#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 50
#define K 250

typedef struct
{
    char autor[N];
    char tytul[N];
    float czas;
    char rodzaj;
}audycja;
//struktura pomocnicza do rozwiazania podpunktu b
typedef struct
{
    char autor[N];
    float czas;
}audycja_lacznie;

int comparea(const void *w1, const void *w2)
{
    const audycja *tab_i=(audycja*)w1;
    const audycja *tab_j=(audycja*)w2;
    if(strcmp(tab_i->autor, tab_j->autor)!=0)
        return strcmp(tab_i->autor, tab_j->autor);
    if(strcmp(&tab_i->rodzaj, &tab_j->rodzaj)!=0)
        return strcmp(&tab_i->rodzaj, &tab_j->rodzaj);
    return strcmp(tab_i->tytul, tab_j->tytul);
}

int main()
{
    int licznik=0;
    audycja tab[K];
    audycja_lacznie tab2[K];
    FILE *plik=fopen("autorzy.dat", "rb");
    if(plik==NULL)
        return 1;
    while(fread(&tab[licznik], sizeof(audycja), 1, plik))
    {
        licznik++;
    }
    fclose(plik);
    
    qsort(tab, licznik, sizeof(audycja), comparea);
    int i;
    FILE *zapis = fopen("autorzy.txt","w");
    for(i=0;i<licznik;i++)
        fprintf(zapis, "%s %s %f %c \n",tab[i].autor, tab[i].tytul, tab[i].czas, tab[i].rodzaj);
    fclose(zapis);
    
    FILE *suma = fopen("autorzy_lacznie.txt","w");
    //Przypisanie jednego autora bez czasu
    strcpy(tab2[0].autor,tab[0].autor);
    
    //indeksy przypisanych autorow do drugiej struktury
    int j=0;
    
    for (i=0;i<licznik;i++)
    {
        if ( strcmp(tab[i].autor, tab2[j].autor) !=0)
        {
            ++j;
            strcpy(tab2[j].autor,tab[i].autor);
            tab2[j].czas+=tab[i].czas;
        }
        else
        {
            tab2[j].czas+=tab[i].czas;
        }
    }
    
    //podpunkt c
    
    FILE *zapisbin = fopen("autorzy_lacznie.dat","wb");
    for(i=0;i<=j;i++)
    {
        fprintf(suma, "%s %f\n",tab2[i].autor, tab2[i].czas);
        fwrite(&tab2[i], sizeof(audycja_lacznie), 1, zapisbin);
    }
    
    fclose(zapis);
    fclose(zapisbin);
    
    //sprawdzenie utworzonego pliku binarnego
    
    FILE *plik2=fopen("autorzy_lacznie.dat", "rb");
    licznik=0;
    if(plik==NULL)
        return 1;
    while(fread(&tab2[licznik], sizeof(audycja_lacznie), 1, plik2))
    {
        licznik++;
    }
    for(i=0;i<licznik;i++)
        fprintf(stdout, "%s %f \n",tab2[i].autor, tab2[i].czas);
    fclose(plik2);
    
    
    return 0;
}
