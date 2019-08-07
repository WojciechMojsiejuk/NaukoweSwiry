#include <stdio.h>
#define MAX 20 //maksymalna dlugosc pola (imie, nazwisko)
#define N 3 //liczba rekordow w pliku

typedef struct
{
    char imie[MAX];
    char nazwisko[MAX];
    int rok;
}Osoba;

int OdczytPliku(const char *nazwa, Osoba *tab)
{
    FILE *plik;
    plik=fopen(nazwa, "r");
    if(plik==NULL)
        return 0;
    int i;
    for(i=0;i<N;i++)
    {
        if(fscanf(plik, "%s", tab[i].imie)==EOF)
            break;
        fscanf(plik, "%s", tab[i].nazwisko);
        fscanf(plik, "%d", &tab[i].rok);
    }
    fclose(plik);
    return i;
}

void f1(const Osoba *os)
{
        printf("%s\t%s\t%d\n", os->imie, os->nazwisko, os->rok);
}

void f2(const Osoba *os)
{
        printf("%s\n%s\n%d\n", os->imie, os->nazwisko, os->rok);
}

void WypiszTablice(Osoba *tab, void(*F)(const Osoba*))
{
    int i;
    for(i=0;i<N;i++)
        F(&tab[i]);
}

int main()
{
    Osoba tab[N];
    int licznik;
    licznik = OdczytPliku("in.txt", tab);
    if (licznik==0)
        return 1;
    WypiszTablice(tab, f1);
    WypiszTablice(tab, f2);
    return 0;
}
