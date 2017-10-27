#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main()
{
    srand((unsigned)time(NULL));
    int n, i;
    float *tab;
    printf("Podaj liczbe elementow ");
    scanf("%d", &n);
    tab=(float*) malloc(n*sizeof(float));
    for (i=0;i<n;i++)
    {
        tab[i]=(float)rand()/SHRT_MAX;
        printf("%f ", tab[i]);
    }
    free(tab);
    return 0;
}
