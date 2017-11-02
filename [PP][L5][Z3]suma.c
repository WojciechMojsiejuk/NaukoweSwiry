#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#define N 5

float suma(float tab[N][N]);
int main()
{
    int i,j;
    float tab[N][N];
    srand((unsigned)time(NULL));
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            tab[i][j]=((float)rand()/SHRT_MAX)*100;
            printf("%.2f\t",tab[i][j]);
        }
        printf("\n");
    }
    printf("\n\nSuma wynosi %.2f",suma(tab));
    return 0;
}
float suma(float tab[N][N])
{
    int i,j;
    float p=0.0;
    float *suma;
    suma = &p;
    printf("\n\n\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            *suma+=tab[i][j];
            printf("%.2f\t",*suma);
        }
        printf("\n");
    }
    return *suma;
}
