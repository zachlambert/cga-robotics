
from structs import make_structs
from operations import get_operations
from write import write_includes, write_struct, write_printing

def main():
    G, structs, available = make_structs()
    operations = get_operations()

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

            # Forward declarations, for constructors which convert from other structs
            for struct in structs:
                f_h.write("struct {};\n".format(struct.name))
            f_h.write("\n")

            # Write struct bodies, including member functions
            for struct in structs:
                write_struct(struct, f_h, f_cpp)

            # Write geometric, outer, inner product, reverse, norm
            # Also room to add more specialised operations if necessary,
            # such as rotor transformation R*x*R.rev()
            for operation in operations:
                operation.write(G, structs, available, f_h, f_cpp)

            # Functions for printing with output streams
            for struct in structs:
                pass
                # write_printing(struct, f_h, f_cpp)

            f_h.write("} // namespace cga\n\n")
            f_cpp.write("} // namespace cga\n")
            f_h.write("#endif\n")

if __name__ == "__main__":
    main()
