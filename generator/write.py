from mapping import get_mapping
from operations import geometric_product, outer_product, inner_product

def write_includes(f_h):
    f_h.write("#include <cmath>\n")
    f_h.write("\n")

def write_struct(G, struct, f_h, f_cpp):
    f_h.write("struct {name} ".format(name=struct.name)+"{\n")

    # Write public members
    for i in range(len(struct.variables)):
        f_h.write("    {} {};\n".format(struct.types[i], struct.variables[i]))

    # operator+=
    f_h.write("    {name}& operator+=(const {name} &other) ".format(name=struct.name)+"{\n")
    for var in struct.basis_to_var.keys():
        f_h.write("        {var} += other.{var};\n".format(var=var))
    f_h.write("        return *this;\n")
    f_h.write("    }\n");

    # operator-=
    f_h.write("    {name}& operator-=(const {name} &other) ".format(name=struct.name)+"{\n")
    for var in struct.basis_to_var.keys():
        f_h.write("        {var} -= other.{var};\n".format(var=var))
    f_h.write("        return *this;\n")
    f_h.write("    }\n");

    # operator*=(scalar)
    f_h.write("    {name}& operator*=(double s) ".format(name=struct.name)+"{\n")
    for var in struct.basis_to_var.keys():
        f_h.write("        {var} *= s;\n".format(var=var))
    f_h.write("        return *this;\n")
    f_h.write("    }\n");

    # operator/=(scalar)
    f_h.write("    {name}& operator/=(double s) ".format(name=struct.name)+"{\n")
    for var in struct.basis_to_var.keys():
        f_h.write("        {var} /= s;\n".format(var=var))
    f_h.write("        return *this;\n")
    f_h.write("    }\n");

    # operator- (negation)
    f_h.write("    {name} operator-()const ".format(name=struct.name)+"{\n")
    f_h.write("        return {"+", ".join(["-"+var for var in struct.basis_to_var.keys()])+"};\n")
    f_h.write("    };\n")

    # End of struct body
    f_h.write("};\n\n");

    # operator+
    f_h.write("inline {name} operator+(const {name} &lhs, const {name} &rhs)".format(name=struct.name)+"{\n")
    f_h.write("    {name} result(lhs);\n".format(name=struct.name))
    f_h.write("    result += rhs;\n")
    f_h.write("    return result;\n")
    f_h.write("}\n")

    # operator-
    f_h.write("inline {name} operator-(const {name} &lhs, const {name} &rhs)".format(name=struct.name)+"{\n")
    f_h.write("    {name} result(lhs);\n".format(name=struct.name))
    f_h.write("    result -= rhs;\n")
    f_h.write("    return result;\n")
    f_h.write("}\n")

    # operator*(scalar)
    f_h.write("inline {name} operator*(const {name} &lhs, double rhs)".format(name=struct.name)+"{\n")
    f_h.write("    {name} result(lhs);\n".format(name=struct.name))
    f_h.write("    result *= rhs;\n")
    f_h.write("    return result;\n")
    f_h.write("}\n")
    f_h.write("inline {name} operator*(double lhs, const {name} &rhs)".format(name=struct.name)+"{\n")
    f_h.write("    return rhs*lhs;\n")
    f_h.write("}\n")

    # operator/(scalar)
    f_h.write("inline {name} operator/(const {name} &lhs, double rhs)".format(name=struct.name)+"{\n")
    f_h.write("    {name} result(lhs);\n".format(name=struct.name))
    f_h.write("    result /= rhs;\n")
    f_h.write("    return result;\n")
    f_h.write("}\n")

    f_h.write("\n\n")

def write_unary_operations(G, struct, f_h, f_cpp):

    # Reverse

    if type(struct.grade) != list:
        # Homogeneous
        num_reverses = sum([i for i in range(1, struct.grade)])
        if num_reverses%2 == 0:
            # Sign doesn't change, can return const ref
            return_type = "const {}&".format(struct.name)
            return_expression = "x"
        else:
            # Need to negate
            return_type = struct.name
            return_expression = "-x"
    else:
        num_reverses = [
            sum([i for i in range(1, grade)]) for grade in struct.grade]
        negations = [
            num%2==1 for num in num_reverses]
        if all([negate==False for negate in negations]):
            return_type = "const {}&".format(struct.name)
            return_expression = "x"
        elif all([negate==True for negate in negations]):
            return_type = struct.name
            return_expression = "-x"
        else:
            return_type = struct.name
            return_expressions = []
            for i, var in enumerate(struct.variables):
                if negations[i]:
                    return_expressions.append("-x.{}".format(var))
                else:
                    return_expressions.append("x.{}".format(var))
            return_expression = "{" + ", ".join(return_expressions) + "}"

    f_h.write("{} reverse(const {} &x) ".format(return_type, struct.name)+"{\n")
    f_h.write("    return {};\n".format(return_expression))
    f_h.write("}\n")

    # Inverse
    # For an orthonormal basis, equal to reverse / norm, with sign dependent on
    # grade and signature
    # But inverse doesn't distribute
    # inverse(a + b) ~= inverse(a) + inverse(b)
    # So this doesn't extend to a non-orthonormal basis
    # Will leave for now, until I need to add in a generic inverse

    f_h.write("double norm2(const {name} &x) ".format(name=struct.name)+"{\n")
    f_h.write("    return inner(x, x);\n")
    f_h.write("}\n")
    f_h.write("double norm(const {name} &x) ".format(name=struct.name)+"{\n")
    f_h.write("    return std::sqrt(inner(x, x));\n")
    f_h.write("}\n")

def _write_product_body(mapping, f_h, f_cpp):
    for ind, elements in mapping.indices.items():
        s = ""
        for element in elements:
            if element.sign==-1:
                s+="-"
            elif len(s)!=0:
                s+="+"

            if len(mapping.op1.blades)==1:
                if mapping.op1.blades[0].grade()==0:
                    op1_s = "lhs"
                else:
                    op1_s = "lhs.data"
            else:
                op1_s = "lhs.data[{}]".format(element.op1_index)

            if len(mapping.op2.blades)==1:
                if mapping.op2.blades[0].grade()==0:
                    op2_s = "rhs"
                else:
                    op2_s = "rhs.data"
            else:
                op2_s = "rhs.data[{}]".format(element.op2_index)

            s+="{}*{}".format(op1_s, op2_s)

        if len(mapping.result.blades)==1:
            if mapping.result.blades[0].grade()==0:
                f_cpp.write("    result = {};\n".format(s))
            else:
                f_cpp.write("    result.data = {};\n".format(s))
        else:
            f_cpp.write("    result.data[{}] = {};\n".format(ind, s))

    f_cpp.write("    return result;\n")
    f_cpp.write("}\n")

def _write_geometric_product(G, obj1, obj2, available, f_h, f_cpp):
    mapping = get_mapping(geometric_product, G, obj1, obj2, available)
    if len(mapping.indices) == 0: return

    prototype = "{result} operator*(const {name} &lhs, const {name} &rhs)".format(
        mapping.result.name, mapping.op1.handle, mapping.op2.handle
    )
    f_h.write(prototype + ";\n")
    f_h.write("\n")

    f_cpp.write(prototype + "\n")
    f_cpp.write("{\n")
    f_cpp.write("    {} result;\n".format(mapping.result.name))

    _write_product_body(mapping, f_h, f_cpp)
    f_cpp.write("\n")

def _write_outer_product(G, obj1, obj2, available, f_h, f_cpp):
    mapping = get_mapping(outer_product, G, obj1, obj2, available)
    if len(mapping.indices) == 0: return

    prototype = "{} outer(const {} &lhs, const {} &rhs)".format(
        mapping.result.name, mapping.op1.handle, mapping.op2.handle
    )
    f_h.write(prototype + ";\n")

    prototype2 = "{} inline operator^(const {} &lhs, const {} &rhs)".format(
        mapping.result.name, mapping.op1.handle, mapping.op2.handle
    )
    f_h.write(prototype2 + " {\n")
    f_h.write("    return outer(lhs, rhs);\n");
    f_h.write("}\n")

    f_cpp.write(prototype + "\n")
    f_cpp.write("{\n")
    f_cpp.write("    {} result;\n".format(mapping.result.name))

    _write_product_body(mapping, f_h, f_cpp)
    f_cpp.write("\n")

def _write_inner_product(G, obj1, obj2, available, f_h, f_cpp):
    mapping = get_mapping(inner_product, G, obj1, obj2, available)
    if len(mapping.indices) == 0: return

    prototype = "{} inner(const {} &lhs, const {} &rhs)".format(
        mapping.result.name, mapping.op1.handle, mapping.op2.handle
    )
    f_h.write(prototype + ";\n")

    f_cpp.write(prototype + "\n")
    f_cpp.write("{\n")
    f_cpp.write("    {} result;\n".format(mapping.result.name))

    _write_product_body(mapping, f_h, f_cpp)
    f_cpp.write("\n")

def write_binary_operations(G, struct1, struct2, structs, f_h, f_cpp):
    _write_geometric_product(G, struct1, struct2, structs, f_h, f_cpp)
    _write_outer_product(G, struct1, struct2, structs, f_h, f_cpp)
    _write_inner_product(G, struct1, struct2, structs, f_h, f_cpp)
    # if obj1!=obj2:
    #     _write_geometric_product(G, obj2, obj1, available, f_h, f_cpp)
    #     _write_outer_product(G, obj2, obj1, available, f_h, f_cpp)
    #     _write_inner_product(G, obj2, obj1, available, f_h, f_cpp)
