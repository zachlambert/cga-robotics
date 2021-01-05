# First, generate blades

from algebra import Algebra, Blade
from write import write_products

class Object:
    def __init__(self, name, handle, blades):
        self.name = name
        self.handle = handle
        self.blades = blades

def main():
    n = 5
    sig = [1, 1, 1, 1, -1]

    G = Algebra(n, sig)


    grades = []
    grades.append(Object("Vector", "VectorHandle", G.grade(1)))
    grades.append(Object("Bivector", "BivectorHandle", G.grade(2)))
    grades.append(Object("Trivector", "TrivectorHandle", G.grade(3)))
    grades.append(Object("Quadvector", "QuadvectorHandle", G.grade(4)))
    grades.append(Object("Pseudoscalar", "Pseudoscalar", G.grade(5)))

    scalar = Object("double", "double", G.grade(0))
    multivector = Object("Multivector", "Multivector", G.blades)
    versor = Object("Versor", "Versor", G.grade(0) + G.grade(2))

    # More specific objects earlier
    available = [scalar] + grades + [versor, multivector]

    h_base = "include"
    cpp_base = "src"

    with open(h_base+"multivector.h", "w") as f_h:
        with open(cpp_base+"multivector.cpp", "w") as f_cpp:
            for obj in [multivector] + grades:
                write_products(G, multivector, obj, available, f_h, f_cpp)

    with open(h_base+"versor.h", "w") as f_h:
        with open(cpp_base+"versor.cpp", "w") as f_cpp:
            for obj in [versor] + grades:
                write_products(G, versor, obj, available, f_h, f_cpp)

    with open(h_base+"grades.h", "w") as f_h:
        with open(cpp_base+"grades.cpp", "w") as f_cpp:
            for i in range(len(grades)):
                for j in range(i, len(grades)):
                    write_products(G, grades[i], grades[j], available, f_h, f_cpp)
