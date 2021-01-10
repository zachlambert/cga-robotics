import sympy

def expression_str(expression):
    # Need to manually express it as a string, to handle things low x**2, which
    # aren't valid c++. Also allows for tidying up the output.

    def expression_substr(expression):
        if type(expression) == sympy.core.add.Add:
            return "+".join([expression_str(arg) for arg in expression.args if not arg.equals(0)])
        elif type(expression) == sympy.core.mul.Mul:
            return "*".join([expression_str(arg) for arg in expression.args if not arg.equals(1)])
        elif type(expression) == sympy.core.power.Pow:
            # For small integer powers, expand into a product
            num = expression.args[0]
            exp = expression.args[1]
            if type(exp) == sympy.core.numbers.Integer:
                for i in range(2, 3):
                    if exp.equals(i):
                        return "*".join([expression_str(num) for j in range(i)])
            return "std::pow({},{})".format(num, exp)
        else:
            return str(expression)

    string = expression_substr(expression)

    # Do some extra preprocessing to tidy up

    # Replace +- with -
    i = 1
    while i < len(string):
        if string[i-1]=="+" and string[i]=="-":
            string = string[:i-1] + string[i:]
        else:
            i+=1

    # Remove repeated zeros when they are followed by an operator, meaning that
    # they aren't followed by a . or number, and can be removed
    on_zero = False
    zero_start = 0
    i = 0
    while i <len(string):
        if string[i]=="0" and not on_zero:
            on_zero = True
            zero_start = i
            if i>0 and string[i-1]==".":
                zero_start -= 1 # To include the decimal point
        if string[i]!="0" and string[i] in ['*', '-', '+', '/'] and on_zero:
            on_zero = False
            string = string[:zero_start] + string[i:]
            i -= (i - zero_start)
        else:
            i+=1

    # Replace -1* with -
    i = 0
    while i < len(string)-3:
        if string[i:i+3] == "-1*":
            string = string[:i+1] + string[i+3:]
        i+=1

    return string


def write_expression(struct, struct_name, expression, f, padding="    ", include_zeros=False):
    for var in struct.variables:
        var_expression = var.extract(expression)

        if not include_zeros and var_expression == 0:
            continue

        # Access member variable:
        #   struct_name.var_name = ...
        # Access member variable within member function:
        #   var_name = ...
        #   (struct_name = "")
        # Struct itself is the variable (only for scalar struct):
        #   struct_name = ...
        name = struct_name
        if struct_name!="" and var.name!="":
            name += "."
        name += var.name

        f.write(padding+"{name} = {expression};\n".format(
            name=name, expression=expression_str(var_expression)))

def write_includes(f_h, f_cpp):
    f_h.write("#include <cmath>\n")
    f_h.write("#include <iostream>\n")
    f_h.write("\n")
    f_cpp.write("#include \"gen/cga.h\"\n")
    f_cpp.write("\n")

def write_struct(struct, f_h, f_cpp):
    f_h.write("struct {name} ".format(name=struct.name)+"{\n")

    # Write public members
    for member in struct.members:
        f_h.write("    {} {};\n".format(member.type, member.name))
    f_h.write("\n")

    # Constructors

    params = []
    default_init_list = []
    member_init_list = []
    for member in struct.members:
        if member.struct is None:
            params.append("double "+member.name)
            default_init_list.append("{}(0)".format(member.name))
        else:
            params.append("const {} &{}".format(member.struct.name, member.name))
            default_init_list.append("{}()".format(member.name))
        member_init_list.append("{name}({name})".format(name=member.name))

    # Default constructor
    f_h.write("    {name}(): {init_list}".format(
        name=struct.name, params=", ".join(params), init_list=", ".join(default_init_list)))
    f_h.write(" {}\n")

    # Construct from members
    f_h.write("    {name}({params}): {init_list}".format(
        name=struct.name, params=", ".join(params), init_list=", ".join(member_init_list)))
    f_h.write(" {}\n")

    # Create a constructor for each non-scalar member
    for i, member in enumerate(struct.members):
        if member.struct is None: continue
        init_list = [member_init_list[j] if j==i else default_init_list[j] for j in range(len(struct.members))]
        f_h.write("    {name}({param}): {init_list}".format(
            name=struct.name, param=params[i], init_list=", ".join(init_list)))
        f_h.write(" {}\n")

    # Extra constructors
    for other in struct.extra_constructors:
        explicit_kw = "" if struct.can_fit(other.blades) else "explicit "
        f_h.write("    {explicit_kw}{name}(const {other}& other);\n".format(
            explicit_kw=explicit_kw, name=struct.name, other=other.name))
        f_cpp.write("{name}::{name}(const {other}& other)\n".format(
            explicit_kw=explicit_kw, name=struct.name, other=other.name))
        f_cpp.write("{\n")
        write_expression(struct, "", other.expression("other"), f_cpp, include_zeros=True)
        f_cpp.write("}\n")
        f_cpp.write("\n")

    # operator+=
    f_h.write("    {name}& operator+=(const {name} &other) ".format(name=struct.name)+"{\n")
    for member in struct.members:
        f_h.write("        {member} += other.{member};\n".format(member=member.name))
    f_h.write("        return *this;\n")
    f_h.write("    }\n");

    # operator-=
    f_h.write("    {name}& operator-=(const {name} &other) ".format(name=struct.name)+"{\n")
    for member in struct.members:
        f_h.write("        {member} -= other.{member};\n".format(member=member.name))
    f_h.write("        return *this;\n")
    f_h.write("    }\n");

    # operator*=(scalar)
    f_h.write("    {name}& operator*=(double s) ".format(name=struct.name)+"{\n")
    for member in struct.members:
        f_h.write("        {member} *= s;\n".format(member=member.name))
    f_h.write("        return *this;\n")
    f_h.write("    }\n");

    # operator/=(scalar)
    f_h.write("    {name}& operator/=(double s) ".format(name=struct.name)+"{\n")
    for member in struct.members:
        f_h.write("        {member} /= s;\n".format(member=member.name))
    f_h.write("        return *this;\n")
    f_h.write("    }\n");

    # operator- (negation)
    f_h.write("    {name} operator-()const ".format(name=struct.name)+"{\n")
    f_h.write("        return {"+", ".join(["-"+member.name for member in struct.members])+"};\n")
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

def write_printing(struct, f_h, f_cpp):
    f_h.write("std::ostream& operator<<(std::ostream& outs, const {name} &x);\n".format(name=struct.name))
    f_cpp.write("std::ostream& operator<<(std::ostream& outs, const {name} &x) ".format(name=struct.name)+"{\n")
    elements = []
    line_start = True
    for i, member in enumerate(struct.members):
        if i!=0 and member.struct is not None:
            elements.append("std::endl")
            line_start = True
        if line_start:
            elements.append("\"{}: \"<<x.".format(member.name)+member.name)
            line_start = False
        else:
            elements.append("\", {}: \"<<x.".format(member.name)+member.name)
    f_cpp.write("    outs<<{};\n".format("<<".join(elements)))
    f_cpp.write("    return outs;\n")
    f_cpp.write("}\n\n")
