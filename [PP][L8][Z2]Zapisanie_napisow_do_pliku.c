#include <stdio.h>
#include <stdlib.h>
#define N 3
#define MAX 15

int main()
{
    char tablica[N][MAX+1];
    char nazwa[]="out.txt";
    int i, j;
    char a;
    for(i=0, j=0;i<N;)
    {
        a=getchar();
        if(a!='\n')
        {
            if(j!=MAX)
            {
                tablica[i][j]=a;
                j++;
            }
        }
        else
        {
            tablica[i][j]='\0';
            i++;
            j=0;
        }
    }

    /*for(i=0;i<N;i++)
    {
        for(j=0;tablica[i][j]!='\0';j++)
        {
            printf("%c", tablica[i][j]);
        }
        printf("\n");
    }*/

    FILE *plik;
    plik=fopen(nazwa, "w+");
    for(i=0, j=0;i<N;)
    {
        if(tablica[i][j]!='\0')
        {
            fputc(tablica[i][j], plik);
            j++;
        }
        else
        {
            fputc('\n', plik);
            i++;
            j=0;
        }
    }

    return 0;
}
