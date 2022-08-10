#include <stdio.h>

int findF(int perm[100], int N)
{
    int f = 0;
    for (int i = 0; i < N; i++)
        if (perm[i] == i+1)
            f++;
    return f;
}

int printPerm(int perm[100], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d", perm[i]);
        if (i == N - 1) printf("\n");
        else printf(" "); 
    }
    return 0;
}

int solveFor(int N) 
{
    int perms[100][100];
    int arb[100], i, j;
    for (i = 1; i <= N; i++)
        arb[i - 1] = i;

    perms[0] = arb;


    int prev[2], pIndex = 1, _f, f = N;
    for (i = 0; i < N; i++)
    {
        prev[0] = arb[i]; 
        prev[1] = arb[N-1];
        arb[N-1] = prev[0];
        arb[i] = prev[1];
        _f = findF(arb, N);
        if (_f < f)
        {   
            perms[pIndex] = arb;
            pIndex++;
            f = _f;
        }
    }

    for (i = 0; i < pIndex; i++)
        for (j = 0; j < N; j++)
            printPerm(perms[i][j], N);
    return 0;
}

int main () 
{
    int t, n;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("%d\n", n);
        solveFor(n);
    }
    return 0;
}