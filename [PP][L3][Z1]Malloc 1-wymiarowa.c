#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL));
    int *tab, n, i;
    scanf("%d", &n);
    tab=(int*) malloc(n*sizeof(int));
    for (i=0;i<n;i++)
    {
        tab[i]=rand();
        printf("element nr %d to %d\n", i+1, tab[i]);
    }
    free(tab);
    return 0;
}
