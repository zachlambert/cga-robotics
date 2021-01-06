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

def _write_product_body(lhs_struct, rhs_struct, results, f_cpp):

    # First, convert expressions to be in terms of argument variables
    temp_results = {}
    for blade, expression in results.items():
        new_expression = []
        for term in expression:
            new_expression.append(term)
        temp_results[blade] = new_expression

    # Second, convert key of results to be in terms of result variables
    new_results = {}
    for blade, expression in temp_results.items():
        pass

    for var, expression in new_results.items():
        f_cpp.write(
            "    result.{var} = {expression}".format(
                var=var,
                expression = "+".join([
                    str(term[0]) # Coefficient
                    +"*lhs."+term[1] # lhs member
                    +"*rhs."+term[2] # rhs member
                    for term in expression])
            )
        )

def _write_geometric_product(G, struct1, struct2, structs, f_h, f_cpp):
    results, return_struct = get_mapping(geometric_product, G, struct1, struct2, structs)
    if return_struct is None: return

    prototype = "{ret} operator*(const {lhs} &lhs, const {rhs} &rhs)".format(
        ret=return_struct.name, lhs=struct1.name, rhs=struct2.name)
    f_h.write(prototype + ";\n")
    f_h.write("\n")

    if struct1.name != struct2.name:
        f_h.write("{ret} operator*(const {lhs} &lhs, const {rhs} &rhs)\n".format(
            ret=return_struct.name, lhs=struct2.name, rhs=struct1.name))
        f_h.write("{\n")
        f_h.write("    return rhs*lhs;\n")
        f_h.write("}\n")
        f_h.write("\n")

    f_cpp.write(prototype + "\n")
    f_cpp.write("{\n")
    f_cpp.write("    {} result;\n".format(return_struct.name))
    _write_product_body(struct1, struct2, results, f_cpp)
    f_cpp.write("    return result;\n")
    f_cpp.write("}\n")
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
    # _write_outer_product(G, struct1, struct2, structs, f_h, f_cpp)
    # _write_inner_product(G, struct1, struct2, structs, f_h, f_cpp)
    # if obj1!=obj2:
    #     _write_geometric_product(G, obj2, obj1, available, f_h, f_cpp)
    #     _write_outer_product(G, obj2, obj1, available, f_h, f_cpp)
    #     _write_inner_product(G, obj2, obj1, available, f_h, f_cpp)
