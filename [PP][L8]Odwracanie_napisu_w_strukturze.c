#include <stdio.h>
#include <string.h>

typedef struct
{
    char napis[20];
    int dl;
}NAPISY;

char* odwracanie_napisu(NAPISY *zmienna)
{
    int i, zamiana=0, dlugosc=strlen((*zmienna).napis);
    char pom;
    do//sortowanie b�belkowe
    {
        zamiana=0;//przed ka�dym "przejazdem" p�tli for zmienna zamiana jest zerowana
        for (i=0; i<dlugosc-1; i++)
        {
            if ((*zmienna).napis[i]>(*zmienna).napis[i+1])// je�li element tablicy jest wi�kszy od nast�pnego elementu
            {
                zamiana++; //je�li jest jaka� zmiana, to zmienne zamiana powi�ksza swoj� warto��
                pom=(*zmienna).napis[i];//warto�� t[i] jest kopiowana do schowka
                (*zmienna).napis[i]=(*zmienna).napis[i+1];//t[i] przyjmuje warto�� nast�pnego elementu, gdy� jest on mniejszy
                (*zmienna).napis[i+1]=pom;//kolejny element tablicy przejmuje wcze�niejsz� warto�� poprzedniego elementu, gdy� jest on wi�kszy
            }
        }
    }
    while(zamiana!=0);
    return (*zmienna).napis;
}

int main()
{
    char napis2[20];
    NAPISY n1, n2, n3;
    strcpy(n1.napis, "bdhagabchcdacdabhdc");
    n1.dl=strlen(n1.napis);
    printf("%s\n", n1.napis);
    strcpy(napis2, odwracanie_napisu(&n1));
    printf("%s\n", napis2);
    return 0;
}
