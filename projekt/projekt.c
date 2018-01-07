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
        if(znak=='.')
        {
            strcpy(tmp->ang[tmp->ilosc],slowo);
            //printf("slowo angielskie: %s%c\n", tmp -> ang[tmp->ilosc], znak);
            tmp->ilosc++;
            break;
        }
        if(znak==':')
        {
            tmp=(ADRES)malloc(sizeof(SlowoPL));
            tmp->ilosc=0;
            strcpy(tmp->pl,slowo);
            puts(slowo);
            //printf("slowo polskie: %s%c\n", tmp -> pl, znak);
            puts(tmp->pl);
        }
        else
        {
            strcpy(tmp->ang[tmp->ilosc],slowo);

           // printf("slowo angielskie: %s%c\n", tmp -> ang[tmp->ilosc], znak);
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
      return NULL;
    }
    while(poczatek!=NULL)
    {
        fprintf(plik,"%s:",poczatek->pl);
         puts(poczatek->pl);
        for(i=0;i<T;i++)
        {
            fprintf(plik,"%s,",poczatek->ang[i]);
        }
        poczatek=poczatek->nast;
        fprintf(plik,"\n");
    }
    fclose(plik);
}
void maxznaczen(ADRES poczatek,const char *nazwa)
{
    FILE *plik;
    plik = fopen(nazwa,"w");
    if(plik==NULL)
    {
      printf("blad otwarcia pliku");
      return NULL;
    }
    while(poczatek!=NULL)
    {
        if(poczatek->ilosc==T)
        {
            puts(poczatek->pl);
            fputs(poczatek->pl,plik);
        }
          //  fprintf(plik,"%s ,",poczatek->pl);
        poczatek=poczatek->nast;
    }
    fclose(plik);
}
void kasuj_element(ADRES *pierwszy, const char *nazwa, char *slowodousuniecia)
{
    ADRES tmp,pom,pom2;
    if(strcmp(slowodousuniecia, (*pierwszy)->pl)== 0)
    {
        tmp = *pierwszy;
        *pierwszy = (*pierwszy) -> nast;
        free(tmp);
    }
    pom=*pierwszy;
    while(pom)
    {
        if(pom->nast!=NULL)
        {
            pom2=pom->nast;
        }
        if(strcmp(pom2->pl,slowodousuniecia)==0)
        {
            pom->nast=pom2->nast;
            free(pom2);

        }
        wypisz(*pierwszy,nazwa);
        break;
    }
    printf("nie znalezniono w bazie");
}

void menu()
{
    char nazwa1[X];
    int w;
    char nazwa[X];
    char slowodousuniecia[X];
    printf("podaj nazwe pliku z rozszerzeniem .txt\n");
    gets(nazwa);
    fflush(stdin);
    ADRES pierwszy=odczyt(nazwa);
    if (pierwszy == NULL) return;
    int wybor= -1;
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
            w = scanf("%d", &wybor);
            fflush(stdin);
            if(w==0)
            {
                printf("podaj liczbe 1-8!\n");
                continue;
            }
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
                 printf("podaj nazwe pliku do ktorego chcesz zapisac wynik z rozszerzeniem .txt\n");
                fflush(stdin);
                gets(nazwa1);
                fflush(stdin);
                maxznaczen(pierwszy,nazwa1);
                break;
            case 5:
                break;
            case 6:
                printf("podaj nazwe pliku do ktorego chcesz zapisac wynik z rozszerzeniem .txt\n");
                fflush(stdin);
                gets(nazwa1);
                fflush(stdin);
                printf("podaj slowo ktore chcesz usunac\n");
                fflush(stdin);
                gets(slowodousuniecia);
                fflush(stdin);
                kasuj_element(&pierwszy,nazwa1,slowodousuniecia);
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
