#include <stdio.h>

#define N 5

void wczytaj(float tablica[])
{
    int i;
    for (i=0;i<N;i++)
    {
        scanf("%f", &tablica[i]);
    }
}

void wypisz(float tablica[])
{
    int i;
    for (i=0;i<N;i++)
    {
        printf("%f ", tablica[i]);
    }
}

int main()
{
    float tab[N];
    wczytaj(tab);
    wypisz(tab);
    return 0;
}
