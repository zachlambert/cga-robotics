class Blade:
    def __init__(self, items, sign=1):
        self.items = items
        self.sign = sign

    def basis(self):
        s = ""
        if len(self.items)==0:
            s += "1"
        else:
            s += "e"
            for item in self.items:
                s += str(item)
        return s

    def __repr__(self):
        if self.sign==-1:
            return "-" + self.basis()
        else:
            return self.basis()

    def grade(self):
        return len(self.items)

def combination(n, level, start=1, add=True):
    if level==1:
        return [[i] for i in range(start, n+1)]
    else:
        items = []
        for i in range(start, n):
            items += [[i]+comb for comb in combination(n, level-1, i+1, False)]
        if(add):
            return combination(n, level-1) + items
        else:
            return items

class Algebra:
    def __init__(self, n, sig):
        self.n = n
        self.sig = sig
        self.blades = [Blade([])] + [Blade(comb) for comb in combination(n, n)]
        self.indices = {self.blades[i].basis(): i for i in range(len(self.blades))}
    def grade(self, r):
        return [b for b in self.blades if b.grade()==r]

#TODO: Specify a transformation from the canonical basis, to the actual basis
# used in code. The canonical basis is easier to generate the operations for,
# but its more compact to use a basis with null vectors
# The choice of basis shouldn't matter, so not bothering with this for now.
class Transformation:
    pass
