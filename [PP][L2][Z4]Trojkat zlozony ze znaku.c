#include <stdio.h>
int main(){
    printf("Program tworzy trojkat\nPodaj nieparzysta liczbe z przedzialu <3;79> znakow oraz znak: ");
    int liczba_znakow, liczba_spacji, i, j, pom=1;
    char zn;
    scanf("%d", &liczba_znakow);
    fflush(stdin);
    scanf("%c", &zn);
    do{
        liczba_spacji=liczba_znakow/2;
        for(i=0;i<liczba_spacji;i++){
            printf(" ");
        }
        for (j=pom;j>0;j--){
            printf("%c", zn);
        }
        printf("\n");
        pom+=2;
        liczba_znakow-=2;
    }while(liczba_znakow>0);
    return 0;
}
