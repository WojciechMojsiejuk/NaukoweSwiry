#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Napis_na_duze(char napis[])
{
    int i, dl=strlen(napis);
    for (i=0;i<dl;i++)
    {
        if (islower(napis[i]))
        {
            napis[i]=toupper(napis[i]);
        }
    }
    printf("%s\n", napis);
}

void Napis_na_male(char napis[])
{
    int i, dl=strlen(napis);
    for (i=0;i<dl;i++)
    {
        if (isupper(napis[i]))
        {
            napis[i]=tolower(napis[i]);
        }
    }
    printf("%s\n", napis);
}

void Zmiana_wielkosci(char napis[])
{
    int dl=strlen(napis), i;
    for (i=0;i<dl;i++)
    {
        if(isupper(napis[i]))
        {
            napis[i]=tolower(napis[i]);
        }
        else
        {
            napis[i]=toupper(napis[i]);
        }
    }
    printf("%s\n", napis);
}

void Lustrzane_odbicie(char napis[])
{
    char pom;
    int dl=strlen(napis), i=0, k;
    for (i=0;i<dl/2;++i)
    {
        pom=napis[i];
        napis[i]=napis[dl-1-i];
        napis[dl-1-i]=pom;
    }
    printf("%s\n", napis);
}

void wypisz_menu()
{
    printf("0) Wyjscie z programu\n"
    "1) Zamiana wszystkich znakow w napisie na duze litery\n"
    "2) Zamiana wszystkich znakow w napisie na male litery\n"
    "3) Zamiana malych liter napisu na duze, a duzych na male\n"
    "4) Lustrzane odbicie napisu\n"
    "5) Pozostawienie napisu bez zmian\n"
    "Podaj wybor: ");
}

int main(int argc, char* argv[])
{
    if (argc!=2)
    {
        printf("Niepoprawna ilosc argumentow!\n");
        return 1;
    }
    wypisz_menu();
    int choice;
    scanf("%d", &choice);
    //printf("%s", argv[1]);
    do{
        switch(choice)
            {
                case 0:
                    break;
                case 1:
                    Napis_na_duze(argv[1]);
                    break;
                case 2:
                    Napis_na_male(argv[1]);
                    break;
                case 3:
                    Zmiana_wielkosci(argv[1]);
                    break;
                case 4:
                    Lustrzane_odbicie(argv[1]);
                    break;
                case 5:
                    printf("%s", argv[1]);
                    break;
                default:
                    printf("Niepoprawny wybor!\n\n");
                    wypisz_menu();
                    scanf("%d", &choice);
                    break;
            }
        }while(choice<0 || choice >5);
        getchar();
        return 0;
}
