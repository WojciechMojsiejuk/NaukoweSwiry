#include <stdio.h>
int main(){
    int i, k;
    for (i=0;i<20;i++){
        printf("1");
        for (k=i;k>=0;k=k-1){
            printf("0");
        }
        printf("\n");
    }
}
