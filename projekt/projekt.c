#include "projekt.h"
ADRES odczyt(const char *nazwa)
{
    ADRES poczatekListy = NULL;

    FILE *plik=fopen(nazwa,"r");
    if(plik==NULL)
    {
      printf("blad wczytania pliku");
      return NULL;
    }
    char slowo[T+1];
    ADRES tmp;
    ADRES pom;
    char znak;
    while(!feof(plik))
    {
       fscanf(plik, "%s %c", slowo, &znak);
       //printf("%s %c\n",slowo,znak);
        if(znak=='.')
        {
            strcpy(tmp->ang[tmp->ilosc],slowo);
            printf("slowo angielskie: %s%c\n", tmp -> ang[tmp->ilosc], znak);
            tmp->ilosc++;
            break;
        }
        if(znak==':')
        {
            tmp=(ADRES)malloc(sizeof(SlowoPL));
            tmp->ilosc=0;
            strcpy(tmp->pl,slowo);
            printf("slowo polskie: %s%c\n", tmp -> pl, znak);
        }
        else
        {
            strcpy(tmp->ang[tmp->ilosc],slowo);
            printf("slowo angielskie: %s%c\n", tmp -> ang[tmp->ilosc], znak);
            tmp->ilosc++;
        }
        if(poczatekListy==NULL)
        {
            poczatekListy=tmp;
        }

        else
        {
            pom=poczatekListy;

            pom->nast=tmp;

            pom=pom->nast;

            pom->nast=NULL;
        }
    }
    fclose(plik);

    return poczatekListy;
}
void wypisz(ADRES poczatek,const char *nazwa)
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
}
void menu()
{
    char nazwa1[50];
    char nazwa[50];
    ADRES pierwszy=odczyt(nazwa);
    int wybor = -1;
    do{
            printf("\nMenu:\n");
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
               printf("podaj nazwe pliku do ktorego chcesz zapisac wynik z rozszerzeniem .txt\n");
               fflush(stdin);
                gets(nazwa1);
                fflush(stdin);
                wypisz(pierwszy,nazwa1);
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
            default:
                printf("wybierz numer 1-8!\n");
                break;
            }
    } while (wybor!=8);
}
