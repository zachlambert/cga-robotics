
def combination(n, level, start=1, add=True):
    if level==1:
        return [[i] for i in range(start, n+1)]
    else:
        vectors = []
        for i in range(start, n):
            vectors += [[i]+comb for comb in combination(n, level-1, i+1, False)]
        if(add):
            return combination(n, level-1) + vectors
        else:
            return vectors

def blade_name(vectors):
    name = "e"
    for vector in vectors:
        name += str(vector)
    return name

def blade_grade(vectors):
    return len(vectors)

class Algebra:
    def __init__(self, sig):
        self.n = len(sig)
        self.sig = sig
        combinations = combination(n, n)
        self.blades = { "1": [] }
        for comb in combination(n, n):
            self.blades[blade_name(comb)] = comb

    def grade(self, r):
        return [ blade for blade, vectors in blades.items() if blade_grade(vectors) == r ]
