#include <stdio.h>
#define N 10
int main (){
    char t1[N+1];
    fgets(t1,N+1,stdin);
    fputs(t1,stdout);
    fflush(stdin);
return 0;
}
