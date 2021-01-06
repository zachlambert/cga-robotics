# First, generate blades

from algebra import Algebra, Blade
from write import write_includes, write_struct, write_unary_operations, write_binary_operations

class Struct:
    def __init__(self, name, blades, variables, types):
        self.name = name
        self.blades = blades
        self.variables = variables
        self.types = types
        self.var_expressions = {}
        self.blade_expressions = {}
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

def make_grades(G):

    # VECTOR

    Vector = Struct(
        "Vector",
        G.grade(1),
        ["e1", "e2", "e3", "eo", "ei"],
        ["double" for i in range(5)]
    )

    Vector.set_equal("e1", "e1")
    Vector.set_equal("e2", "e2")
    Vector.set_equal("e3", "e3")

    Vector.set_var_expression("eo", [(0.5, "e4"), (-0.5, "e5")])
    Vector.set_var_expression("ei", [(-1, "e4"), (1, "e5")])
    Vector.set_blade_expression("e4", [(1, "eo"), (-0.5, "ei")])
    Vector.set_blade_expression("e5", [(1, "eo"), (0.5, "ei")])

    # BIVECTOR

    Bivector = Struct(
        "Bivector",
        G.grade(2),
        ["e23", "e31", "e12", "e1o", "e2o", "e3o", "e1i", "e2i", "e3i", "eoi"],
        ["double" for i in range(10)]
    )

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

    # TRIVECTOR

    Trivector = Struct(
        "Trivector",
        G.grade(3),
        ["e123", "e23o", "e31o", "e12o", "e23i", "e31i", "e12i", "e1oi", "e2oi", "e3oi"],
        ["double" for i in range(10)]
    )

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

    # QUADVECTOR

    Quadvector = Struct(
        "Quadvector",
        G.grade(4),
        ["e123o", "e123i", "e23oi", "e31oi", "e12oi"],
        ["double" for i in range(5)]
    )

    Quadvector.set_var_expression("e123o", [(0.5, "e1234"), (0.5, "e1235")])
    Quadvector.set_var_expression("e123i", [(-1, "e1234"), (1, "e1235")])

    Quadvector.set_blade_expression("e1234", [(1, "e123o"), (-0.5, "e123i")])
    Quadvector.set_blade_expression("e1235", [(1, "e123o"), (0.5, "e123i")])

    Quadvector.set_equal("e23oi", "e2345")
    Quadvector.set_opposite("e31oi", "e1345")
    Quadvector.set_equal("e12oi", "e1245")

    Bivector.set_equal("eoi", "e45")

    # PSEUDOSCALAR

    Pseudoscalar = Struct(
        "Pseudoscalar",
        G.grade(5),
        ["I5"],
        ["double"]
    )
    Pseudoscalar.set_equal("I5", "e12345")

    return [Vector, Bivector, Trivector, Quadvector, Pseudoscalar]

def make_compounds(grades_dict):
    Rotor = Struct("Rotor", ["s", "b"], ["double", "Bivector"], [0, 2])
    Rotor.set_equal("s", "1");
    Rotor.copy("b.", grades_dict["Bivector"])

    Versor = Struct("Versor", ["double s", "Bivector b", "Quadvector q"])
    Rotor.set_equal("s", "1");
    Versor.copy("b.", grades_dict["Bivector"])
    Versor.copy("q.", grades_dict["Quadvector"])

    Multivector = Struct("Multivector",
        ["double s", "Vector v", "Bivector b", "Trivector t", "Quadvector q", "Pseudoscalar p"])
    Rotor.set_equal("s", "1");
    Versor.copy("v.", grades_dict["Vector"])
    Versor.copy("b.", grades_dict["Bivector"])
    Versor.copy("t.", grades_dict["Trivector"])
    Versor.copy("q.", grades_dict["Quadvector"])
    Versor.copy("p.", grades_dict["Pseudoscalar"])

    return [Rotor, Versor, Multivector]

def main():
    sig = [1, 1, 1, 1, -1]

    G = Algebra(sig)

    grades = make_grades()
    structs = grades + make_compounds({ grade.name: grade for grade in grades})

    h_base = "include/"
    cpp_base = "src/"

    with open(h_base+"cga_gen.h", "w") as f_h:
        with open(cpp_base+"cga_gen.cpp", "w") as f_cpp:
            write_includes(f_h)
            for struct in structs:
                write_struct(G, struct, f_h, f_cpp)
                write_unary_operations(G, struct, f_h, f_cpp)
            for i in range(len(structs)):
                for j in range(i, len(structs)):
                    write_binary_operations(G, structs[i], structs[j], structs, f_h, f_cpp)
            # norm and norm2 need the inner product, so put after binary operations
            for struct in structs:
                write_unary_operations(G, struct, f_h, f_cpp)

if __name__ == "__main__":
    main()
