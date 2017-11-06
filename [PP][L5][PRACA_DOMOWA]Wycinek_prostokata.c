#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define W 5
#define K 3

void uzupelnij(int tab[][K])
{
    srand((unsigned)time(NULL));
    int i,j;
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            tab[i][j]=rand()%5;
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

int wartosc_maksymalna(int tab[][K], int x, int y, int dl_x, int dl_y)
{
    int i, j, maksymalna=tab[x][y];
    for (i=x;i<dl_x;i++)
    {
        for (j=y;j<dl_y;j++)
        {
            if(tab[i][j]>maksymalna)
            {
                maksymalna=tab[i][j];
            }
        }
    }
    return maksymalna;
}

int main()
{
    int tab[W][K], x, y, dl_x, dl_y;
    uzupelnij(tab);
    wyswietl(tab);
    printf("Indeks x, y, dlugosc x, dlugosc y\n");
    scanf("%d%d%d%d", &x, &y, &dl_x, &dl_y);
    int wynik=wartosc_maksymalna(tab, x, y, dl_x, dl_y);
    printf("%d", wynik);
    return 0;
}
