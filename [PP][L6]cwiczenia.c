#include<stdio.h>
//Cwiczenie 2
/*int minimum (int a, int b)
{
    return(a<b?a:b);
}
int main()
{
    printf("%d",minimum(2,3));
}*/

//Cwiczenie 3
/*
//2
void P(int *x)
{
    *x+=10;
    printf("%d ",*x);
}
int main(void)
{
    int a=1;
    P(&a);
    printf("%d",a);
    return 0;
}*/
//3
/*
int x=0;
void P(void)
{
    x+=10;
    printf("%d ",x);
}
int main(void)
{
    int x=10;
    P();
    printf("%d",x);
    return 0;
}
*/
//4
/*
int x=0;
void P(void)
{
    int x=100;
    x+=1;
    printf("%d ",x);
}
int main(void)
{
    int x=10;
    P();
    printf("%d",x);
    return 0;
}
*/
//5
/*
int x;
void P(int x)
{
    x+=100;
    printf("%d ",x);
}
int main(void)
{
    x=10;
    int a=77;
    P(a);
    printf("%d ",x);
    printf("%d",a);
    return 0;
}
*/
//6
/*
int a;
void P(int x)
{
    x+=100;
    printf("%d ",x);
}
int main(void)
{
    int x=10;
    int a=77;
    P(a);
    printf("%d ",x);
    printf("%d",a);
    return 0;
}*/
//7
/*
int x;
void P(int *x)
{
    *x+=100;
    printf("%d ",*x);
}
int main(void)
{
    x=10;
    int a=77;
    P(&a);
    printf("%d ",x);
    printf("%d",a);
    return 0;
}*/
//8
/*
void P(int x)
{
    int x=10;
    printf("%d ",x);
}
int main(void)
{
    int a=77;
    P(a);
    printf("%d",a);
    return 0;
}
*/
int silnia(int n){
    if(n<=0)
        return 1;
    return n*silnia(n-1);
    }
int fibonacci(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}
float zad3(float a)
{
    if(a==1)
        return 1;
    else
        return(1/(zad3(a-1)+1));
}
float zad4(float a)
{
    if(a==1)
        return 1;
    else
        return((zad3(a-1)+1)/(zad3(a-1)+2));
}
float pierwiastek(float a)
{
    if(a==1)
    {
        return a/2;
    }
    else
    {
        return 1/3*(2*pierwiastek(a-1)+(a/(pierwiastek(a-1)*pierwiastek(a-1))));
    }
}
void Funkcja(int a, const int *b)
{
    if(!a)
    {
        printf("%d",b[0]);
        return;
    }
    int *c=b;
    if(a%4==0)
    {
        printf("%d %d",b[0],b[1]);
        c+=2;
    }
    Funkcja(a/2,c);
    printf("%d",b[a%4]);
}
void F(int n)
{
    if(n>10)
    {
        F(n-10);
        return;
    }
    if(n<0)
    {
        printf("A ");
        return;
    }
    printf("%d ",n);
    F(n-1);
    printf("%d", n+1);
}
int main()
{
    int n=2;
    printf("silnia z n = %d wynosi %d\n",n,silnia(n));
    int i;
    for (i=0;i<n;i++)
        printf("%d ",fibonacci(i));
    printf("zad3 = %f\n",zad3(n));
    printf("zad4 = %f\n",zad4(n));
    float a=8;
    printf("pierwiastek z %f = %f\n\n",a,pierwiastek(a));
    int tab[]={2,4,6,8};

    printf("Zadanie6\n");
    Funkcja(13,tab);
    printf("\nZadanie7\n");
    F(13);
}
