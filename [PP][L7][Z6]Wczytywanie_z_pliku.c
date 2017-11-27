#include <stdio.h>
#include<string.h>//dodalem biblioteke
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

    //rozwiazanie fscanf i fprintf
    printf("Rozwiazanie fscanf i fprintf\n\n");
    FILE * odczyt = stdout;
    while(fscanf(dane,"%s", zmienna[i])!=EOF)
    {
        int dl=strlen(zmienna[i]);
        dlugosc+=dl;
        fprintf(odczyt,"%s ", zmienna[i]); //w zadaniu mialo byc wyswietlone przy pomocy fprintf
        i++;
    }

    printf("\n\nRozwiazanie getc i putc\n\n");
    rewind(dane);
    int znak = getc(dane);
    while(znak!=EOF)
    {
        putc(znak,stdout);
        znak = getc(dane);
    }

    printf("\n\nRozwiazanie fgets i fputs\n\n");
    rewind(dane);
    char str[50];
    i=0;
    while(fgets(str,50,dane)!=NULL)
    {
        fputs(str,stdout);
    }

    printf("\n\nilosc znakow= %d \n", dlugosc);
    fclose(dane);
    return 0;
}
