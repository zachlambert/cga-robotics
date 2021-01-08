# First, generate blades

from algebra import Algebra
from write import write_includes, write_struct, write_unary_operations, write_binary_operations, write_printing
from structs import Struct, make_structs

def main():
    sig = [1, 1, 1, 1, -1]

    G = Algebra(sig)

    # Don't generate operations with the generic multivector, but use a
    # generic multivector to hold results when a more compact struct doesn't exist
    # When a multivector is returned, it is up to the code using it to extract
    # the relevant parts of it

    structs = make_structs(G)

    # Create a "Scalar" struct for the double return type
    Scalar = Struct("double")
    Scalar.add_equal("", "1")

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
                # write_unary_operations(G, struct, f_h, f_cpp)
                write_printing(struct, f_h, f_cpp)

            f_h.write("} // namespace cga\n\n")
            f_cpp.write("} // namespace cga\n")
            f_h.write("#endif\n")

if __name__ == "__main__":
    main()
