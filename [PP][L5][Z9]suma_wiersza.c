#include <stdio.h>
#include <time.h>
#include<limits.h>
#define W 5
#define K 8

void wiersz(float tab[][K]);
int i, j;
float p,r;
int main()
{
    srand((unsigned)time(NULL));
    float tab[W][K];
    wiersz(*tab);
    return 0;
}

void wiersz(float tab[][K])
{
    int indeks_wiersza;
    float suma, suma_najwieksza=0.0;
    printf("Elementy tablicy to:\n");
    for (i=0;i<W;i++)
    {
        suma=0.0;
        for (j=0;j<K;j++)
        {
            tab[i][j]=((float)rand()/SHRT_MAX)*100;
            printf("%.2f\t", tab[i][j]);
            suma+=tab[i][j];
        }
        printf(" Suma: %.2f",suma);
        if (suma>suma_najwieksza)
        {
            suma_najwieksza=suma;
            indeks_wiersza=i;
        }
        printf("\n");
    }
    printf("indeks wiersza z najwieksza suma= %d", indeks_wiersza);
}
