#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#include<string.h>
#define N 7
void zamiana(char **c,char **d)
{
    char *tmp;
        tmp=*c;
        *c=*d;
        *d=tmp;
}
int main ()
{
    char tab[2][N];
    int i;
    int a,b;
    for(a=0;a<N-1;a++)
    {
        for(b=a+1;b<N;b++)
        {
            if(strcmp(tab[a],tab[b])>0)
            {
                zamiana(tab[a],tab[b]);
            }
        }
    }
    for(i=0;i<2;i++)
    {
        printf("\n%s",tab[i]);
    }
    return 0;
}
