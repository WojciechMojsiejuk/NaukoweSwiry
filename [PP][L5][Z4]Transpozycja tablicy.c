#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 5

int main()
{
    srand((unsigned)time(NULL));
    int tab[N][N], i, j, tab2[N][N];
    for (i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            tab[i][j]=rand()%2;
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            tab2[j][i]=tab[i][j];
        }
    }
    for (i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ", tab[i][j]);
        printf("\n");
    }
    printf("\n");
    for (i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ", tab2[i][j]);
        printf("\n");
    }
    return 0;
}
