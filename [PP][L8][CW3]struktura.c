#include <stdio.h>
#include <string.h>
#define N 10
#define MAX 20
typedef struct
{
    char imie[MAX];
    char nazwisko[MAX];
    int rok;
}Osoba;
int OdczytPliku(const char*n,Osoba t1[])
{
    FILE*plik=fopen(n,"r");
    if (plik==NULL) return 0;
    int i;
    for(i=0;i<N;i++)
    {
        if(fscanf(plik,"%s",t1[i].imie)==EOF) break;
        fscanf(plik,"%s",t1[i].nazwisko);
        fscanf(plik,"%d", &t1[i].rok);
    }
    fclose(plik);
    return i;
}
int MinRok(Osoba *tab,int licznik)
{
    int minimum=tab[0].rok;
    int i;
    for(i=1;i<licznik;i++)
    {
        minimum = tab[i].rok;
    }
    return minimum;
}
void TworzPlikWynikowy(const char*nazwa,Osoba*tab,int licznik,int min_rok)
{
    FILE*dane=fopen(nazwa,"w");
    if(dane==NULL) return;
    int i;
    for(i=0;i<licznik;i++)
    {
        if(tab[i].rok==min_rok)
        {
            fprintf(dane,"%s %s %d\n", tab[i].imie, tab[i].nazwisko, tab[i].rok);
        }
    }
     fclose(dane);
}
int main(void)
{
 int licznik, min_rok;
 Osoba tab[N];
 /* przepisanie zawartosci pliku do tablicy */
 licznik = OdczytPliku("in.txt", tab);
 if (licznik==0)
 return 1;
 /* znalezienie minimalnego roku */
 min_rok = MinRok(tab, licznik);
 /* zapis do pliku wynikowego informacji o najmlodszych osobach */
 TworzPlikWynikowy("out.txt", tab, licznik, min_rok);
 return 0;
}
