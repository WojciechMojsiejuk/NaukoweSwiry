#include <stdio.h>
int main(){
    int ilosc, i, ile, j, k, pom=0;
    scanf("%d", &ilosc);
    for (i=0;i<ilosc;i++){
        ile=0;
        pom++;
        for (j=pom;j>0;j--){
            printf("a");
            ile++;
        }
        for (k=ilosc-ile;k>0;k--){
            printf("b");
        }
        printf("\n");
    }
    return 0;
}

