#include <stdio.h>
#include <string.h>

int Czy_litera(int znak)
{
    if((znak>='A' && znak<='Z') || (znak>='a' && znak<='z'))
        return 1;
    else return 0;
}

int Czy_mala_litera(int znak)
{
    if(znak>='a' && znak<='z')
        return 1;
    else return 0;
}

int Czy_duza_litera(int znak)
{
    if(znak>='A' && znak<='Z')
        return 1;
    else return 0;
}

int Duza_na_mala(int znak)
{
    if(Czy_duza_litera(znak)==1)
    {
        int znak2=znak+32;
        return znak2;
    }
    else
    {
        return -1;
    }
}

int Mala_na_duza(int znak)
{
    if(Czy_mala_litera(znak)==1)
    {
        int znak2=znak-32;
        return znak2;
    }
    else
    {
        return -1;
    }
}

int Znak_w_stringu(const char* napis, int c)
{
    int i;
    int dl=strlen(napis);
    for(i=0;i<dl;i++)
    {
        if(napis[i]==c)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char znak='A', napis[100]="Ty no nie wiem jak tam twoja partnerka", znak1='o';
    printf("Nasz znak to: %c\n", znak);
    printf("Nasz napis to: %s\n", napis);
    int w=Czy_litera(znak);
    int w2=Czy_mala_litera(znak);
    int w3=Czy_duza_litera(znak);
    int w4=Duza_na_mala(znak);
    int w5=Mala_na_duza(znak);
    int w6=Znak_w_stringu(napis, znak1);
    printf("Czy litera= %d\nCzy mala= %d\nCzy duza= %d\nAdres pierwszego znaku '%c' w napisie '%s'= %d\n", w, w2, w3, znak1, napis, w6);
    printf("Kod ASCII dla malej= %d\nKod ASCII dla duzej= %d\n", w4, w5);
}
