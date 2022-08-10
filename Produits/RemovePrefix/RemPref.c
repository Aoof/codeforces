#include <stdio.h>


int solveFor(int a[200000], int N)
{
    if (N == 1) return 0;
    int ind, pos = 0, exists[200000] = {0};

    for (ind = N-1; ind >= 0; ind--)
    {
        if (exists[a[ind]] == 1) break;
        exists[a[ind]] = 1;
        pos++;
    }
    return N - pos;
}


int main () {
    int t, N, a[200000];
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &N);
        for (int j = 0; j < N; j++)
        {
            a[j] = 0;
            scanf("%d", &a[j]);
        }

        printf("%d\n", solveFor(a, N));
    }
    return 0;
}