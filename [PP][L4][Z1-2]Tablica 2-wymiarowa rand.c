#include <stdio.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL));
    int tab[100][100], i, j, a, b;
    scanf("%d%d", &a, &b);
    for (i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            tab[i][j]=rand()%10;
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    if(a==b)
    {

    }
    return 0;
}
