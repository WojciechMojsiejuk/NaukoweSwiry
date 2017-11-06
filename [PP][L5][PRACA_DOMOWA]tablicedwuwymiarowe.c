#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define W 4
#define K 4
void uzupelnij(int tab[][K]);
void wyswietl(int tab[][K]);
int minimum(int tab[][K]);
void wspolrzedniemin(int tab[W][K],int min);
int ile_elementow_potrzeba(int tab[W][K],int suma);
void transpozycja(int tab[][K]);
int suma_elementow(int tab[][K],int wiersz);
int suma_elementow_xx_yy(int tab[][K],int x, int y, int xx, int yy);

int main()
{
int tab[W][K];
uzupelnij(tab);
wyswietl(tab);
int min = minimum(tab);
printf("\nNajmniejszy element w tablicy wynosi %d\n", min);
wspolrzedniemin(tab,min);
int suma = 20;
printf("\nPotrzeba %d elemenetow by przekroczyc %d\n",ile_elementow_potrzeba(tab,suma),suma);
transpozycja(tab);
printf("Suma elementow wynosi %d \n",suma_elementow(tab,2));//przyjmowane sa wartosci od 1 do W
printf("\nSuma elementow w prostokacie wynosi %d \n",suma_elementow_xx_yy(tab,2,2,1,0));//przyjmowane sa wartosci od 1 do W
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
            //printf("element %d tablicy = %d suma laczna= %d\n", j, tab[i][j], s);
            if(s>suma)
                return licznik;
        }
    }
    printf("Nie udalo sie uzebrac odpowiedniej ilosci przekraczajacej sumy");
    return 1;
}
void transpozycja(int tab[][K])
{
    int i,j;
    if(W!=K)
        {
            printf("Transpozycja niemozliwa\n");
            return 2;
        }
    int tab2[W][K];
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
           tab2[j][i]=tab[i][j];
        }
    }
wyswietl(tab2);
}
int suma_elementow(int tab[][K],int wiersz)
{
    int i,j;
    int suma=0;
    if(W!=K)
        {
            printf("Tablica musi byc kwadratowa\n");
            return 3;
        }
    for(i=0;i<wiersz;i++)
    {
        for(j=0;j<=i;j++)
        {
           suma+=tab[i][j];
           //printf("\nsuma=%d",suma);
        }
    }
    for(i=wiersz-1;i<W;i++)
    {
        for(j=i;j<K;j++)
        {
           suma+=tab[i][j];
           //printf("\nsuma=%d",suma);
        }
    }
    suma-=tab[wiersz-1][wiersz-1];
return suma;
}
int suma_elementow_xx_yy(int tab[][K],int x, int y,int xx, int yy)
{
    if(W%y!=0||K%x!=0)
        {
            printf("Nie da podzielic sie tablicy\n");
            return 4;
        }
    int suma=0;
    int i,j;
    int wiersz=W/y;
    int kolumna=K/x;
    for(i=xx*wiersz;i<(xx+1)*wiersz;i++)
    {
        for(j=yy*kolumna;j<(yy+1)*kolumna;j++)
        {
           suma+=tab[i][j];
           printf("\nsuma = %d",suma);
        }
    }
    return suma;
}
