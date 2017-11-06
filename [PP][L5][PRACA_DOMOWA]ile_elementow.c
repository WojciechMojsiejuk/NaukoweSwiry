#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define W 3
#define K 4

void uzupelnij(int tablica[][K])
{
    int i, j;
    for (i=0;i<W;i++)
    {
        for (j=0;j<K;j++)
        {
            tablica[i][j]=rand()%10;
        }
    }
}

int ile(int tablica[][K], int max)
{
    int i, j, suma=0, ilosc=0;
    for (i=0;i<W;i++)
    {
        for (j=0;j<K;j++)
        {
            ilosc++;
            suma+=tablica[i][j];
            if (suma>max)
                return ilosc;
        }
    }
    return -1;
}

int main()
{
    int tab[W][K], max;
    uzupelnij(tab);
    printf("Podaj sume\n");
    scanf("%d", &max);
    int wynik=ile(tab, max);
    printf("%d", wynik);
    return 0;
}
