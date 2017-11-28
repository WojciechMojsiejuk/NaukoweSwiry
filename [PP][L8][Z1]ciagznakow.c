#include<stdio.h>
#include <string.h>
#define N 10
int dlugoscznaku(const char* napis)
{
    int i;
for(i=0;napis[i]!='\0';i++)
{
    ;
}

if(i!=N)--i;
return i;
}
int main (){
char t1[N+1],t2[N+1];
fgets(t1,N+1,stdin);
fflush(stdin);
printf("%s %d",t1,dlugoscznaku(t1));
fgets(t2,N+1,stdin);
fflush(stdin);
printf("%s %d",t2,dlugoscznaku(t2));
return 0;
}
