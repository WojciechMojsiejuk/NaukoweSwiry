/*
#include <stdio.h>
#include <string.h>
int main()
{
	int x=5,y=5;
	int a=1,b=0,c=-2;
	double z;
	char s[10]="egzamin",*w,c1='y';
	
	w=s+strlen(s)-3;
	printf("%c\n",*w);  //.....m
	
	z=(++y-(--x))%x;
	printf("%.11f\n",z); //......2.00000000000
	printf("%d\n",--s[2]==c1);
	
	z=x/y && !(x%++y);
	printf("%.21f\n",z);  //......0.000000000000000000000
	
	int t[10]={0,1,2};
	printf("%d\n", (2*(++t[2])<<2));  //......24
	printf("%d\n",a<b<c);  //......0
}
*/

//****************************************************************************************************

/*
#include <stdio.h>

int main(){
	char t[]="LADNA PANI";
	int i=6,j=1,k=5;
	while(i){
		for(j--;i!=j;i--){
			if(i-5) printf("%c %d %d\n", t[i],i,j);
			if(i==1) {
				for(;k>=i+4;k-=2); printf("%d",k);
			}
		}
	}
}
*/

//****************************************************************************************************

/*
#include<stdio.h>
int main(){
	char tekst[]="0123456789";
	int i=4,j=9;
	for(i++;i!=j;j-=1){
		printf("--%d \n",j-(tekst[i]-'0'));
		switch(tekst[++i-1])
		{
			case '9':printf("%c ",*(tekst+i));break;
			case '8':
				case '7':
				case '6':
				case '5':
				case '4':
				case '3':
				case '2':
				case '1':
				case '0': printf("-c-%c\n", *(tekst+j));break;
				default:break;
		}
	}
}
*/

//****************************************************************************************************

/*
#include<stdio.h>
int main(){
	char s[]="Proste zadanie!";
	int i=0;
	for(++i;*(s+i);i++);
	printf("%d",i);     //..............15
}
*/

//****************************************************************************************************

/*
#include<stdio.h>
	int x=3;
	void f1(int a)
	{
		printf("%d ",a++);
	}
	int f2(int y)
	{
		return ++y%x;
	}
	void f3(int *x,char *c)
	{
		printf("%c %i", *c+2,++*x);
	}
	int f4(int a,int y)
	{
		return a+--y;
	}
	
	int main(void){
		int b=7,y=8;
		char zn='s';
		f1(b);
		printf("%d ",b);
		printf("%d ",f2(y));
		printf("%d ",y);
		f3(&b,&zn);
		printf("%d ",b);
		printf("%d\n",f4(b,x));
		return 0;
	}
	*/
	
//****************************************************************************************************

/*
#include<stdio.h>
int main(){
	int z2=3, y=4, z1=8;
	char z[10]="egzamin";
	char a='c';
	double x;
	z1=y/z2;
	printf("%d ",z1);
	
	//z1= ....................
	a= (z[1]++ -a);
	printf("%d ",a);
	
	//a= .....................
	x=((z1++)-4)/(y-2);
	printf("%1f ",x);
	
	//x= .....................
	printf("%c", z[1]);
	
	//z[1]= .................
	z2=5; y=6;
	z1=(z2/4+y++)%4;
	
	printf("%d ",z1);
	
	//z1= ...................
	z1=(!(y+z2)) || (z2&&3);
	printf("%d ",z1);
	
	//z1= ...................
	x=(z1/6)*2.5-y%3;
	printf("%1f ",z);
	
	//z= .....................
}
*/


//****************************************************************************************************

/*
#include <stdio.h>
	int fA(int x){
		int w = x;
		printf("%d ",x);
		if (x>4) w+=fA(x-2);
		if (x>2) w+=fA(x-4);
		printf("%d ",x);
		return w;
	}
	
	int fB(int x){
		if (x<1) return 1;
		int w = x;
		if (w>2) w = w * fB(x-1);
		if (x>1) w = w + fA(x-1);
		
		return w;
	}
	
	int main(){
		printf("\n %d %d \n",fA(6),fB(3));
		return 0;
	}
*/


//****************************************************************************************************


/*

Dana jest dwuwymiarowa, dynamiczna tablica liczb ca³kowitych
(tablicaIn) o rozmiarze n na n.
Napisaæ funkcjê, która do jednowymiarowej tablicy wynikowej
(tablicaOut) wpisze sumy liczb
podzielnych przez k z kolejnych wierszy tablicy tablicaIn. Nastêpnie
funkcja ma stwierdziæ, czy w
tablicy wynikowej jakiekolwiek wartoœci siê powtarzaj¹ (zwracaj¹c
odpowiedni¹ wartoœæ logiczn¹).
Argumentami funkcji maj¹ byæ tablicaIn, n, k oraz tablicaOut. Zak³adamy,
¿e numerem wiersza w 
tablicy dwuwymiarowej jest jej pierwszy indeks

*/
