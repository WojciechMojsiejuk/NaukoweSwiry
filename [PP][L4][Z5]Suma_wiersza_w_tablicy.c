#include <stdio.h>
//#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define W 5
#define K 4

int main()
{
    srand((unsigned)time(NULL));
    int i, j, indeks_wiersza;
    float tab[W][K], suma, suma_najwieksza=-0.5;
    printf("Elementy tablicy to:\n");
    for (i=0;i<W;i++)
    {
        suma=0.0;
        for (j=0;j<K;j++)
        {
            tab[i][j]=(float)rand()/SHRT_MAX;
            printf("%f ", tab[i][j]);
            suma+=tab[i][j];
        }
        if (suma>suma_najwieksza)
        {
            suma_najwieksza=suma;
            indeks_wiersza=i;
        }
        printf("\n");
    }
    printf("indeks wiersza z najwieksza suma= %d", indeks_wiersza+1);
    return 0;
}
