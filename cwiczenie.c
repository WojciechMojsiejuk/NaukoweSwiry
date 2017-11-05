#include<stdio.h>
int main()
{
int a=1,b=2,c=3,d=4;
printf("a= %d b= %d c= %d d= %d\n",++a,b++,c--,--d);
printf("a= %d b= %d c= %d d= %d\n",a,b,c,d);

int e=a---b; //trzeba rozpatrzec dwa przypadki a-(--b) oraz (a--)-b
printf("a= %d b= %d e= %d\n",a,b,e);
int f=a-(--b);
printf("a= %d b= %d f= %d\n",a,b,f);
//int g=c-----d; nie zadziala
int g=(c--)-(--d);
printf("c= %d d= %d g= %d\n",c,d,g);
printf("d = %d\n",d);
printf("d= %d d= %d d= %d\n",d++,++d,++d); //Nie da sie przewidziec jak kompilator przeprowadzi operacje, nie uzywamy inkrementacji wiecej niz jeden raz
int h=10;
printf("h = %d h = %d\n",h++,h++); //Mozliwe rozwiaznia h=11 h=10 lub h=10 h=11
int x=5;
int y=5;
double z=(++y-(--x))%x; //(6-(5-1))%(4)
printf("z=%lf\n",z);
char z1='z', z2='y',z3='d';
while('f'-z3)
{
    char z4=z1--;
    char x=z1==z2;
    printf("x= %d z1= %c z2= %c z3= %c z4= %c\n",x,z1,z2,z3,z4);
    z3++;
}
z=1;
x=3%5;
y=5/2;
z=z&&!(x%++y);
printf("%lf",z);









return 0;
}
