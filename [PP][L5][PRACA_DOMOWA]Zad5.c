#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 4

void uzupelnij(int tablica[][N])
{
    int i, j;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            tablica[i][j]=rand()%2;
        }
    }
}

void wyswietl(int tab[][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d\t",tab[i][j]);
        }
        printf("\n");
    }
}

int suma(int tab[][N], int indeks_wiersza)
{
    int i, j, sum=0, pom=0;
    for (i=0;i<indeks_wiersza;i++)
    {
        pom++;
        for(j=0;j<pom;j++)
        {
            sum+=tab[i][j];
        }
    }
    for (i=indeks_wiersza, j=0;j<N;j++)
    {
        sum+=tab[i][j];
    }
    for (i=indeks_wiersza+1;i<N;i++)
    {
        for(j=N-indeks_wiersza+1;j<N;j++)
        {
            sum+=tab[i][j];
        }
    }
    return sum;
}

int main()
{
    srand((unsigned)(time(NULL)));
    int tab[N][N], numer_wiersza=1;
    uzupelnij(tab);
    printf("Podaj numer wiersza: ");
    scanf("%d", &numer_wiersza);
    if(numer_wiersza>N || numer_wiersza<=0)
        return 1;
    wyswietl(tab);
    int sum=suma(tab, numer_wiersza-1);
    printf("Suma tego czegos to: %d", sum);
    return 0;
}
