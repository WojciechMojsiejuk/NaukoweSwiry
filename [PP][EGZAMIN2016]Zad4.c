#include <stdio.h>
#include <limits.h>
int* function (int tablica[],int n)
{
    int maxpoj=0;
    int i=0,j=0,k=0;
    int pojawienia[n][2];
    int pom1[n],pom2[n],tablicaOut[n];
    
    for(i=0;i<n;i++)
    {
        int liczbapoj=0;
        for(j=i;j<n;j++)
        {
            if(tablica[i]==tablica[j])
                liczbapoj++;
        }
        pojawienia[i][0]=liczbapoj;
        pojawienia[i][1]=tablica[i];
        if(liczbapoj>maxpoj)
            maxpoj=liczbapoj;
    }
    int najwiekszy=INT_MIN;
    for(i=0;i<n;i++)
    {
        printf("%d\n",tablica[i]);
        if(pojawienia[i][0]==maxpoj)
        {
            if(pojawienia[i][1]>najwiekszy)
                najwiekszy=pojawienia[i][1];
        }
    }
    j=0;k=0;
    for(i=0;i<n;i++)
    {
        if(tablica[i]<najwiekszy)
        {
            pom1[j]=tablica[i];
            j++;
        }
        else
        {
            pom2[k]=tablica[i];
            k++;
        }
    }
    for(i=0;i<j;i++)
        tablicaOut[i]=pom1[i];
    for(i=0;i<k;i++)
        tablicaOut[i]=pom2[i];
    return tablicaOut;
}
int main()
{
    int tablicaIn[]={4,5,7,1,5,9,4,5,3,4};
    int n = 10;
    printf("n = %d\n",n);
    int* wynik;
    wynik=function(tablicaIn, n);
    return 0;
}
