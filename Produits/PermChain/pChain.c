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
    int arb[100], p[100], i, j;
    for (i = 1; i <= N; i++)
        arb[i - 1] = i;
    
    printPerm(arb, N);
    
    for (i = 0; i <= N; i++)
        p[i] = i;

    i = 1;

    int prev[2], _f, f = N;
    while (i < N)
    {
        p[i]--;
        if (i % 2 != 0) j = p[i];
        else j = 0;

        prev[0] = arb[i]; 
        prev[1] = arb[j];
        arb[j] = prev[0];
        arb[i] = prev[1];

        for (i = 1; p[i] == 0; i++)
            p[i] = i;

        _f = findF(arb, N);

        if (_f < f)
        {
            f = _f;
            printPerm(arb, N);
        }
    }
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