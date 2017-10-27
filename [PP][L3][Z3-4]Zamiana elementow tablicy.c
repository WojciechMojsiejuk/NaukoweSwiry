#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    bool warunek=false;
    int i, n=10, pom=0, x=5;
    int *tab;
    tab = (int*) malloc (n * sizeof(int));
    for (i=0;i<n;i++){
        tab[i]=rand()%10;
        printf("%d ", tab[i]);
    }
    printf("\n");
    for (i=0;i<n/2;i++){
        pom=tab[i];
        tab[i]=tab[n-i-1];
        tab[n-i-1]=pom;
    }
    for (i=0;i<n;i++){
        printf("%d ", tab[i]);
        if (tab[i]==x) warunek=true;
    }
    if (warunek) printf("\nznaleziono x\n");
    free(tab);
    return 0;
}
