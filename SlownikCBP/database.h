#ifndef DATABASE_H_INCLUDED
#define DATABASE_H_INCLUDED

//cin cout
#include <iostream>
//fprintf
#include <stdio.h>
//qsort
#include <stdlib.h>
//strcpy, atrcmp
#include <string.h>

//Max amount of english words attached to polish word
#define T 5
//Max english word occurrence number to polish words
#define Z 10
//Max size of one word and file name
#define X 50
//Max amount of english words total
#define A 100

struct slowo_polskie
{
	char polish[X];
	char english[T][X];
	int quantity;
	slowo_polskie* next;
};

typedef struct slowo_polskie* ADRESS;

bool read_data(ADRESS &);

bool delete_data(ADRESS &);

#endif // DATABASE_H_INCLUDED
