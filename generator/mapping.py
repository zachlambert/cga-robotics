
class MappingElement:
    def __init__(self, sign, op1_index, op2_index):
        self.sign = sign
        self.op1_index = op1_index
        self.op2_index = op2_index

class Mapping:
    def __init__(self, op1, op2, result, indices):
        self.op1 = op1
        self.op2 = op2
        self.result = result
        self.indices = indices

def get_mapping(func, G, lhs, rhs, structs):
    # Result has the form of a dictionary, with
    # { "e1": [(1, "e3", "e31"), (...), ...],
    #   "e2": [...]
    #   ...
    # }
    # Gives an expression for each component of the result
    # where the expression is a list of terms, of the form
    # (coefficient, lhs basis, rhs basis)
    result = {}

    for A_i, A in enumerate(obj1.blades):
        for B_i, B in enumerate(obj2.blades):
            res = func(G, A, B)
            if res is None:
                continue

            element = MappingElement(res.sign, A_i, B_i)
            if not res.basis() in results:
                results[res.basis()] = []
            results[res.basis()].append(element)

    # Get the return type from available objects
    # Assume available is ordered with the more specific objects earlier
    return_obj = None
    for obj in available:
        valid = True
        obj_bases = [blade.basis() for blade in obj.blades]
        for basis in results.keys():
            if not basis in obj_bases:
                valid = False
                break
        if valid:
            return_obj = obj
            break

    # Convert result basis to indices within given objects
    indices = {}
    result_bases = [blade.basis() for blade in obj.blades]
    for result_basis, elements in results.items():
        ind = result_bases.index(result_basis)
        indices[ind] = elements

    return Mapping(obj1, obj2, return_obj, indices)
