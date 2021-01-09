import sympy
import galgebra.atoms as ga_atoms
from galgebra.ga import Ga

"""
A Struct defines a type of object (struct) to put in the cga.h header.

Requires:
1. Definition of the member variables
- Variable type
- Variable name
2. Definition of variables, their vector expression, and how to extract them
from a result
- List of tuples, each of the form:
  (var_name, expression, extractor)
eg:
(e1, e1, e1)             struct.e1  = (e1 * result).grade(0);
(e31, e1^e3, -e1^e3)     struct.e31 = ((-e1^e3) * result).grade(0);
(eo, 0.5*(e4+e5), -ei)   struct.eo  = (-ei * result).grade(0);

Member variables can themselves be Structs.
In this case, when providing mappings between member variables and blades,
the member variables must be written as "v.e1" for example, indicating a
sub-member of a member variable.

Therefore, "e1" within this struct is referred to with "v.e1".

"""

def extract_from_product(product, blades):
    has_blade = False
    for coef in product.args:
        if type(coef) in [ga_atoms.BasisVectorSymbol, ga_atoms.BasisBladeSymbol]:
            blades.append(coef)
            has_blade = True
    if not has_blade:
        blades.append(sympy.core.numbers.Integer(1))

def extract_blades(expression):
    blades = []
    expression = expression.obj.expand()
    if type(expression) == sympy.core.mul.Mul:
        extract_from_product(expression, blades)
    elif type(expression) == sympy.core.add.Add:
        for term in expression.args:
            if type(term) in [ga_atoms.BasisVectorSymbol, ga_atoms.BasisBladeSymbol]:
                blades.append(term)
            elif type(term) == sympy.core.mul.Mul:
                extract_from_product(term, blades)
            else:
                # Symbol, float, integer, minus one, etc
                blades.append(sympy.core.numbers.Integer(1))
    else:
        blades.append(sympy.core.numbers.Integer(1))
    return blades

class Member:
    def __init__(self, name, struct=None):
        self.name = name
        self.type = "double" if struct is None else struct.name
        self.struct = struct

class Variable:
    def __init__(self, name, expression, extractor):
        self.name = name
        self.expression = expression
        self.extractor = extractor

class Struct:
    def __init__(self, name):
        self.name = name
        self.members = []
        self.variables = []

    def add_variable(self, name, expression, extractor, add_member=True):
        self.variables.append(Variable(name, expression, extractor))
        if add_member:
            self.members.append(Member(name))

    def add_struct(self, name, struct):
        for var in struct.variables:
            self.add_variable(name+"."+var.name, var.expression, var.extractor, False)
        self.members.append(Member(name, struct))

    def expression(self, struct_name = None):
        expression = 0
        prefix = "" if struct_name is None else struct_name + "."
        for var in self.variables:
            expression += sympy.Symbol(prefix+var.name) * var.expression
        return expression

    def extract(self, expression, var):
        return (var.extractor * expression).grade(0).obj.simplify()

    def validate(self):
        expression = self.expression()
        for var in self.variables:
            assert(sympy.Symbol(var.name).equals(self.extract(expression, var)))
        print(self.name, "is valid")
        self.blades = extract_blades(expression)

    def can_fit(self, blades):
        for blade in blades:
            if not blade in self.blades:
                return False
        return True

def make_structs():

    G = Ga("e_1 e_2 e_3 e_4 e_5", g=[1, 1, 1, 1, -1])
    e1, e2, e3, e4, e5 = G.mv()
    eo = 0.5*(e4 + e5)
    ei = (e5 - e4)
    s = e1*e1 # Don't know how to get a scalar 1

    structs = []

    # VECTOR3

    Vector3 = Struct("Vector3")
    Vector3.add_variable("e1", e1, e1)
    Vector3.add_variable("e2", e2, e2)
    Vector3.add_variable("e3", e3, e3)

    Vector3.validate()
    structs.append(Vector3)


    # VECTOR

    Vector = Struct("Vector")
    Vector.add_variable("e1", e1, e1)
    Vector.add_variable("e2", e2, e2)
    Vector.add_variable("e3", e3, e3)
    Vector.add_variable("eo", eo, -ei)
    Vector.add_variable("ei", ei, -eo)

    Vector.validate()
    structs.append(Vector)


    # BIVECTOR3

    Bivector3 = Struct("Bivector3")
    Bivector3.add_variable("e23", e2^e3, -e2^e3)
    Bivector3.add_variable("e31", e3^e1, -e3^e1)
    Bivector3.add_variable("e12", e1^e2, -e1^e2)

    Bivector3.validate()
    structs.append(Bivector3)


    # BIVECTOR

    Bivector = Struct("Bivector")
    Bivector.add_variable("e23", e2^e3, -e2^e3)
    Bivector.add_variable("e31", e3^e1, -e3^e1)
    Bivector.add_variable("e12", e1^e2, -e1^e2)
    Bivector.add_variable("e1o", e1^eo, e1^ei)
    Bivector.add_variable("e2o", e2^eo, e2^ei)
    Bivector.add_variable("e3o", e3^eo, e3^ei)
    Bivector.add_variable("e1i", e1^ei, e1^eo)
    Bivector.add_variable("e2i", e2^ei, e2^eo)
    Bivector.add_variable("e3i", e3^ei, e3^eo)
    Bivector.add_variable("eoi", eo^ei, eo^ei)

    Bivector.validate()
    structs.append(Bivector)


    # TRIVECTOR

    Trivector = Struct("Trivector")
    Trivector.add_variable("e123", e1^e2^e3, -e1^e2^e3)
    Trivector.add_variable("e23o", e2^e3^eo, e2^e3^ei)
    Trivector.add_variable("e31o", e3^e1^eo, e3^e1^ei)
    Trivector.add_variable("e12o", e1^e2^eo, e1^e2^ei)
    Trivector.add_variable("e23i", e2^e3^ei, e2^e3^eo)
    Trivector.add_variable("e31i", e3^e1^ei, e3^e1^eo)
    Trivector.add_variable("e12i", e1^e2^ei, e1^e2^eo)
    Trivector.add_variable("e1oi", e1^eo^ei, e1^eo^ei)
    Trivector.add_variable("e2oi", e2^eo^ei, e2^eo^ei)
    Trivector.add_variable("e3oi", e3^eo^ei, e3^eo^ei)

    Trivector.validate()
    structs.append(Trivector)

    # QUADVECTOR

    Quadvector = Struct("Quadvector")
    Quadvector.add_variable("e123o", e1^e2^e3^eo, -e1^e2^e3^ei)
    Quadvector.add_variable("e123i", e1^e2^e3^ei, -e1^e2^e3^eo)
    Quadvector.add_variable("e23oi", e2^e3^eo^ei, -e2^e3^eo^ei)
    Quadvector.add_variable("e31oi", e3^e1^eo^ei, -e3^e1^eo^ei)
    Quadvector.add_variable("e12oi", e1^e2^eo^ei, -e1^e2^eo^ei)

    Quadvector.validate()
    structs.append(Quadvector)


    # PSEUDOSCALAR3

    Pseudoscalar3 = Struct("Pseudoscalar3")
    Pseudoscalar3.add_variable("I3", e1^e2^e3, -e1^e2^e3)
    Pseudoscalar3.validate()
    structs.append(Pseudoscalar3)

    # PSEUDOSCALAR

    Pseudoscalar = Struct("Pseudoscalar")
    Pseudoscalar.add_variable("I5", e1^e2^e3^eo^ei, -e1^e2^e3^eo^ei)
    Pseudoscalar.validate()
    structs.append(Pseudoscalar)


    # ROTOR3

    Rotor3 = Struct("Rotor3")
    Rotor3.add_variable("s", s, s)
    Rotor3.add_struct("b", Bivector3)

    Rotor3.validate()
    structs.append(Rotor3)


    # ROTOR

    Rotor = Struct("Rotor")
    Rotor.add_variable("s", s, s);
    Rotor.add_struct("b", Bivector)

    Rotor.validate()
    structs.append(Rotor)


    # VERSOR

    Versor = Struct("Versor")
    Versor.add_variable("s", s, s);
    Versor.add_struct("b", Bivector)
    Versor.add_struct("q", Quadvector)

    Versor.validate()
    structs.append(Versor)


    # MULTIVECTOR

    Multivector = Struct("Multivector")
    Multivector.add_variable("s", s, s);
    Multivector.add_struct("v", Vector)
    Multivector.add_struct("b", Bivector)
    Multivector.add_struct("t", Trivector)
    Multivector.add_struct("q", Quadvector)
    Multivector.add_variable("I5", e1^e2^e3^eo^ei, -e1^e2^e3^eo^ei)

    Multivector.validate()
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

    # Also create a scalar struct to append to the "available" list
    # of structs. Has an empty variable name that it is the variable
    # itself.

    Scalar = Struct("double")
    Scalar.add_variable("", s, s)
    Scalar.validate()
    available = [Scalar] + ordered_structs

    return ordered_structs[2:5], available

if __name__ == "__main__":
    make_structs()
