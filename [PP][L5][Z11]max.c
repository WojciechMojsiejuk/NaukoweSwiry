#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include<limits.h>
#define W 5
#define K 8

void max(float tab[][K]);
int main()
{
    srand((unsigned)time(NULL));
    float tab[W][K];
    max(*tab);
    return 0;
}

void max(float tab[][K])
{
    int i,j;
    float p;
    float max=0.0;
    int indexx,indexy;
    srand((unsigned)time(NULL));
    for (i=0;i<W;i++)
    {
        for (j=0;j<K;j++)
        {
            tab[i][j]=((float)rand()/SHRT_MAX)*100;
            printf("%.2f\t", tab[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            p=tab[i][j];
            if(p>max)
            {
                max=p;
                indexx=i;
                indexy=j;
            }
        }
    }

    printf("Wartosc max: %.2f znaduje sie pod indeksem %d:%d",max,indexx,indexy);
}
