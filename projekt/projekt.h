#ifndef PROJEKT_H_INCLUDED
#define PROJEKT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define T 10
#define X 50
struct slowopl
{
    char pl[X];
    char ang[X][T];
    int ilosc;
    struct slowopl* nast;

};
typedef struct slowopl* ADRES;
typedef struct slowopl SlowoPL;
void menu();
ADRES odczyt();
void wypisz();
void maxznaczen();
void kasuj_element();

#endif // PROJEKT_H_INCLUDED
