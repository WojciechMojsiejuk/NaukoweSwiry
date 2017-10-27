#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#define N 3

int main()
{
    float suma=0.0;
    srand((unsigned)(time(NULL)));
    int i,j;
    float tab[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            tab[i][j]=(float)rand()/SHRT_MAX*10;
        }
    }
    for(i=0;i<N;i++)
    {
            suma+=tab[i][i]+tab[i][N-i-1];
            printf("suma= %f \n", suma);
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%.2f\t",tab[i][j]);
        }
        printf("\n");
    }
    if(N%2!=0)
        suma-=tab[N/2][N/2];
    printf("Suma przekatnych wynosi %f",suma);
    return 0;
}
