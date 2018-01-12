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
    int i,j;
    FILE *plik=fopen(nazwa,"w");
    if(plik==NULL)
    {
      printf("blad otwarcia pliku");
      return NULL;
    }
    while(poczatek!=NULL)
    {
        fprintf(plik, "%s :",poczatek->pl);
        // puts(poczatek->pl);
        if(poczatek->nast==NULL)
            {
                for(j=0;j<poczatek->ilosc;j++)
                {
                if(j+1==poczatek->ilosc)
                {
                    fprintf(plik, " %s .",poczatek->ang[j]);
                }
                else fprintf(plik, " %s ,",poczatek->ang[j]);
                }
                break;
            }
        for(i=0;i<poczatek->ilosc;i++)
        {
            fprintf(plik, " %s ,",poczatek->ang[i]);
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
void usuwanieang(ADRES pierwszy,const char *nazwa, char *slowoang)
{
    int i;
    bool a=false;
    ADRES pom=pierwszy;
    while(pom!=NULL)
    {
        for(i=0;i<T;i++)
        {
            if(strcmp(pom->ang[i],slowoang)==0)
            {
                strcpy(pom->ang[i], "\0");
                a=true;
                pom->ilosc--;
            }
        }
        pom=pom->nast;
    }
    wypisz(pierwszy,nazwa);
    if(!a) printf("nie znalezniono takiego tlumaczenia\n");
}
void sortowanie(ADRES *pierwszy, const char *nazwa)
{
    ADRES pom1,pom2;
    int i,j,k;
    int zmiana=0;
    for(pom1=*pierwszy;pom1->nast!=NULL;pom1=pom1->nast)
    {
        for(pom2=pom1->nast;pom2!=NULL;pom2=pom2->nast)
        {
            if(comparestrings(pom1->pl,pom2->pl)>0)
            {
                char tmp[X];
                zmiana=1;
                strcpy(tmp, pom2 -> pl);
                strcpy(pom2 -> pl,pom1 -> pl);
                strcpy(pom1->pl, tmp);
            }
            for(i=0;i<T;i++)
            {
                for(j=i+1;j<=T;j++)
                {
                    if(comparestrings(pom2->ang[i],pom2->ang[j])>0)
                    {
                        char tmp[X];
                        strcpy(tmp, pom2 -> ang[i]);
                        strcpy(pom2 -> ang[i],pom2 -> ang[j]);
                        strcpy(pom2->ang[j], tmp);
                    }
                }

            }
            if(zmiana==1)
            {
                int tmp2;
                char tmp1[X];
                tmp2=pom2->ilosc;
                pom2->ilosc=pom1->ilosc;
                pom1->ilosc=tmp2;
                for(k=0;k<T;k++)
                {
                strcpy(tmp2, pom2 -> ang[k]);
                strcpy(pom2 -> ang[k],pom2 -> ang[k]);
                strcpy(pom2->ang[k], tmp2);
                }

            }
        }
        zmiana=0;
    }
    wypisz(*pierwszy,nazwa);
}
int comparestrings(const void *w1,const void *w2)
{
    const char *a=(char*)w1;
    const char *b=(char*)w2;
    return strcmp(a,b);
}
void menu()
{
    char nazwa1[X];
    int w;
    char nazwa[X];
    char slowodousuniecia[X],usang[X];
    printf("podaj nazwe pliku z rozszerzeniem .txt\n");
    gets(nazwa);
    fflush(stdin);
    ADRES pierwszy=odczyt(nazwa);
    if (pierwszy == NULL) return;
    int wybor= -1;
    do{
            ADRES pierwszy=odczyt(nazwa);
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
                printf("podaj nazwe pliku do ktorego chcesz zapisac wynik z rozszerzeniem .txt\n");
                fflush(stdin);
                gets(nazwa1);
                fflush(stdin);
                sortowanie(&pierwszy,nazwa1);
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
                printf("podaj slowo polskie ktore chcesz usunac (wraz z tlumaczeniami)\n");
                fflush(stdin);
                gets(slowodousuniecia);
                fflush(stdin);
                kasuj_element(&pierwszy,nazwa,slowodousuniecia);
                break;
            case 7:
                printf("podaj slowo angielskie ktore chcesz usunac\n");
                fflush(stdin);
                gets(usang);
                fflush(stdin);
                usuwanieang(pierwszy,nazwa,usang);
                break;
            case 8:
                return;
            default:
                printf("wybierz numer 1-8!\n");
                break;
            }
    } while (wybor!=8);
}
