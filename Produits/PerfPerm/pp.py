testN = int(input())

def get_weight(li : list):
    x = 0
    for i, val in enumerate(li):
        if (val % (i + 1) == 0):
            x += 1 
    return x

# This is a Python implementation of the QuickPerm algorithm described by Phillip Paul Fuchs at http://www.quickperm.org that generates all permutations of a list without using recursion
def quickperm(initial):
    a = initial

    N = len(a)
    p = [*range(N+1)]
    i = 1

    while True:
        yield a
        if i >= N: break

        p[i] -= 1
        j = 0 if i % 2 == 0 else p[i]
        a[j], a[i] = a[i], a[j]

        i = 1
        while p[i] == 0:
            p[i] = i
            i += 1

def gen_permutation(n : int):
    lowest = initPermute = [*range(1, n + 1)]
    
    for permute in quickperm(initPermute):
        lowest = permute.copy() if (get_weight(permute) < get_weight(lowest)) else lowest.copy()
            
        
    print(" ".join([str(i) for i in lowest]))
    

if __name__ == '__main__':
    for _ in range(testN):
        gen_permutation(int(input()))
