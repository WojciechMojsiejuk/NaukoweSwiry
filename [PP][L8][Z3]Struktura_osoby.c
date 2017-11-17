#include <stdio.h>
#include <string.h>
#define N 10
#define MAX 20
#define X 100

int i=0;//ilosc wierszy w pliku <globalna>

typedef struct osoby
{
    char Imie[MAX];
    char Nazwisko[MAX];
    int Rok;
} Osoba;

int OdczytPliku(const char* name, Osoba* tab)
{
   FILE*wskaznik=fopen(name, "r");
    if(!wskaznik)
        return 0;
    char Imie[X][MAX], Nazwisko[X][MAX];
    int Rok[X];
    while(fscanf(wskaznik, "%s %s %d", Imie[i], Nazwisko[i], &Rok[i])!=EOF)
    {
        strcpy(tab[i].Imie, Imie[i]);
        strcpy(tab[i].Nazwisko, Nazwisko[i]);
        tab[i].Rok=Rok[i];
        i++;
    }
    return 1;
}

void Wypisz_osoby(Osoba* tab)
{
    int k;
    printf("Wszystkie osoby:\n\n");
    for(k=0;k<i;k++)
        printf("%s %s %d\n", tab[k].Imie, tab[k].Nazwisko, tab[k].Rok);
}

int MinRok(Osoba* tab, int licznik)
{
    int minimum=tab[0].Rok, k=0;
    for(k=1;k<i;k++)
    {
        if(tab[k].Rok<minimum)
        {
            minimum=tab[k].Rok;
        }
    }
    return minimum;
}

void TworzPlikWynikowy(const char* name, Osoba* tab, int licznik, int min_rok)
{
    FILE*zapis=fopen(name, "w");
    if(!zapis)
    {
        perror(name);
        return;
    }
    int k;
    for (k=0;k<i;k++)
    {
        if(tab[k].Rok==min_rok)
            fprintf(zapis, "%s %s %d\n", tab[k].Imie, tab[k].Nazwisko, tab[k].Rok);
    }
    fclose(zapis);
}

int main(void)
{
    int licznik, min_rok;
    Osoba tab[N];
    /* przepisanie zawartosci pliku do tablicy */
    licznik = OdczytPliku("in.txt", tab);
    if (licznik==0)
        return 1;
    Wypisz_osoby(tab);
    /* znalezienie minimalnego roku */
    min_rok = MinRok(tab, licznik);
    /* zapis do pliku wynikowego informacji o najmlodszych osobach */
    TworzPlikWynikowy("out.txt", tab, licznik, min_rok);
    return 0;
}
