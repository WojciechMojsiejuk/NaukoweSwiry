#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 5

void wypisz(float tablica[][N])
{
    int i, j;
    for (i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%f ", tablica[i][j]);
        printf("\n");
    }
}

int suma(float tablica[][N])
{
    float sum=0.0;
    int i, j=1, k;
    for(i=0;i<N;i++)
    {
        for(k=0;k<j;k++)
        {
            sum+=tablica[i][k];
        }
        j++;
    }
    return sum;
}

int main()
{
    srand((unsigned)time(NULL));
    int i, j;
    float tab[N][N];
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            tab[i][j]=rand()%2;
    int wynik=suma(tab);
    wypisz(tab);
    printf("%d", wynik);
    return 0;
}
