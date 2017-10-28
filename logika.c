#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#define N 4 //ilosc zmiennych

int main()
{
    //Uzywam zmiennej przechowujacej liczby z zakresu od 0 do +18,446,744,073,709,551,615
    unsigned long long input_options = pow(2,N);
    unsigned long long output_options = pow(2,input_options);
    printf("%llu %llu ",input_options, output_options);
    bool **tab;
    int i,j;
    tab = (bool**)malloc(output_options*sizeof(bool*));
    for (i=0; i<output_options; i++)
        tab[i] = (bool*)malloc(input_options*sizeof(bool));

    for (i=0; i<output_options; i++)
        for (j=0; j<input_options; j++)
            tab[i][j]=true;
    for (i=0; i<output_options; i++)
 {
/*wypisuje wierszami operacje logiczne, 1 wiersz to jedna kombinacja wejsciowa i odpowiadajaca im liczba operacji wyjsciowych
wartosci przypisane jako operacje maja tylko wartosc jeden ze wzgl na komplikacje programu
Program wiec nie symuluje prawdziwego przypisania, ale obrazuje ile takich obliczen powinno zostac wykonanych 2^(kombinacji wejsciowych) <=> 2^(2^(liczba zmiennych))
*/
     for (j=0; j<input_options; j++)
            printf("%d",tab[i][j]);
        printf("\n");
}


return 0;
}

