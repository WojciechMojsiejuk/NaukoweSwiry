#include <stdio.h>
#include <time.h>

#define W 3
#define K 5

void Uzupelnij_tablice(int tab[][K])
{
    int i, j;
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            tab[i][j]=rand()%2;
        }
    }
}

void Wypisz_tablice(int tab[][K])
{
    int i, j;
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    FILE*zapis=fopen("[PP][L7][Z5]tablica_dwuwymiarowa.txt", "w");
    srand((unsigned)time(NULL));
    int tab[W][K], i, j;
    Uzupelnij_tablice(tab);
    Wypisz_tablice(tab);
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            fprintf(zapis, "%d ", tab[i][j]);
        }
        fprintf(zapis, "\n");
    }
    close(zapis);
    return 0;
}
