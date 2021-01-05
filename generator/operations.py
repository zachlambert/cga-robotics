from algebra import Blade

def _product(G, A, B, product="geometric"):
    # Get list of basis vectors for each blade
    a = A.items.copy()
    b = B.items.copy()
    # Store basis vectors and sign of resultant blade
    c = []
    sign = 1
    # Merge all basis vectors from a
    while len(a)>0:
        if a[0] in b:
            if G.sig[a[0]-1]==0:
                return None
            ind = b.index(a[0])
            num_swaps = len(a)-1 + b.index(a[0])
            if num_swaps%2 == 1:
                sign = -sign
            b.pop(ind)
            sign *= G.sig[a[0]-1]
        else:
            c.append(a[0])
        a.pop(0)
    # Merge the remaining basis vectors from b
    while len(b)>0:
        i = len(c)-1
        num_swaps = 0
        while i>=0 and c[i]>b[0]:
            i-=1
            num_swaps+=1
        if num_swaps%2==1:
            sign = -sign
        c.insert(i+1, b[0])
        b.pop(0)

    if product=="outer" and (len(c) != len(A.items) + len(B.items)):
        return None
    if product=="inner" and (len(c) != abs(len(A.items) - len(B.items))):
        return None

    return Blade(c, sign)

def geometric_product(G, a, b):
    return _product(G, a, b)

def outer_product(G, a, b):
    return _product(G, a, b, "outer")

def inner_product(G, a, b):
    return _product(G, a, b, "inner")
