#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void uzupelnij(float tablica[], int n)
{
    int i;
    for(i=0;i<n;i++)
        tablica[i]=(float)rand()/SHRT_MAX;
}

void wypisz(float tablica[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%f ", tablica[i]);
    printf("\n");
}

float iloczyn_skalarny(float tablica[], float tablica2[], int n)
{
    int i;
    float iloczyn=0.0;
    for(i=0;i<n;i++)
    {
        iloczyn+=tablica[i]*tablica2[i];
    }
    return iloczyn;
}

int main()
{
    srand((unsigned)(time(NULL)));
    int n;
    scanf("%d", &n);
    float tab[n], tab2[n];
    uzupelnij(tab, n);
    uzupelnij(tab2, n);
    wypisz(tab, n);
    wypisz(tab2, n);
    float wynik=iloczyn_skalarny(tab, tab2, n);
    printf("%f", wynik);
    return 0;
}
