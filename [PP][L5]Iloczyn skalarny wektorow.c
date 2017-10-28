#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main()
{
    srand((unsigned)(time(NULL)));
    float*tab, *tab2, il=0.0;
    int x, i;
    scanf("%d", &x);
    tab=(float*)malloc(x*sizeof(float));
    tab2=(float*)malloc(x*sizeof(float));
    for(i=0;i<x;i++)
    {
        tab[i]=(float)rand()/SHRT_MAX;
        tab2[i]=(float)rand()/SHRT_MAX;
        printf("%f %f\n", tab[i], tab2[i]);
        il+=tab[i]*tab2[i];
    }
    printf("%f", il);
    return 0;
}
