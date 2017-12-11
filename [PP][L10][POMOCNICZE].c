#include <stdio.h>
#include <stdlib.h>
#define N 10

//struktura do zadan 0-4

typedef struct element
{
    float x;
    struct element *nast;
}ELEMENT;
typedef ELEMENT *ADRES;

//struktura do zadania 5

typedef struct napis{
    char tab[N];
    struct napis *nast;
}NAPIS;
typedef NAPIS *ADRES_DO_NAPISU;

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
ADRES ostatni(ADRES pierwszy)
{
    if(pierwszy==NULL)
        return NULL;
    while(pierwszy->nast!=NULL)
    {
        pierwszy=pierwszy->nast;
    }
    return pierwszy;
}
ADRES poprzedni(ADRES pierwszy,ADRES biezacy)
{
    if(pierwszy==NULL)
        return NULL;
    ADRES pom = pierwszy;
    while(pom->nast!=biezacy)
    {
        pom=pom->nast;
        if(pom==NULL)
            return NULL;
    }
    return pom;
}
ADRES przedostatni (ADRES pierwszy)
{
    if(pierwszy==NULL||pierwszy->nast==NULL)
        return NULL;
    ADRES pom = pierwszy;
    while(pom->nast->nast!=NULL)
        pom=pom->nast;
    return pom;
}
ADRES przedostatni_alternatywa(ADRES pierwszy)
{
    ADRES pom=pierwszy;
    ADRES pom1=ostatni(pom);
    ADRES pom2=poprzedni(pom, pom1);
    return pom2;
}
void ostatni_i_poprzedzajacy(ADRES pierwszy, ADRES* ost, ADRES *pop)
{
    ADRES pom=pierwszy;
    *ost=ostatni(pom);
    *pop=poprzedni(pierwszy,*ost);
    
}
ADRES_DO_NAPISU dodaj_napis(char *s)
{
    ADRES_DO_NAPISU slowo;
    while(fprintf(ADRES_DO_NAPISU,"%s")
    {
        slowo=(ADRES_DO_NAPISU)malloc(sizeof(NAPIS));
        slowo->tab[N]=*s;
        slowo->nast=dodaj_napis(s+1)
    }
    ;
    napis->x=*s;

}
int czyistnieje(ADRES pierwszy)
{
    ADRES pom=pierwszy;
    while(pom)
    {
        return 0;
    }
}
int main()
{
    
    ADRES liczba=dodaj(5);
    
    printf("\n\nzadanie 0\n\n");
    
    ADRES Z0 = liczba;
    while(Z0)
    {
        printf("%f \n",Z0->x);
        Z0=Z0->nast;
    }
    printf("\n\nzadanie 1\n\n");
    
    ADRES Z1 = ostatni(liczba);
    printf("Adres ostatniego elementu przechowuje wartosc %f\n",Z1->x);
    
    printf("\n\nzadanie 2\n\n");
    
    ADRES Z2 = poprzedni(liczba, Z1);
    printf("Adres elementu poprzedzajacy Z1 przechowuje wartosc %f\n",Z2->x);
    
    printf("\n\nzadanie 3\n\n");
    
    ADRES Z3 = przedostatni(liczba);
    ADRES Z3_1 = przedostatni_alternatywa(liczba);
    printf("Adres elementu przedostatniego z listy przechowuje wartosc %f\n",Z3->x);
    printf("Adres elementu przedostatniego z listy przechowuje wartosc %f\n",Z3_1->x);
    
    printf("\n\nzadanie 4\n\n");
    
    ADRES ost=NULL;
    ADRES pop=NULL;
    ostatni_i_poprzedzajacy(liczba, &ost, &pop);
    printf("Adres ostatniego elementu przechowuje wartosc %f\n",ost->x);
    printf("Adres elementu przedostatniego z listy przechowuje wartosc %f\n",pop->x);
    
    printf("\n\nzadanie 5\n\n");
    //inicjalizacja listy
    ADRES_DO_NAPISU slowo;
    
    (*slowo)->tab="Ala ma kota, Kuba ma pierdolca";
    dodaj_napis(slowo);
    
    
    
}
