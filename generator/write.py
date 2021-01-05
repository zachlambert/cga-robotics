from mapping import get_mapping
from operations import geometric_product, outer_product, inner_product

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

    prototype = "{} operator*(const {} &lhs, const {} &rhs)".format(
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

def write_products(G, obj1, obj2, available, f_h, f_cpp):
    _write_geometric_product(G, obj1, obj2, available, f_h, f_cpp)
    _write_outer_product(G, obj1, obj2, available, f_h, f_cpp)
    _write_inner_product(G, obj1, obj2, available, f_h, f_cpp)
    if obj1!=obj2:
        _write_geometric_product(G, obj2, obj1, available, f_h, f_cpp)
        _write_outer_product(G, obj2, obj1, available, f_h, f_cpp)
        _write_inner_product(G, obj2, obj1, available, f_h, f_cpp)
