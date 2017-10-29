#include <stdio.h>
#include <time.h>
#include<limits.h>
#define W 5
#define K 8

void przypisz(float *tab[][K]);
void wypisz(float *tab[][K]);
int i, j,p;
int main()
{
    srand((unsigned)time(NULL));
    float tab[W][K];
    przypisz(tab);
    wypisz(tab);
    return 0;
}

void przypisz(float *tab[][K])
{

    for (i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            p=((float)rand()/SHRT_MAX)*100;
            tab[i][j]=p;
        }
    }
}
void wypisz(float *tab[][K])
{

    for (i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            printf("%d\t", tab[i][j]);
        }
        printf("\n");
    }
}
