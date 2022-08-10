
def findF(perm):
    f = 0
    for i, elem in enumerate(perm):
        if (i+1 == elem):
            f += 1
    return f

def solveFor(x):
    a = [i + 1 for i in range(x)]
    iterations = []
    f = x

    iterations.append(" ".join([str(i) for i in a.copy()]))
    for i, _ in enumerate(a):
        a[0], a[i] = a[i], a[0]
        _f = findF(a)
        if (_f < f):
            f = _f
            iterations.append(" ".join([str(i) for i in a.copy()]))

    return "\n".join(iterations)

if (__name__ == "__main__"):
    for _ in range(int(input())):
        x = int(input())
        print(x)
        print(solveFor(x))
        
