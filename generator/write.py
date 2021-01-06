from mapping import get_mapping
from operations import geometric_product, outer_product, inner_product

def write_includes(f_h, f_cpp):
    f_h.write("#include <cmath>\n")
    f_h.write("#include <iostream>\n")
    f_h.write("\n")
    f_cpp.write("#include \"cga.h\"\n")
    f_cpp.write("\n")

def write_struct(G, struct, f_h, f_cpp):
    f_h.write("struct {name} ".format(name=struct.name)+"{\n")

    # Write public members
    for member in struct.members:
        f_h.write("    {};\n".format(member))

    # operator+=
    f_h.write("    {name}& operator+=(const {name} &other) ".format(name=struct.name)+"{\n")
    for var in struct.variables:
        f_h.write("        {var} += other.{var};\n".format(var=var))
    f_h.write("        return *this;\n")
    f_h.write("    }\n");

    # operator-=
    f_h.write("    {name}& operator-=(const {name} &other) ".format(name=struct.name)+"{\n")
    for var in struct.variables:
        f_h.write("        {var} -= other.{var};\n".format(var=var))
    f_h.write("        return *this;\n")
    f_h.write("    }\n");

    # operator*=(scalar)
    f_h.write("    {name}& operator*=(double s) ".format(name=struct.name)+"{\n")
    for var in struct.variables:
        f_h.write("        {var} *= s;\n".format(var=var))
    f_h.write("        return *this;\n")
    f_h.write("    }\n");

    # operator/=(scalar)
    f_h.write("    {name}& operator/=(double s) ".format(name=struct.name)+"{\n")
    for var in struct.variables:
        f_h.write("        {var} /= s;\n".format(var=var))
    f_h.write("        return *this;\n")
    f_h.write("    }\n");

    # operator- (negation)
    f_h.write("    {name} operator-()const ".format(name=struct.name)+"{\n")
    f_h.write("        return {"+", ".join(["-"+var for var in struct.variables])+"};\n")
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

    grades = [G.blade_grade(blade) for blade in struct.blades]

    homogeneous = True
    for i in range(1, len(grades)):
        if grades[i] != grades[0]:
            homogeneous = False
            break

    if homogeneous: 
        grade = grades[0]
        num_reverses = sum([i for i in range(1, grade)])
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
            sum([i for i in range(1, grade)]) for grade in grades]
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

    f_h.write("inline {} reverse(const {} &x) ".format(return_type, struct.name)+"{\n")
    f_h.write("    return {};\n".format(return_expression))
    f_h.write("}\n")

    # Inverse
    # For an orthonormal basis, equal to reverse / norm, with sign dependent on
    # grade and signature
    # But inverse doesn't distribute
    # inverse(a + b) ~= inverse(a) + inverse(b)
    # So this doesn't extend to a non-orthonormal basis
    # Will leave for now, until I need to add in a generic inverse

    # Norm and norm2
    # Only do this for homogeneous multivectors, where dot(x, x) is a scalar

    if homogeneous:
        f_h.write("inline double norm2(const {name} &x) ".format(name=struct.name)+"{\n")
        f_h.write("    return inner(x, x);\n")
        f_h.write("}\n")
        f_h.write("inline double norm(const {name} &x) ".format(name=struct.name)+"{\n")
        f_h.write("    return std::sqrt(inner(x, x));\n")
        f_h.write("}\n")


def _write_product_body(lhs_struct, rhs_struct, return_struct, results, f_cpp):
    # First, convert expressions to be in terms of argument variables
    temp_results = {}
    for blade, expression in results.items():
        new_expression = {}
        for term in expression:
            # Expression = coef * lhs blade * rhs blade
            for lhs_term in lhs_struct.blade_expressions[term[1]]:
                for rhs_term in rhs_struct.blade_expressions[term[2]]:
                    # lhs_term = (lhs_coef, lhs_blade)
                    # rhs_term = (rhs_coef, rhs_blade)
                    # Add (lhs_blade, rhs_blade): lhs_coef*rhs_coef
                    key = (lhs_term[1], rhs_term[1])
                    if key not in new_expression:
                        new_expression[key] = 0
                    new_expression[key] += term[0] * lhs_term[0] * rhs_term[0]

        # Keep new_expression in dictionary format
        temp_results[blade] = new_expression

    # Second, convert key of results to be in terms of result variables
    new_results = {}
    for var in return_struct.variables:
        var_expression = return_struct.var_expressions[var]
        # var_expression is a list with elements of the form:
        # (coef, blade)
        # Iterate through the var_expression, and copy the corresponding blade
        # expression from temp_results, multiplied by the coefficient
        expression = {}
        for coef, blade in var_expression:
            # First, check that the results actually include this blade
            if blade not in temp_results:
                continue
            # expression += coef * temp_results[blade]
            for pair, pair_coef in temp_results[blade].items():
                if not pair in expression:
                    expression[pair] = 0
                expression[pair] += coef * pair_coef
        new_results[var] = expression

    # new_results is now a dictionary of the form:
    #   variable: expression
    # where expression is a dictionary of the form:
    #   (lhs var, rhs var): coefficient

    for var, expression in new_results.items():
        expression_str = ""
        for pair, coefficient in expression.items():
            if coefficient == 1:
                if expression_str!="":
                    expression_str += "+"
            elif coefficient == -1:
                expression_str += "-"
            elif coefficient != 0:
                if coefficient > 0 and expression_str!="":
                    expression_str += "+"
                expression_str += str(coefficient)+"*"

            if coefficient != 0:
                expression_str += "lhs.{}*rhs.{}".format(pair[0], pair[1])

        if expression_str != "":
            if var=="":
                f_cpp.write("    result = {expression};\n".format(
                    expression=expression_str))
            else:
                f_cpp.write("    result.{var} = {expression};\n".format(
                    var=var, expression=expression_str))

def _write_geometric_product(G, struct1, struct2, structs, f_h, f_cpp):
    results, return_struct = get_mapping(geometric_product, G, struct1, struct2, structs)
    if return_struct is None: return

    prototype = "{ret} operator*(const {lhs} &lhs, const {rhs} &rhs)".format(
        ret=return_struct.name, lhs=struct1.name, rhs=struct2.name)
    f_h.write(prototype + ";\n")
    f_h.write("\n")

    if struct1.name != struct2.name:
        f_h.write("inline {ret} operator*(const {lhs} &lhs, const {rhs} &rhs)\n".format(
            ret=return_struct.name, lhs=struct2.name, rhs=struct1.name))
        f_h.write("{\n")
        f_h.write("    return rhs*lhs;\n")
        f_h.write("}\n")
        f_h.write("\n")

    f_cpp.write(prototype + "\n")
    f_cpp.write("{\n")
    f_cpp.write("    {} result;\n".format(return_struct.name))
    _write_product_body(struct1, struct2, return_struct, results, f_cpp)
    f_cpp.write("    return result;\n")
    f_cpp.write("}\n")
    f_cpp.write("\n")

def _write_outer_product(G, struct1, struct2, structs, f_h, f_cpp):
    results, return_struct = get_mapping(outer_product, G, struct1, struct2, structs)
    if return_struct is None: return

    prototype = "{ret} outer(const {lhs} &lhs, const {rhs} &rhs)".format(
        ret=return_struct.name, lhs=struct1.name, rhs=struct2.name)
    f_h.write(prototype + ";\n")
    f_h.write("\n")

    if struct1.name != struct2.name:
        f_h.write("inline {ret} outer(const {lhs} &lhs, const {rhs} &rhs)\n".format(
            ret=return_struct.name, lhs=struct2.name, rhs=struct1.name))
        f_h.write("{\n")
        f_h.write("    return outer(rhs, lhs);\n")
        f_h.write("}\n")
        f_h.write("\n")

    f_cpp.write(prototype + "\n")
    f_cpp.write("{\n")
    f_cpp.write("    {} result;\n".format(return_struct.name))
    _write_product_body(struct1, struct2, return_struct, results, f_cpp)
    f_cpp.write("    return result;\n")
    f_cpp.write("}\n")
    f_cpp.write("\n")

def _write_inner_product(G, struct1, struct2, structs, f_h, f_cpp):
    results, return_struct = get_mapping(inner_product, G, struct1, struct2, structs)
    if return_struct is None: return

    prototype = "{ret} inner(const {lhs} &lhs, const {rhs} &rhs)".format(
        ret=return_struct.name, lhs=struct1.name, rhs=struct2.name)
    f_h.write(prototype + ";\n")
    f_h.write("\n")

    if struct1.name != struct2.name:
        f_h.write("inline {ret} inner(const {lhs} &lhs, const {rhs} &rhs)\n".format(
            ret=return_struct.name, lhs=struct2.name, rhs=struct1.name))
        f_h.write("{\n")
        f_h.write("    return inner(rhs, lhs);\n")
        f_h.write("}\n")
        f_h.write("\n")

    f_cpp.write(prototype + "\n")
    f_cpp.write("{\n")
    f_cpp.write("    {} result;\n".format(return_struct.name))
    _write_product_body(struct1, struct2, return_struct, results, f_cpp)
    f_cpp.write("    return result;\n")
    f_cpp.write("}\n")
    f_cpp.write("\n")

def write_binary_operations(G, struct1, struct2, structs, f_h, f_cpp):
    _write_geometric_product(G, struct1, struct2, structs, f_h, f_cpp)
    _write_outer_product(G, struct1, struct2, structs, f_h, f_cpp)
    _write_inner_product(G, struct1, struct2, structs, f_h, f_cpp)

def write_printing(struct, f_h, f_cpp):
    f_h.write("std::ostream& operator<<(std::ostream& outs, const {name} &x);\n\n".format(name=struct.name))
    f_cpp.write("std::ostream& operator<<(std::ostream& outs, const {name} &x) ".format(name=struct.name)+"{\n")
    elements = []
    for var in struct.variables:
        elements.append("\"{}=\"<<x.{}<<\" \"".format(var, var))
        if var in struct.print_newlines:
            elements.append("std::endl")
    f_cpp.write("    outs << {};\n".format("<<".join(elements)))
    f_cpp.write("    return outs;\n")
    f_cpp.write("}\n\n")
