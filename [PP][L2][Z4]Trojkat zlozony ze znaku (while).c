#include<stdio.h>
int main()
{
    int p;
    char c;
    printf("Podaj dlugosc podstawy trojkata ");
    scanf("%d",&p);
    while (p%2==0 || p<3 || p>79)
    {
        printf("podaj nieparzysta wartosc z przedzialu 3, 79\n");
        scanf("%d",&p);
    }
        printf("podaj znak do wypisania ");
        scanf("\n%c",&c);
        int i=0;
        do{
            int j=(p-(2*i+1))/2;
            int k=0;
            int l=(p-(2*i+1))/2;
            do
            {
                if (j==0) break;
                printf(" ");
                j--;
            }while (j>0);
            do
            {
                printf("%c",c);
                k++;
            }while (k<(2*i+1));
            do
            {
                printf(" ");
                l--;
            }while (l>0);
            i++;
            printf("\n");
        }
        while (i<((p-1)/2)+1);
    return 0;
}
