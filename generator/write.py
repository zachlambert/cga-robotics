from mapping import get_mapping
# from operations import geometric_product, outer_product, inner_product

def write_includes(f_h, f_cpp):
    f_h.write("#include <cmath>\n")
    f_h.write("#include <iostream>\n")
    f_h.write("\n")
    f_cpp.write("#include \"cga.h\"\n")
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
    f_h.write("std::ostream& operator<<(std::ostream& outs, const {name} &x);\n\n".format(name=struct.name))
    f_cpp.write("std::ostream& operator<<(std::ostream& outs, const {name} &x) ".format(name=struct.name)+"{\n")
    elements = []
    for i, member in enumerate(struct.members):
        elements.append("\"{}: \"<<x.".format(member.name)+member.name)
        if member.struct is not None and i != len(struct.members)-1:
            elements.append("std::endl")
    f_cpp.write("    outs<<{};\n".format("<<".join(elements)))
    f_cpp.write("    return outs;\n")
    f_cpp.write("}\n\n")
