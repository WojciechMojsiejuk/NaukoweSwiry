#include <stdio.h>
//I fucking hate my life, and everyone hates me.
//I've found peace in knowing this.

int main()
{
    char nazwa[100]="[PP][L7][Z6]Wczytanie_z_pliku.txt";
    int i=0, dlugosc=0;
    char zmienna[50][100];//ilosc slow i dlugosc jednego slowa
    FILE*dane=fopen(nazwa, "r");
    if(!dane)
    {
        perror(nazwa);
        return -1;
    }
    while(fscanf(dane,"%s", zmienna[i])!=EOF)
    {
        int dl=strlen(zmienna[i]);
        dlugosc+=dl;
        printf("%s ", zmienna[i]);
        i++;
    }
    printf("\nilosc znakow= %d ", dlugosc);
    close(dane);
    return 0;
}
