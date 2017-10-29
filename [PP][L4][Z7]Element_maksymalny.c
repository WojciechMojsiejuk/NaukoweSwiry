#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#define W 5
#define K 8
int main()
{
    int i,j;
    int max=0;
    int index[1][2];
    int tab[W][K];
    srand((unsigned)time(NULL));
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            tab[i][j]=rand()*100/SHRT_MAX;
            printf("%d\t",tab[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<W;i++)
    {
        for(j=0;j<K;j++)
        {
            if(tab[i][j]>max)
            {
                max=tab[i][j];
                index[0][0]=i+1;
                index[0][1]=j+1;
            }
        }
    }

    printf("Wartosc max: %d znaduje sie pod indeksem %d:%d",max,index[0][0],index[0][1]);
    return 0;
}
