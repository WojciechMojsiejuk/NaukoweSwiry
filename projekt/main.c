#include <stdio.h>
#include <stdlib.h>
#include "project.h"

int main()
{
    ADRES pierwszy=NULL;
    char nazwa[50];
    printf("podaj nazwe pliku z rozszerzeniem .txt\n");
    gets(nazwa);
    odczyt(&pierwszy,nazwa);
    menu();
    return 0;
}
