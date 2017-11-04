#include <stdio.h>
#include <time.h>
#include<limits.h>
#define N 5

void przypisz(float *tab[][N]);
void wypisz(float *tab[][N]);
void przekatna(float *tab[][N]);
int i, j,p,r;
int main()
{
    srand((unsigned)time(NULL));
    float tab[N][N];
    przypisz(tab);
    wypisz(tab);
    przekatna(tab);
    return 0;
}

void przypisz(float *tab[][N])
{

    for (i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            p=((float)rand()/SHRT_MAX)*10;
            tab[i][j]=p;
        }
    }
}
void wypisz(float *tab[][N])
{

    for (i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d\t", tab[i][j]);
        }
        printf("\n");
    }
}
void przekatna(float *tab[][N])
{
    int suma=0;
    for(i=0;i<N;i++)
    {
            p=tab[i][i];
            r=tab[i][N-i-1];
            suma+=p+r;
            printf("suma= %d \n", suma);
    }
    if(N%2!=0)
        p=tab[N/2][N/2];
        suma-=p;
    printf("Suma przekatnych wynosi %d",suma);
}
