# First, generate blades

from algebra import Algebra, Blade
from write import write_struct, write_products

class Struct:
    def __init__(self, name, blades):
        self.name = name
        self.blades = blades

def main():
    n = 5
    sig = [1, 1, 1, 1, -1]

    G = Algebra(n, sig)
    # TODO: Include a dimension transformation, to use the null
    # vectors eo and ei instead of e+ and e-.

    structs = []
    structs.append(Struct("Vector", G.grade(1)))
    structs.append(Struct("Bivector", G.grade(2)))
    structs.append(Struct("Trivector", G.grade(3)))
    structs.append(Struct("Quadvector", G.grade(4)))
    structs.append(Struct("Pseudoscalar", G.grade(5)))
    # structs.append(Struct("Rotor", G.grade(0) + G.grade(2)))
    # structs.append(Struct("Versor", G.grade(0) + G.grade(2) + G.grade(4)))

    h_base = "include/"
    cpp_base = "src/"

    with open(h_base+"cga_gen.h", "w") as f_h:
        with open(cpp_base+"cga_gen.cpp", "w") as f_cpp:
            for struct in structs:
                write_struct(G, struct, f_h, f_cpp)
            # for i in range(len(structs)):
            #     for j in range(i, len(structs)):
            #         write_products(G, structs[i], structs[j], structs, f_h, f_cpp)

if __name__ == "__main__":
    main()
