#include <stdio.h>
#include <string.h>
#define N 10
#define MAX 20
#define X 100

typedef struct osoby
{
    char Imie[MAX];
    char Nazwisko[MAX];
    int Rok;
} Osoba;

int OdczytPliku(const char* name, Osoba* tab)
{
    int i=0;
   FILE*wskaznik=fopen(name, "r");
    if(!wskaznik)
    {
        perror(name);
        return 0;
    }
    char Imie[X][MAX], Nazwisko[X][MAX];
    int Rok[X];
    while(fscanf(wskaznik, "%s %s %d", Imie[i], Nazwisko[i], &Rok[i])!=EOF)
    {
        strcpy(tab[i].Imie, Imie[i]);
        strcpy(tab[i].Nazwisko, Nazwisko[i]);
        tab[i].Rok=Rok[i];
        i++;
    }
    return i;
}

void Wypisz_osobe(Osoba* tab, int index)
{
    printf("%s %s %d", tab[index].Imie, tab[index].Nazwisko, tab[index].Rok);
}

void Choice1(void (*Wypisz_osobe), Osoba* tab, int licznik)
{
    Wypisz_osobe(tab, licznik);
}

void Choice2()
{

}

void Wypisz_osoby(Osoba* tab, int licznik)
{
    int k;
    printf("Wszystkie osoby:\n\n");
    for(k=0;k<licznik;k++)
        printf("%s %s %d\n", tab[k].Imie, tab[k].Nazwisko, tab[k].Rok);
}

int main(void)
{
    int licznik, choice;
    Osoba tab[N];
    void (*wskaznik)(Osoba*, int);

    licznik = OdczytPliku("in.txt", tab);
    if (licznik==0)
        return 1;

    printf("1-dane w jednej linii\n"
           "2-dane w wielu liniach\n");
    scanf("%d", &choice);

    if(choice==1)
    {
        Choice1(wskaznik, tab, licznik);
    }
    else
    {
        Wypisz_osoby(tab, licznik);
    }

    Wypisz_osoby(tab, licznik);
    return 0;
}
