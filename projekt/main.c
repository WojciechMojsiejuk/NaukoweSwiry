#include <stdio.h>
#include <stdlib.h>
#include "projekt.h"

void test(ADRES lista)
{
    printf("test\n");

    while(lista!=NULL)
    {
        printf("slowo polskie: %s\n", lista -> pl);

        int i=0;
        for(i=0;i<lista->ilosc;i++)
        {
            printf("slowo angielskie: %s\n", lista -> ang[i]);
        }

        lista = lista->nast;
    }
}
/*void wypisz(ADRES poczatek,const char *nazwa)
{
    int i;
    FILE *plik=fopen(nazwa,"w");
    if(plik==NULL)
    {
      printf("blad otwarcia pliku");
      return;
    }
    while(poczatek!=NULL)
    {
        fprintf(plik,"%s:",poczatek->pl);
        for(i=0;i<(poczatek->ilosc);i++)
        {
            fprintf(plik,"%s,",poczatek->ang[i]);
        }
        poczatek=poczatek->nast;
        fprintf(plik,"\n");
    }
    fclose(plik);
}*/
int main()
{
    char nazwa[50];
    char nazwa1[50];
    printf("podaj nazwe pliku z rozszerzeniem .txt\n");
    gets(nazwa);
    ADRES pierwszy=odczyt(nazwa);
   // test(pierwszy);
    menu();
    //printf("podaj nazwe pliku do ktorego chcesz zapisac wynik z rozszerzeniem .txt\n");
    //gets(nazwa1);
    //wypisz(pierwszy,nazwa1);
    return 0;
}
