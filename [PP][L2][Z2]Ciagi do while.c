#include <stdio.h>
int main(){
    int i=0, j=0;
    do{
        j=i;
        printf("1");
        do{
            printf("0");
            j--;
        }while(j>=0);
        printf("\n");
        i++;
    }while(i<20);
    return 0;
}
