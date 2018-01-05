#include "projekt.h"
#include "projekt.h"
void odczyt(ADRES *pierwszy,const char *nazwa)
{
    FILE *plik=fopen(nazwa,"r");
    if(plik==NULL)
    {
      printf("blad wczytania pliku");
      return;
    }
    char slowo[T+1];
    ADRES tmp;
    ADRES pom;
    char znak,znak1;
    while(!feof(plik))
    {

        fscanf(plik, "%s %c", &slowo, &znak);
        if(znak=='.')
            break;
       if(znak==':')
        {
             tmp=(ADRES)malloc(sizeof(SlowoPL));
             strcpy(tmp->pl,slowo);
        }
        if(znak==',')
        {
            strcpy(tmp->ang,slowo);
        }
        if(znak=='\n')
        {
            strcpy(tmp->ang,slowo);
            
        }
        if(pierwszy==NULL)
        {
            pierwszy=tmp;
        }
        else
            {
				pom=pierwszy;
            while(pom->nast != NULL)
            {
                pom=pom->nast;
            }
            pom->nast=tmp;
            tmp->nast=NULL;
            }

    }
    fclose(plik);
}
void menu()
{
    int wybor;
    do{
            printf("Menu:\n");
            printf("1.wypisz wszystkie slowa polskie z przyporzadkowanymi angielskimi\n");
            printf("2.wypisz wszystkie angielskie oraz polskie do ktorych zostaly one przyporzadkowane \n");
            printf("3. posortuj slowa polskie a dla nich posortuj slowa angielskie\n");
            printf("4.wypisz slowa polskie majace maksymalna liczbe znaczen\n");
            printf("5.wypisz slowa angielskie najczesciej wystepujace jako tlumaczenia wraz z ich polskimi odpowiednikami\n");
            printf("6. usun slowo polskie wraz z tlumaczeniami\n");
            printf("7.usun slowo angielskie ze wszystkich tlumaczen\n");
            printf("8.wyjdz z programu\n");
            scanf("%d",&wybor);
            switch (wybor)
            {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                return;
            }
    } while (wybor!=8);
}
