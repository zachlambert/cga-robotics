from structs import make_structs, extract_blades

"""
An operation must define:
- The number of structs
- The expression to compute from these structs
- The prototype structure, argument names
- Any equivalent versions of the function (such as swapping arguments)

Easiest to just create a different class for each operation, so long as they
have a common interface. (Don't need to use inheritance)

Assume operands are provided as the sympy/geometric algebra expression,
generated by struct.expression()
"""

def find_return_struct(expression, available):
    # Assume available are sorted from most to least specific
    # Iterate through until a suitable struct is found
    blades = extract_blades(expression)
    for struct in available:
        if struct.can_fit(blades):
            return struct
    return None

class GeometricProduct:
    def write_individual(self, op1, op2, available, f_h, f_cpp):
        expression = (op1.expression("lhs") * op2.expression("rhs")).expand()
        ret = find_return_struct(expression, available)
        if ret is None:
            print("No return struct for {} * {}".format(op1.name, op2.name))
            return

        prototype = "{ret} operator*(const {op1} &lhs, const {op2} &rhs)".format(
            ret=ret.name, op1=op1.name, op2=op2.name)

        f_h.write(prototype+";\n")
        f_cpp.write(prototype+" {\n")
        f_cpp.write("    {} result;\n".format(ret.name))

        for var in ret.variables:
            var_expression = ret.extract(expression, var)
            if var_expression != 0:
                var_name = "result"
                if var.name != "":
                    var_name += "." + var.name
                f_cpp.write("    {name} = {expression};\n".format(
                    name=var_name, expression=var_expression))

        f_cpp.write("    return result;\n")
        f_cpp.write("}\n")

        if op1.name != op2.name:
            f_h.write("{ret} operator*(const {op2} &lhs, const {op1} &rhs)".format(
                ret=ret.name, op1=op1.name, op2=op2.name) + " {\n")
            f_h.write("    return rhs*lhs;\n")
            f_h.write("}\n")

    def write(self, structs, available, f_h, f_cpp):
        print("WRITING GEOMETRIC PRODUCT")
        for i in range(len(structs)):
            print("({}/{}) op1 = {}".format(i+1, len(structs), structs[i].name))
            for j in range(i, len(structs)):
                print("  ({}/{}) op2 = {}".format(j+1-i, len(structs)-i, structs[j].name))
                self.write_individual(structs[i], structs[j], available, f_h, f_cpp)

class OuterProduct:
    def write_individual(self, op1, op2, available, f_h, f_cpp):
        expression = (op1.expression("lhs") ^ op2.expression("rhs")).expand()
        ret = find_return_struct(expression, available)
        if ret is None:
            print("No return struct for {} ^ {}".format(op1.name, op2.name))
            return

        prototype = "{ret} outer(const {op1} &lhs, const {op2} &rhs)".format(
            ret=ret.name, op1=op1.name, op2=op2.name)

        f_h.write(prototype+";\n")
        f_cpp.write(prototype+" {\n")
        f_cpp.write("    {} result;\n".format(ret.name))

        for var in ret.variables:
            var_expression = ret.extract(expression, var)
            if var_expression != 0:
                var_name = "result"
                if var.name != "":
                    var_name += "." + var.name
                f_cpp.write("    {name} = {expression};\n".format(
                    name=var_name, expression=var_expression))

        f_cpp.write("    return result;\n")
        f_cpp.write("}\n")

        if op1.name != op2.name:
            f_h.write("{ret} outer(const {op2} &lhs, const {op1} &rhs)".format(
                ret=ret.name, op1=op1.name, op2=op2.name) + " {\n")
            f_h.write("    return outer(rhs, lhs);\n")
            f_h.write("}\n")

    def write(self, structs, available, f_h, f_cpp):
        print("WRITING OUTER PRODUCT")
        for i in range(len(structs)):
            print("({}/{}) op1 = {}".format(i+1, len(structs), structs[i].name))
            for j in range(i, len(structs)):
                print("  ({}/{}) op2 = {}".format(j+1-i, len(structs)-i, structs[j].name))
                self.write_individual(structs[i], structs[j], available, f_h, f_cpp)

class InnerProduct:
    def write_individual(self, op1, op2, available, f_h, f_cpp):
        expression = (op1.expression("lhs") | op2.expression("rhs")).expand()
        ret = find_return_struct(expression, available)
        if ret is None:
            print("No return struct for {} | {}".format(op1.name, op2.name))
            return

        prototype = "{ret} inner(const {op1} &lhs, const {op2} &rhs)".format(
            ret=ret.name, op1=op1.name, op2=op2.name)

        f_h.write(prototype+";\n")
        f_cpp.write(prototype+" {\n")
        f_cpp.write("    {} result;\n".format(ret.name))

        for var in ret.variables:
            var_expression = ret.extract(expression, var)
            if var_expression != 0:
                var_name = "result"
                if var.name != "":
                    var_name += "." + var.name
                f_cpp.write("    {name} = {expression};\n".format(
                    name=var_name, expression=var_expression))

        f_cpp.write("    return result;\n")
        f_cpp.write("}\n")

        if op1.name != op2.name:
            f_h.write("{ret} inner(const {op2} &lhs, const {op1} &rhs)".format(
                ret=ret.name, op1=op1.name, op2=op2.name) + " {\n")
            f_h.write("    return inner(rhs, lhs);\n")
            f_h.write("}\n")

    def write(self, structs, available, f_h, f_cpp):
        print("WRITING INNER PRODUCT")
        for i in range(len(structs)):
            print("({}/{}) op1 = {}".format(i+1, len(structs), structs[i].name))
            for j in range(i, len(structs)):
                print("  ({}/{}) op2 = {}".format(j+1-i, len(structs)-i, structs[j].name))
                self.write_individual(structs[i], structs[j], available, f_h, f_cpp)

class Reverse:
    def write_individual(self, op, f_h, f_cpp):
        original = op.expression("x")
        expression = (original.rev()).expand()

        if expression == original:
            f_h.write("inline const {op}& reverse(const {op} &x)".format(op=op.name))
            f_h.write(" { return x; }\n")
            return

        if expression == -original:
            f_h.write("inline {op} reverse(const {op} &x)".format(op=op.name))
            f_h.write(" { return -x; }\n")
            return

        prototype = "{op} reverse(const {op} &x)".format(op=op.name)
        f_h.write(prototype+";\n")
        f_cpp.write(prototype+" {\n")
        f_cpp.write("    {op} result;\n".format(op=op.name))

        for var in op.variables:
            var_expression = op.extract(expression, var)
            if var_expression != 0:
                var_name = "result"
                if var.name != "":
                    var_name += "." + var.name
                f_cpp.write("    {name} = {expression};\n".format(
                    name=var_name, expression=var_expression))

        f_cpp.write("    return result;\n")
        f_cpp.write("}\n")

    def write(self, structs, available, f_h, f_cpp):
        print("WRITING REVERSE")
        for i in range(len(structs)):
            print("({}/{}) op = {}".format(i+1, len(structs), structs[i].name))
            self.write_individual(structs[i], f_h, f_cpp)

def get_operations():
    return [OuterProduct(), InnerProduct(), Reverse()]

if __name__ == "__main__":
    structs, available = make_structs()
    struct1 = structs[5]
    struct2 = structs[11]
    expression = struct1.expression("lhs") * struct2.expression("rhs")

    temp = expression
    for var in struct2.variables:
        # Remove component of expression in that variable
        temp -= struct2.extract(expression, var) * var.expression
    print(temp)
    print(temp.obj.equals(0))
