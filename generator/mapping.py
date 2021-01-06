
def get_mapping(func, G, lhs, rhs, structs):
    # Results has the form of a dictionary, with
    # { "e1": [(1, "e3", "e31"), (...), ...],
    #   "e2": [...]
    #   ...
    # }
    # Gives an expression for each component of the result
    # where the expression is a list of terms, of the form
    # (coefficient, lhs basis, rhs basis)
    results = {}

    for lhs_blade in lhs.blades:
        for rhs_blade in rhs.blades:
            coef, vectors = func(G, lhs_blade, rhs_blade)
            if coef == 0:
                continue
            blade = G.vectors_to_blade(vectors)
            # print(lhs_blade, "*", rhs_blade, " = ", coef, "*",blade)
            if not blade in results:
                results[blade] = []
            results[blade].append((coef, lhs_blade, rhs_blade))

    if len(results)==0:
        return results, None

    # Get the return struct from available structs
    # Assume structs are ordered with more specific structs earlier
    return_struct = None
    for struct in structs:
        valid = True
        for blade in results.keys():
            # Invalidate if the return struct is missing this blade
            if not blade in struct.blades:
                valid = False
                break
        if valid:
            return_struct = struct
            break

    return results, return_struct
