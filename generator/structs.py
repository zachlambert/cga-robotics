
"""
A Struct defines a type of object (struct) to put in the cga.h header.

Requires:
1. Definition of the member variables
- Variable type
- Variable name
2. Definition of the blades and a mapping between the blades
   and variables
- List of blades
- Expression for each blade in terms of member variables
- Expression for each member variable in terms of blades

Member variables can themselves be Structs.
In this case, when providing mappings between member variables and blades,
the member variables must be written as "v.e1" for example, indicating a
sub-member of a member variable.

Therefore, "e1" within this struct is referred to with "v.e1".

For some functions (eg: reverse), it is useful to see what variable belong
to which members, which can be done by splitting the variable on "."

"""

class Member:
    def __init__(self, name, struct=None):
        self.name = name
        self.type = "double" if struct is None else struct.name
        self.struct = struct

class Struct:
    def __init__(self, name):
        self.name = name
        self.members = []
        self.blade_expressions = {}
        self.var_expressions = {}

    def add_member(self, var, expression):
        self.var_expressions[var] = expression
        self.members.append(Member(var))

    def add_blade(self, blade, expression):
        self.blade_expressions[blade] = expression

    def add_equal(self, var, blade):
        self.add_member(var, [(1, blade)])
        self.add_blade(blade, [(1, var)])

    def add_opposite(self, var, blade):
        self.add_member(var, [(-1, blade)])
        self.add_blade(blade, [(-1, var)])

    def add_struct(self, name, struct):
        for var, expression in struct.var_expressions.items():
            self.var_expressions[name+"."+var] = expression
        for blade, expression in struct.blade_expressions.items():
            self.blade_expressions[blade] = [(term[0], name+"."+term[1]) for term in expression]
        self.members.append(Member(name, struct))

    def blades(self):
        return self.blade_expressions.keys()

    def variables(self):
        return self.var_expressions.keys()

    # def add_constructor(self, params, init_list, explicit=False):
    #     self.constructors.append((params, init_list, explicit))


def make_structs(G):

    structs = []

    # VECTOR3

    Vector3 = Struct("Vector3")
    Vector3.add_equal("e1", "e1")
    Vector3.add_equal("e2", "e2")
    Vector3.add_equal("e3", "e3")

    structs.append(Vector3)


    # VECTOR

    Vector = Struct("Vector")
    Vector.add_equal("e1", "e1")
    Vector.add_equal("e2", "e2")
    Vector.add_equal("e3", "e3")
    Vector.add_member("eo", [(0.5, "e4"), (-0.5, "e5")])
    Vector.add_member("ei", [(-1, "e4"), (1, "e5")])
    Vector.add_blade("e4", [(1, "eo"), (-0.5, "ei")])
    Vector.add_blade("e5", [(1, "eo"), (0.5, "ei")])

    # Vector.add_constructor("", "e1(0), e2(0), e3(0), eo(0), ei(0)")
    # Vector.add_constructor("double e1, double e2, double e3, double eo, double ei", "e1(e1), e2(e2), e3(e3), eo(eo), ei(ei)")
    # Vector.add_constructor("const Vector3 &v", "e1(v.e1), e2(v.e2), e3(v.e3), eo(0), ei(0)")
    # Vector.add_constructor("const Multivector &mv", "e1(mv.v.e1), e2(mv.v.e2), e3(mv.v.e3), eo(mv.v.eo), ei(mv.v.ei)", True)

    structs.append(Vector)


    # BIVECTOR

    Bivector = Struct("Bivector")

    Bivector.add_equal("e23", "e23")
    Bivector.add_opposite("e31", "e13")
    Bivector.add_equal("e12", "e12")

    Bivector.add_member("e1o", [(0.5, "e14"), (0.5, "e15")])
    Bivector.add_member("e2o", [(0.5, "e24"), (0.5, "e25")])
    Bivector.add_member("e3o", [(0.5, "e34"), (0.5, "e35")])
    Bivector.add_member("e1i", [(-1, "e14"), (1, "e15")])
    Bivector.add_member("e2i", [(-1, "e24"), (1, "e25")])
    Bivector.add_member("e3i", [(-1, "e34"), (1, "e35")])

    Bivector.add_blade("e14", [(1, "e1o"), (-0.5, "e1i")])
    Bivector.add_blade("e15", [(1, "e1o"), (0.5, "e1i")])
    Bivector.add_blade("e24", [(1, "e2o"), (-0.5, "e2i")])
    Bivector.add_blade("e25", [(1, "e2o"), (0.5, "e2i")])
    Bivector.add_blade("e34", [(1, "e3o"), (-0.5, "e3i")])
    Bivector.add_blade("e35", [(1, "e3o"), (0.5, "e3i")])

    Bivector.add_equal("eoi", "e45")

    structs.append(Bivector)


    # TRIVECTOR

    Trivector = Struct("Trivector")

    Trivector.add_equal("e123", "e123")

    Trivector.add_member("e23o", [(0.5, "e234"), (0.5, "e235")])
    Trivector.add_member("e31o", [(-0.5, "e134"), (-0.5, "e135")])
    Trivector.add_member("e12o", [(0.5, "e124"), (0.5, "e125")])

    Trivector.add_member("e23i", [(-1, "e234"), (1, "e235")])
    Trivector.add_member("e31i", [(1, "e134"), (-1, "e135")])
    Trivector.add_member("e12i", [(-1, "e124"), (1, "e125")])

    Trivector.add_blade("e234", [(1, "e23o"), (-0.5, "e23i")])
    Trivector.add_blade("e235", [(1, "e23o"), (0.5, "e23i")])
    Trivector.add_blade("e134", [(-1, "e31o"), (0.5, "e31i")])
    Trivector.add_blade("e135", [(-1, "e31o"), (-0.5, "e31i")])
    Trivector.add_blade("e124", [(1, "e12o"), (-0.5, "e12i")])
    Trivector.add_blade("e125", [(1, "e12o"), (0.5, "e12i")])

    Trivector.add_equal("e1oi", "e145")
    Trivector.add_equal("e2oi", "e245")
    Trivector.add_equal("e3oi", "e345")

    structs.append(Trivector)

    # QUADVECTOR

    Quadvector = Struct("Quadvector")

    Quadvector.add_member("e123o", [(0.5, "e1234"), (0.5, "e1235")])
    Quadvector.add_member("e123i", [(-1, "e1234"), (1, "e1235")])

    Quadvector.add_blade("e1234", [(1, "e123o"), (-0.5, "e123i")])
    Quadvector.add_blade("e1235", [(1, "e123o"), (0.5, "e123i")])

    Quadvector.add_equal("e23oi", "e2345")
    Quadvector.add_opposite("e31oi", "e1345")
    Quadvector.add_equal("e12oi", "e1245")

    structs.append(Quadvector)


    # PSEUDOSCALAR

    Pseudoscalar = Struct("Pseudoscalar")
    Pseudoscalar.add_equal("p", "e12345")
    structs.append(Pseudoscalar)


    # PSEUDOSCALAR3

    Pseudoscalar3 = Struct("Pseudoscalar3")
    Pseudoscalar3.add_equal("p", "e123")

    structs.append(Pseudoscalar3)


    # BIVECTOR3

    Bivector3 = Struct("Bivector3")
    Bivector3.add_equal("e23", "e23")
    Bivector3.add_opposite("e31", "e13")
    Bivector3.add_equal("e12", "e12")

    structs.append(Bivector3)


    # ROTOR3

    Rotor3 = Struct("Rotor3")
    Rotor3.add_equal("s", "1")
    Rotor3.add_struct("b", Bivector3)

    structs.append(Rotor3)


    # ROTOR

    Rotor = Struct("Rotor")
    Rotor.add_equal("s", "1");
    Rotor.add_struct("b", Bivector)

    structs.append(Rotor)


    # VERSOR

    Versor = Struct("Versor")
    Versor.add_equal("s", "1");
    Versor.add_struct("b", Bivector)
    Versor.add_struct("q", Quadvector)

    structs.append(Versor)


    # MULTIVECTOR

    Multivector = Struct("Multivector")
    Multivector.add_equal("s", "1");
    Multivector.add_struct("v", Vector)
    Multivector.add_struct("b", Bivector)
    Multivector.add_struct("t", Trivector)
    Multivector.add_struct("q", Quadvector)
    Multivector.add_equal("p", "e12345")

    structs.append(Multivector)


    # Before returning structs, put them in order of least to most general
    # Quantify specificity by the number of variables

    ordered_structs = []
    for struct in structs:
        i = 0
        while i < len(ordered_structs):
            if len(struct.variables()) < len(ordered_structs[i].variables()):
                break
            else:
                i+=1
        ordered_structs.insert(i, struct)

    return ordered_structs
