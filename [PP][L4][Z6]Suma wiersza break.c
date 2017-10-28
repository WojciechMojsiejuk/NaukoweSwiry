#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define W 20
#define K 5

int main()
{
    srand((unsigned)time(NULL));
    int i, j, indeks_wiersza;
    float tab[W][K], suma[W], suma_najwieksza=-0.5;
    printf("Elementy tablicy to:\n");
    for (i=0;i<W;i++)
    {
        suma[i]=0.0;
        for (j=0;j<K;j++)
        {
            tab[i][j]=rand()%2;
            printf("%f ", tab[i][j]);
            suma[i]+=tab[i][j];
        }
        printf("\n");
    }
    for(i=0;i<W;i++)
    {
        if(suma[i]>suma_najwieksza)
        {
            suma_najwieksza=suma[i];
        }
    }
    for(i=0;i<W;i++)
    {
        if(suma[i]==suma_najwieksza)
        {
            printf("\nindeks= %d suma= %f\n", i, suma[i]);
        }
    }
    return 0;
}
