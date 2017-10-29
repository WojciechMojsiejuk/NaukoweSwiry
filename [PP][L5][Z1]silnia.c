#include<stdio.h>
int silnia(int n);
int main()
{
    int n;
    printf("Podaj n dla ktorego zostanie obliczona silnia: ");
    scanf("%d",&n);
    printf("Silnia z %d wynosi %d",n,silnia(n));
    return n;
}
int silnia(int n)
{
    int silnia=1;
    int i;
    for(i=1;i<=n;i++)
    {
        silnia*=i;
    }
    return silnia;
}
