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
    do//sortowanie b¹belkowe
    {
        zamiana=0;//przed ka¿dym "przejazdem" pêtli for zmienna zamiana jest zerowana
        for (i=0; i<dlugosc-1; i++)
        {
            if ((*zmienna).napis[i]>(*zmienna).napis[i+1])// jeœli element tablicy jest wiêkszy od nastêpnego elementu
            {
                zamiana++; //jeœli jest jakaœ zmiana, to zmienne zamiana powiêksza swoj¹ wartoœæ
                pom=(*zmienna).napis[i];//wartoœæ t[i] jest kopiowana do schowka
                (*zmienna).napis[i]=(*zmienna).napis[i+1];//t[i] przyjmuje wartoœæ nastêpnego elementu, gdy¿ jest on mniejszy
                (*zmienna).napis[i+1]=pom;//kolejny element tablicy przejmuje wczeœniejsz¹ wartoœæ poprzedniego elementu, gdy¿ jest on wiêkszy
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
