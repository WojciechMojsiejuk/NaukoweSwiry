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
    if (!wskaznik)
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
    fclose(wskaznik);
    return 1;
}

void przepisz(const char* plik, Osoba* tab)
{
    FILE*wskaznik=fopen(plik, "wb");
    fwrite(tab, sizeof(*tab), sizeof(tab), wskaznik);
    fclose(wskaznik);
}

int main()
{
    int licznik;
    Osoba tab[N];
    char nazwa[200];
    strcpy(nazwa, "[PP][L8][Z5]plik.dat");
    licznik = OdczytPliku("in.txt", tab);
    if (licznik==0)
        return 1;
    przepisz(nazwa, tab);
    return 0;
}
