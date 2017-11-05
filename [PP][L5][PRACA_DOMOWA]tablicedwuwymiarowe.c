#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define W 3
#define K 4
void uzupelnij(int tab[][K]);
void wyswietl(int tab[][K]);
int minimum(int tab[][K]);
void wspolrzedniemin(int tab[W][K],int min);
int ile_elementow_potrzeba(int tab[W][K],int suma);

int main()
{
int tab[W][K];
uzupelnij(tab);
wyswietl(tab);
int min = minimum(tab);
printf("Najmniejszy element w tablicy wynosi %d\n", min);
wspolrzedniemin(tab,min);
int suma = 20;
printf("Potrzeba %d elemenetow by przekroczyc %d",ile_elementow_potrzeba(tab,suma),suma);
return 0;
}
void uzupelnij(int tab[][K])
{
    srand((unsigned)time(NULL));
    int i,j;
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            tab[i][j]=(rand()%10)+1;
        }
    }
}
void wyswietl(int tab[][K])
{
    int i,j;
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            printf("%d\t",tab[i][j]);
        }
        printf("\n");
    }
}
int minimum(int tab[][K])
{
    int i,j;
    int min=tab[0][0];
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            if(tab[i][j]<min)
                min=tab[i][j];
        }
    }
    return min;
}
void wspolrzedniemin(int tab[][K],int min)
{

    int i,j;
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            if(tab[i][j]==min)
                printf("Element min= %d znajduje sie w tablicy na wspolrzednych i = %d j= %d\n",min,i,j);
        }
    }
}
int ile_elementow_potrzeba(int tab[][K],int suma)
{
    int i,j;
    int s=0, licznik = 0;
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            licznik++;
            s+=tab[i][j];
            printf("element %d tablicy = %d suma laczna= %d\n", j, tab[i][j], s);
            if(s>suma)
                return licznik;
        }
    }
    printf("Nie udalo sie uzebrac odpowiedniej ilosci przekraczajacej sumy");
    return 1;
}
