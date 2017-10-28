#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    srand((unsigned)time(NULL));
    int *tab, n, i, k=1, min, max, suma=0, najblizsza, indeks_najblizszej, ilosc_mniejszych=0, srodkowy;
    float srednia=0, roznica=9999999.0;
    printf("Podaj liczbe elementow\n");
    scanf("%d", &n);
    tab = (int*) malloc (n * sizeof(int));
    printf("wylosowane elementy tablicy to: ");
    for (i=0;i<n;i++){
        if(i==0) {
            max=tab[i];
            min=tab[i];
        }
        tab[i]=rand()%100;
        printf("%d ", tab[i]);
        suma+=tab[i];
        if (tab[i]<min) min=tab[i];
        if (tab[i]>max) max=tab[i];
    }
    printf("\n");
    srednia=(float)suma/n;
    for (i=0;i<n;i++){
        if(fabs(srednia-tab[i])<roznica) {
            roznica=fabs(srednia-tab[i]);
            najblizsza=tab[i];
            indeks_najblizszej=i;
        }
    }
    for(i=0;i<n;i++){
        ilosc_mniejszych=0;
        for(k=1;k+i<n;k++){
            if(tab[i]>tab[i+k])
                ilosc_mniejszych++;
        }
        for(k=1;i-k>=0;k++){
            if(tab[i]>=tab[i-k])
                ilosc_mniejszych++;
        }
        //printf("ilosc dla liczby %d = %d\n", tab[i], ilosc_mniejszych);
        if(ilosc_mniejszych==n/2){
            srodkowy=tab[i];
            //printf("element srodkowy=%d\n", srodkowy);
            //printf("ilosc mniejszych=%d", ilosc_mniejszych);
            break;
        }
    }
    printf("max=%d min=%d suma=%d srednia=%f element sredni=%d indeks elementu sredniego=%d element srodkowy=%d", max, min, suma, srednia, najblizsza, indeks_najblizszej, srodkowy);
    free(tab);
    return 0;
}
