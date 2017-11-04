#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

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

void suma(float tab[][N])
{
    int i,j;
    float sum[N], sum_najwieksza;
    for(j=0;j<N;j++)
    {
        sum_najwieksza+=tab[0][j];
    }
    sum[0]=sum_najwieksza;
    for(i=1;i<N;i++)
    {
        sum[i]=0.0;
        for(j=0;j<N;j++)
        {
            sum[i]+=tab[i][j];
        }
        //printf("sum[%d]=%d ", i, sum[i]);
        if(sum[i]>sum_najwieksza)
        {
            sum_najwieksza=sum[i];
        }
    }
    for (i=0;i<N;i++)
    {
        if(sum[i]==sum_najwieksza)
        {
            printf("indeks=%d suma=%f\n", i, sum[i]);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));
    int i, j;
    float tab[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            tab[i][j]=rand()%2;
        }
    }
    wypisz(tab);
    suma(tab);
    return 0;
}
