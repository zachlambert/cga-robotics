# First, generate blades

from algebra import Algebra
from write import write_includes, write_struct, write_unary_operations, write_binary_operations, write_printing

class Struct:
    def __init__(self, name, blades, variables, members):
        self.name = name
        self.blades = blades
        self.variables = variables # e1, e2, e12, b.e12, etc
        self.members = members # double e1, double e2, Bivector b, etc
        self.var_expressions = {}
        self.blade_expressions = {}
        self.print_newlines = []
        self.constructors = []
        # var_expressions defines expressions for each variable in terms of basis blades
        # blade_expressions defines expressions for each basis blade in terms of variables
        # Each has the form:
        # y: [(a1, "x1"), (a2, "x2"), ...]
        # Which means:
        # y = a1*x1 + a2*x2
        # Wherea a1, a2 are coefficients, x1, x2 are variable names

    def set_var_expression(self, var, expression):
        self.var_expressions[var] = expression

    def set_blade_expression(self, blade, expression):
        self.blade_expressions[blade] = expression

    def set_equal(self, var, blade):
        self.set_var_expression(var, [(1, blade)])
        self.set_blade_expression(blade, [(1, var)])

    def set_opposite(self, var, blade):
        self.set_var_expression(var, [(-1, blade)])
        self.set_blade_expression(blade, [(-1, var)])

    def copy(self, prefix, struct):
        # Variable names add "prefix". May be empry.
        for var, expression in struct.var_expressions.items():
            self.var_expressions[prefix+var] = expression
        for blade, expression in struct.blade_expressions.items():
            self.blade_expressions[blade] = [(term[0], prefix+term[1]) for term in expression]

    def set_print_newlines(self, *var_list):
        self.print_newlines = var_list

    def add_constructor(self, params, init_list, explicit=False):
        self.constructors.append((params, init_list, explicit))

def make_structs(G):

    structs = []

    # VECTOR3

    Vector3 = Struct(
        "Vector3",
        ["e1", "e2", "e3"],
        ["e1", "e2", "e3"],
        ["double e1", "double e2", "double e3"],
    )
    Vector3.set_equal("e1", "e1")
    Vector3.set_equal("e2", "e2")
    Vector3.set_equal("e3", "e3")

    structs.append(Vector3)


    # VECTOR

    Vector = Struct(
        "Vector",
        G.grade(1),
        ["e1", "e2", "e3", "eo", "ei"],
        ["double e1", "double e2", "double e3", "double eo", "double ei"]
    )
    Vector.set_print_newlines("e3")

    Vector.set_equal("e1", "e1")
    Vector.set_equal("e2", "e2")
    Vector.set_equal("e3", "e3")

    Vector.set_var_expression("eo", [(0.5, "e4"), (-0.5, "e5")])
    Vector.set_var_expression("ei", [(-1, "e4"), (1, "e5")])
    Vector.set_blade_expression("e4", [(1, "eo"), (-0.5, "ei")])
    Vector.set_blade_expression("e5", [(1, "eo"), (0.5, "ei")])

    Vector.add_constructor("", "e1(0), e2(0), e3(0), eo(0), ei(0)")
    Vector.add_constructor("double e1, double e2, double e3, double eo, double ei", "e1(e1), e2(e2), e3(e3), eo(eo), ei(ei)")
    Vector.add_constructor("const Vector3 &v", "e1(v.e1), e2(v.e2), e3(v.e3), eo(0), ei(0)")
    Vector.add_constructor("const Multivector &mv", "e1(mv.v.e1), e2(mv.v.e2), e3(mv.v.e3), eo(mv.v.eo), ei(mv.v.ei)", True)

    structs.append(Vector)


    # BIVECTOR

    Bivector = Struct(
        "Bivector",
        G.grade(2),
        ["e23", "e31", "e12", "e1o", "e2o", "e3o", "e1i", "e2i", "e3i", "eoi"],
        ["double e23", "double e31", "double e12",
         "double e1o", "double e2o", "double e3o",
         "double e1i", "double e2i", "double e3i",
         "double eoi"]
    )
    Bivector.set_print_newlines("e12", "e3o", "e3i");

    Bivector.set_equal("e23", "e23")
    Bivector.set_opposite("e31", "e13")
    Bivector.set_equal("e12", "e12")

    Bivector.set_var_expression("e1o", [(0.5, "e14"), (0.5, "e15")])
    Bivector.set_var_expression("e2o", [(0.5, "e24"), (0.5, "e25")])
    Bivector.set_var_expression("e3o", [(0.5, "e34"), (0.5, "e35")])
    Bivector.set_var_expression("e1i", [(-1, "e14"), (1, "e15")])
    Bivector.set_var_expression("e2i", [(-1, "e24"), (1, "e25")])
    Bivector.set_var_expression("e3i", [(-1, "e34"), (1, "e35")])

    Bivector.set_blade_expression("e14", [(1, "e1o"), (-0.5, "e1i")])
    Bivector.set_blade_expression("e15", [(1, "e1o"), (0.5, "e1i")])
    Bivector.set_blade_expression("e24", [(1, "e2o"), (-0.5, "e2i")])
    Bivector.set_blade_expression("e25", [(1, "e2o"), (0.5, "e2i")])
    Bivector.set_blade_expression("e34", [(1, "e3o"), (-0.5, "e3i")])
    Bivector.set_blade_expression("e35", [(1, "e3o"), (0.5, "e3i")])

    Bivector.set_equal("eoi", "e45")

    structs.append(Bivector)


    # TRIVECTOR

    Trivector = Struct(
        "Trivector",
        G.grade(3),
        ["e123", "e23o", "e31o", "e12o", "e23i", "e31i", "e12i", "e1oi", "e2oi", "e3oi"],
        ["double e123",
         "double e23o", "double e31o", "double e12o",
         "double e23i", "double e31i", "double e12i",
         "double e1oi", "double e2oi", "double e3oi"],
    )
    Trivector.set_print_newlines("e123", "e12o", "e12i")

    Trivector.set_equal("e123", "e123")

    Trivector.set_var_expression("e23o", [(0.5, "e234"), (0.5, "e235")])
    Trivector.set_var_expression("e31o", [(-0.5, "e134"), (-0.5, "e135")])
    Trivector.set_var_expression("e12o", [(0.5, "e124"), (0.5, "e125")])

    Trivector.set_var_expression("e23i", [(-1, "e234"), (1, "e235")])
    Trivector.set_var_expression("e31i", [(1, "e134"), (-1, "e135")])
    Trivector.set_var_expression("e12i", [(-1, "e124"), (1, "e125")])

    Trivector.set_blade_expression("e234", [(1, "e23o"), (-0.5, "e23i")])
    Trivector.set_blade_expression("e235", [(1, "e23o"), (0.5, "e23i")])
    Trivector.set_blade_expression("e134", [(-1, "e31o"), (0.5, "e31i")])
    Trivector.set_blade_expression("e135", [(-1, "e31o"), (-0.5, "e31i")])
    Trivector.set_blade_expression("e124", [(1, "e12o"), (-0.5, "e12i")])
    Trivector.set_blade_expression("e125", [(1, "e12o"), (0.5, "e12i")])

    Trivector.set_equal("e1oi", "e145")
    Trivector.set_equal("e2oi", "e245")
    Trivector.set_equal("e3oi", "e345")

    structs.append(Trivector)


    # QUADVECTOR

    Quadvector = Struct(
        "Quadvector",
        G.grade(4),
        ["e123o", "e123i", "e23oi", "e31oi", "e12oi"],
        ["double e123o", "double e123i", "double e23oi", "double e31oi", "double e12oi"],
    )
    Quadvector.set_print_newlines("e123i")

    Quadvector.set_var_expression("e123o", [(0.5, "e1234"), (0.5, "e1235")])
    Quadvector.set_var_expression("e123i", [(-1, "e1234"), (1, "e1235")])

    Quadvector.set_blade_expression("e1234", [(1, "e123o"), (-0.5, "e123i")])
    Quadvector.set_blade_expression("e1235", [(1, "e123o"), (0.5, "e123i")])

    Quadvector.set_equal("e23oi", "e2345")
    Quadvector.set_opposite("e31oi", "e1345")
    Quadvector.set_equal("e12oi", "e1245")

    structs.append(Quadvector)

    # PSEUDOSCALAR

    Pseudoscalar = Struct(
        "Pseudoscalar",
        G.grade(5),
        ["p"],
        ["double p"]
    )
    Pseudoscalar.set_equal("p", "e12345")

    structs.append(Pseudoscalar)


    # PSEUDOSCALAR3

    Pseudoscalar3 = Struct(
        "Pseudoscalar3",
        ["e123"],
        ["p"],
        ["double p"]
    )
    Pseudoscalar3.set_equal("p", "e123")

    structs.append(Pseudoscalar3)


    # BIVECTOR3

    Bivector3 = Struct(
        "Bivector3",
        ["e12", "e13", "e23"],
        ["e23", "e31", "e12"],
        ["double e23", "double e31", "double e12"]
    )
    Bivector3.set_equal("e23", "e23")
    Bivector3.set_opposite("e31", "e13")
    Bivector3.set_equal("e12", "e12")

    structs.append(Bivector3)


    # ROTOR3

    Rotor3 = Struct(
        "Rotor3",
        ["1", "e12", "e13", "e23"],
        ["s", "b.e23", "b.e31", "b.e12"],
        ["double s", "Bivector3 b"]
    )
    Rotor3.set_equal("s", "1")
    Rotor3.copy("b.", Bivector3)

    structs.append(Rotor3)


    # ROTOR

    Rotor = Struct(
        "Rotor",
        G.grade(0) + G.grade(2),
        ["s",
         "b.e23", "b.e31", "b.e12",
         "b.e1o", "b.e2o", "b.e3o",
         "b.e1i", "b.e2i", "b.e3i",
         "b.eoi"],
        ["double s", "Bivector b"]
    )
    Rotor.set_equal("s", "1");
    Rotor.copy("b.", Bivector)
    Rotor.set_print_newlines("s", "b.e12", "b.e3o", "b.e3i")

    structs.append(Rotor)


    # VERSOR

    Versor = Struct(
        "Versor",
        G.grade(0) + G.grade(2) + G.grade(4),
        ["s",
         "b.e23", "b.e31", "b.e12",
         "b.e1o", "b.e2o", "b.e3o",
         "b.e1i", "b.e2i", "b.e3i",
         "b.eoi",
         "q.e123o", "q.e123i", "q.e23oi", "q.e31oi", "q.e12oi"],
        ["double s", "Bivector b", "Quadvector q"]
    )
    Versor.set_equal("s", "1");
    Versor.copy("b.", Bivector)
    Versor.copy("q.", Quadvector)
    Versor.set_print_newlines("s", "b.e12", "b.e3o", "b.e3i", "b.eoi", "q.e123i")

    structs.append(Versor)


    # MULTIVECTOR

    Multivector = Struct(
        "Multivector",
        G.blades,
        ["s",
         "v.e1", "v.e2", "v.e3", "v.eo", "v.ei",
         "b.e23", "b.e31", "b.e12",
         "b.e1o", "b.e2o", "b.e3o",
         "b.e1i", "b.e2i", "b.e3i",
         "b.eoi",
         "t.e123", "t.e23o", "t.e31o", "t.e12o", "t.e23i", "t.e31i", "t.e12i",
         "t.e1oi", "t.e2oi", "t.e3oi",
         "q.e123o", "q.e123i", "q.e23oi", "q.e31oi", "q.e12oi",
         "p"],
        ["double s", "Vector v", "Bivector b", "Trivector t", "Quadvector q", "double p"]
    )
    Multivector.set_equal("s", "1");
    Multivector.copy("v.", Vector)
    Multivector.copy("b.", Bivector)
    Multivector.copy("t.", Trivector)
    Multivector.copy("q.", Quadvector)
    Multivector.set_equal("p", "e12345")
    Multivector.set_print_newlines(
        "s", "v.e3", "b.e12", "b.e3o", "b.e3i", "b.eoi",
        "t.e123", "t.12o", "t.e12i", "t.e3oi", "q.e123i", "q.e12oi")

    structs.append(Multivector)


    # Before returning structs, put them in order of least to most general
    # Quantify specificity by the number of variables

    ordered_structs = []
    for struct in structs:
        i = 0
        while i < len(ordered_structs):
            if len(struct.variables) < len(ordered_structs[i].variables):
                break
            else:
                i+=1
        ordered_structs.insert(i, struct)

    return ordered_structs

def create_conversion(struct1, struct2, prefix1, prefix2, variables):
    return (
        struct1, struct2,
        [prefix1+variable for variable in variables],
        [prefix2+variable for variable in variables]
    )

def make_conversions():
    # Use explicit casting for casting to a more specific type
    # Allow implicit casting for casting to a more general type
    # Conversions have the form:
    # (Struct1, Struct2, vars1, vars2)
    # If you can cast in one way, allow casting the other way

    conversions = []

    conversions.append(create_conversion(
        "Vector3", "Vector", "", "",
        ["e1", "e2", "e3"]
    ))

    conversions.append(create_conversion(
        "Bivector3", "Bivector", "", "",
        ["e23", "e31", "e12"]
    ))

    conversions.append(create_conversion(
        "Rotor3", "Rotor", "", "",
        ["s", "e23", "e31", "e12"]
    ))

    conversions.append(create_conversion(
        "Bivector3", "Rotor3", "", "b.",
        ["e23", "e31", "e12"]
    ))

    # TODO: Maybe see if I can programmatically determine the conversion
    # between types.
    # Probably still worth explicitly stating which conversions to make though.


def main():
    sig = [1, 1, 1, 1, -1]

    G = Algebra(sig)

    # Don't generate operations with the generic multivector, but use a
    # generic multivector to hold results when a more compact struct doesn't exist
    # When a multivector is returned, it is up to the code using it to extract
    # the relevant parts of it

    structs = make_structs(G)

    # Create a "Scalar" struct for the double return type
    Scalar = Struct(
        "double",
        G.grade(0),
        [""],
        None
    )
    Scalar.set_equal("", "1")

    h_base = "include/"
    cpp_base = "src/"

    with open(h_base+"cga.h", "w") as f_h:
        with open(cpp_base+"cga.cpp", "w") as f_cpp:

            f_h.write("#ifndef CGA_H\n")
            f_h.write("#define CGA_H\n")
            f_h.write("\n")
            write_includes(f_h, f_cpp)

            f_h.write("namespace cga {\n\n")
            f_cpp.write("namespace cga {\n\n")

            # Forward declarations for structs, for conversion function
            # prototypes
            for struct in structs:
                f_h.write("struct {};\n".format(struct.name))
            f_h.write("\n")

            for struct in structs:
                write_struct(G, struct, f_h, f_cpp)
            for i in range(len(structs)):
                for j in range(i, len(structs)):
                    # Skip binary operations with multivector operands
                    # if structs[i].name=="Multivector" or structs[j].name=="Multivector":
                    #     continue
                    write_binary_operations(G, structs[i], structs[j], [Scalar]+structs, f_h, f_cpp)

            # norm and norm2 need the inner product, so put after binary operations
            for struct in structs:
                write_unary_operations(G, struct, f_h, f_cpp)
                write_printing(struct, f_h, f_cpp)

            f_h.write("} // namespace cga\n\n")
            f_cpp.write("} // namespace cga\n")
            f_h.write("#endif\n")

if __name__ == "__main__":
    main()
