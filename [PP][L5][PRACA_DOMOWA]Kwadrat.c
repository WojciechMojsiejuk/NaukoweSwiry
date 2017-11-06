#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define W 3
#define K 5

void uzupelnij(int tablica[][K])
{
    int i, j;
    for (i=0;i<W;i++)
    {
        for (j=0;j<K;j++)
        {
            tablica[i][j]=(rand()%11)-5;
        }
    }
}

void wyswietl(int tab[][K])
{
    int i,j;
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            printf("%d\t",tab[i][j]);
        }
        printf("\n");
    }
}

void wspolrzedne(int tab[][K], int k)
{
    printf("xy");
}

int main()
{
    srand((unsigned)time(NULL));
    int tab[W][K], k;
    uzupelnij(tab);
    wyswietl(tab);
    printf("Podaj k: ");
    scanf("%d", &k);
    return 0;
}
