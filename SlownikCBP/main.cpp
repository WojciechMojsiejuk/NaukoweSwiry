// Slownik.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

#define T 5

void show_menu()
{
	std::cout << "0- Wyjdz z programu\n"
		"1- Wypisz wszystkie polskie slowa i wszystkie przyporzadkowane slowa angielskie\n"
		"2- Wypisz wszystkie angielskie oraz wszystkie przyporzadkowane im slowa polskie\n"
		"3- Posortuj alfabetycznie slowa polskie i ich angielskie odpowiedniki\n"
		"4- Wypisz slowa polskie z maksymalna liczba znaczen\n"
		"5- Wypisz wszystkie slowa angielskie najczesciej wystepujace oraz przyporzadkowane im slowa polskie\n"
		"6- Usun slowo polskie i jego angielskie odpowiedniki\n"
		"7- Usun slowo angielskie (jego wystapienia przy slowach polskich)\n";
};

struct slowo_polskie
{
	char polish[50];
	char english[T][50];
	int quantity;
	slowo_polskie* next;
};

typedef struct slowo_polskie* ADRESS;

bool read_data()
{
    //Max size of line
    char pom[2000];
    ADRESS first = NULL;
    ADRESS temp = NULL;
	const char* name = "../SlownikCBP/data/database.txt";
	FILE*file = fopen(name, "r");
	if (!file)
	{
		perror(name);
		return false;
	}
	//Czy polskie zostalo wczytane
	bool f1=false;
	//Lines counter
	int lines=0;
    //Words counter
	//int amount= 0;
	//Strlen of polish word
	int strlen_polish=0;
	//Strlen of english word
	int strlen_english=0;
    //Strlen of line
	int strlen_line=0;

    first = new slowo_polskie;

	while ( fgets(pom, sizeof pom, file)!= 0 )
	{
	    temp = new slowo_polskie;
        temp -> next = NULL;
        temp -> quantity = 0;
	    strlen_line=strlen(pom);
	    //printf("%d\n", pom2);

	    for(int i=0;i<strlen_line;i++)
        {
            if(pom[i]=='\0')
            {
                f1 = true;
                strlen_polish = 0;
                strlen_english = 0;
                temp -> quantity++;
            }
            if(pom[i]=='\n')
            {
                temp -> next = temp;
                //temp = new slowo_polskie;
                strlen_polish = 0;
                strlen_english = 0;
                f1 = false;
            }

            if( pom[i]!='\0' && pom[i]!='\n' && f1 == false)
            {
                temp -> polish[strlen_polish] = pom[i];
                strlen_polish++;
            }

            if( pom[i]!='\0' && pom[i]!='\n' && f1 == true)
            {
                temp -> english[first -> quantity - 1][strlen_english] = pom[i];
                strlen_english++;
            }
        }

        if (first == NULL)
        {
            first = temp;
        }

        printf("%s\t", temp -> polish);
        for (int i=0;i<temp -> quantity;i++)
        {
            printf("%s ", temp -> english[i]);
        }
        printf("\n");
        ++lines;
	    /*while( pom!='\n' )
        {
            pom=getc(file);
            if (pom != '\0')
            {
                first -> english[i][k]=pom;
                k++;
            }
            if (pom == '\0')
            {
                printf("%s", first -> english[i]);
                k=0;
                i++;
            }
        }
        first = first -> next;
        first = new slowo_polskie;
        //printf("\n");*/
    }
	return true;
};

bool open_file()
{
	char name[30];
	std::cout << "Podaj nazwe pliku: ";
	std::cin >> name;
	while (std::cin.fail())
	{
		std::cout << "Niepoprawna nazwa, podaj ponownie\n";
		std::cin.clear();
		std::cin.ignore(500, '\n');
		std::cin >> name;
	}
	FILE* file = fopen(name, "w");
	if (!file)
	{
		perror(name);
		return false;
	}
	return true;
};

bool choice_1()
{
	return true;
};

int main()
{
	//ADRESS first = NULL;

	if(read_data() == false)
    {
        return 1;
    }

	int choice = -1;
	bool quit = false;

	//Main loop
	do {
		show_menu();
		//check choice
		std::cin >> choice;
		while ( std::cin.fail() )
		{
			std::cout << "Podaj poprawny wybor!\n";
			std::cin.clear();
			std::cin.ignore(500, '\n');
			std::cin >> choice;
		}

		switch (choice)
		{
			//Quit
			case 0:
				quit = true;
				break;
			case 1:
				if (open_file() == false)
				{
					return 1;
				}

				std::cout << "Operacja zakonczona\n\n";

				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			default:
				std::cout << "Niepoprawny wybor!\n";
				break;
		}
	}while ( !quit );
    return 0;
}

