#include <stdio.h>
#include <stdlib.h>
typedef struct element
{
    int x;
    struct element *nast;
}ELEMENT;

typedef ELEMENT *ADRES;
ADRES dodaj(int n)
{
    int i=0;
    ADRES liczba=NULL;
    liczba=(ADRES)malloc(sizeof(ELEMENT));
    liczba->x=i;
    ADRES pom = liczba;
    for(i=0;i<n;i++)
    {
        pom->nast=(ADRES)malloc(sizeof(ELEMENT));
        pom=pom->nast;
        pom->x=i+1;
    }
    pom->nast=NULL;
    return liczba;
}
int main()
{
    
    ADRES liczba=dodaj(5);
    while(liczba)
    {
        printf("%d",liczba->x);
        liczba=liczba->nast;
    }
    
}
