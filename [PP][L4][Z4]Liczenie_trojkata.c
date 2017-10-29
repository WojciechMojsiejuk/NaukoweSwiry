#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<limits.h>
#define N 5

int main()
{
	int i,j;
	float tab[N][N];
	float suma=0.0;
	srand((unsigned)time(NULL));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			tab[i][j]=((float)rand()/SHRT_MAX)*10;
			printf("%f  ",tab[i][j]);
		}
		printf("\n\n");
	}
	for(i=0;i<N;i++)
    {
        for(j=0;j<=i;j++)
        {
            suma+=tab[i][j];
        }
        printf("suma dla wiersza %d: %.2f\n",i+1,suma);
    }
    printf("Suma calkowita: %.2f",suma);


	return 0;
}
