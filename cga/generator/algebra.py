
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
        self.blades = ["1"]
        for comb in combination(self.n, self.n):
            self.blades.append(self.vectors_to_blade(comb))

    def blade_to_vectors(self, blade):
        if blade=="1":
            return []
        else:
            return [int(blade[i]) for i in range(1, len(blade))]

    def vectors_to_blade(self, vectors):
        if len(vectors) == 0:
            return "1"
        else:
            return "e" + "".join([str(vector) for vector in vectors])

    def blade_grade(self, blade):
        if blade=="1":
            return 0
        else:
            return len(blade)-1

    def vectors_grade(self, vectors):
        return len(vectors)

    def grade(self, r):
        return [ blade for blade in self.blades if self.blade_grade(blade) == r ]
