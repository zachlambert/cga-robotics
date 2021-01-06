
# Provides the geometric product, outer product and inner product
# between basis blades, with a canonical basis

def _product(G, A, B, product="geometric"):
    # A, B = blades
    # a, b = list of vectors
    a = G.blade_to_vectors(A)
    b = G.blade_to_vectors(B)

    # Result
    coef = 1
    vectors = []

    # Merge all basis vectors from a
    while len(a)>0:
        if a[0] in b:
            if G.sig[a[0]-1]==0:
                return 0, vectors
            ind = b.index(a[0])
            num_swaps = len(a)-1 + b.index(a[0])
            if num_swaps%2 == 1:
                coef = -coef
            b.pop(ind)
            coef *= G.sig[a[0]-1]
        else:
            vectors.append(a[0])
        a.pop(0)

    # Merge the remaining basis vectors from b
    while len(b)>0:
        i = len(vectors)-1
        num_swaps = 0
        while i>=0 and vectors[i]>b[0]:
            i-=1
            num_swaps+=1
        if num_swaps%2==1:
            coef = -coef
        vectors.insert(i+1, b[0])
        b.pop(0)

    if product=="outer" and (len(vectors) != G.blade_grade(A) + G.blade_grade(B)):
        return 0, vectors
    if product=="inner" and (len(vectors) != abs(G.blade_grade(A) - G.blade_grade(B))):
        return 0, vectors

    return coef, vectors

def geometric_product(G, a, b):
    return _product(G, a, b)

def outer_product(G, a, b):
    return _product(G, a, b, "outer")

def inner_product(G, a, b):
    return _product(G, a, b, "inner")
