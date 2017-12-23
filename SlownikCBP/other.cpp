#include "database.h"
#include "other.h"

void show_menu()
{
	std::cout << "0- Wyjdz z programu\n"
		"1- Wypisz wszystkie polskie slowa i wszystkie przyporzadkowane slowa angielskie\n"
		"2- Wypisz wszystkie angielskie oraz wszystkie przyporzadkowane im slowa polskie\n"
		"3- Posortuj alfabetycznie slowa polskie i ich angielskie odpowiedniki\n"
		"4- Wypisz slowa polskie z maksymalna liczba znaczen\n"
		"5- Wypisz wszystkie slowa angielskie najczesciej wystepujace oraz przyporzadkowane im slowa polskie\n"
		"6- Usun slowo polskie i jego angielskie odpowiedniki\n"
		"7- Usun slowo angielskie (jego wystapienia przy slowach polskich)\n"
		"8- Wczytaj od nowa baze danych\n";
};

FILE* open_file()
{
	char _name[X];
	std::cout << "Podaj nazwe pliku: ";
	std::cin >> _name;
	while (std::cin.fail())
	{
		std::cout << "Niepoprawna nazwa, podaj ponownie\n";
		std::cin.clear();
		std::cin.ignore(500, '\n');
		std::cin >> _name;
	}
	char name[X+20];
	strcpy(name,"./output/");
	strcat(name,_name);
	FILE* file = fopen(name, "w");
	if (!file)
	{
		perror(name);
		return NULL;
	}
	return file;
};

char* read_string(char mystring[])
{
    std:: cout << "Podaj napis: ";
    std::cin >> mystring;
    while ( std::cin.fail() )
    {
        std::cout << "Podany napis jest niepoprawny!\n";
        std::cin.clear();
        std::cin.ignore(500, '\n');
        std::cin >> mystring;
    }
    return mystring;
};

int compare_strings (const void* element, const void* element2)
{
    char* temp = (char*)element;
    const char* temp2 = (char*)element2;
    return strcmp(temp, temp2);
};

ADRESS previous(ADRESS first, ADRESS temp)
{
    if(first == NULL)
        return NULL;
    while( first -> next != NULL)
        first = first -> next;
    return first;
};

ADRESS next(ADRESS first, ADRESS temp)
{
    if (first == NULL)
        return NULL;
    if (temp -> next == NULL)
        return NULL;
    return temp -> next;
};
