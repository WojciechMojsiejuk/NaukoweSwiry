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
int main()
{
    char nazwa[X];
    printf("podaj nazwe pliku z rozszerzeniem .txt\n");
    gets(nazwa);
   ADRES pierwszy=odczyt(nazwa);
    test(pierwszy);
    menu();
    //ADRES pierwszy=odczyt(nazwa);
    return 0;
}
