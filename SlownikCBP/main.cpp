// Slownik.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <stdio.h>
#include <string.h>

//Max amout of english words attached to polish word
#define T 5
//Max amout of english words total and max english word occurrence number to polish words
#define Z 100
//Max size of one word and file name
#define X 50
//Max size of one line
#define K 200

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
	char polish[X];
	char english[T][X];
	int quantity;
	slowo_polskie* next;
};

typedef struct slowo_polskie* ADRESS;

///Read database and get ADRESS first
bool read_data(ADRESS &first)
{
    //Max size of one line
    char pom[K];

    //Auxiliary variable
    ADRESS temp2;

	const char* name = "./data/database.txt";
	FILE*file = fopen(name, "r");
	if (!file)
	{
		perror(name);
		return false;
	}
	//Check if polish word was read
	bool f1 = false;
	//Lines counter
	int lines = 0;
	//Strlen of polish word
	int strlen_polish = 0;
	//Strlen of english word
	int strlen_english = 0;
    //Strlen of line
	int strlen_line = 0;

	while ( fgets(pom, sizeof(pom), file)!= 0 )
	{
	    ADRESS temp = new slowo_polskie;

        temp -> quantity = 0;
	    strlen_line=strlen(pom);
	    strlen_polish = 0;
	    strlen_english = 0;

	    for(int i=0;i<strlen_line;i++)
        {
            if(pom[i]==' ')
            {
                f1 = true;
                //End of polish word!
                temp -> polish[strlen_polish]='\0';

                strlen_english = 0;

                temp -> quantity++;
            }

            if(pom[i]=='\n')
            {
                f1 = false;
            }

            if( pom[i]!=' ' && pom[i]!='\n' && f1 == true)
            {
                temp -> english[temp -> quantity - 1][strlen_english] = pom[i];
                strlen_english++;
            }

            if( pom[i]!=' ' && pom[i]!='\n' && f1 == false)
            {
                temp -> polish[strlen_polish] = pom[i];
                strlen_polish++;
            }
        }
	    if (first == NULL)
        {
            first = temp;
        }
        else
        {
            temp2 = first;
            while(temp2 -> next)
            {
                temp2 = temp2 -> next;
            }
            temp2 -> next = temp;
            temp -> next = NULL;
        }
        ++lines;
	}
	return true;
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

bool choice_1(ADRESS first)
{
    FILE* file=open_file();
    if (first == NULL)
        return false;
    while(first != NULL)
    {
        fprintf(file, "%s: ", first -> polish );
        for (int i=0;i<first -> quantity;i++)
        {
            if(strcmp(first -> english[i],"\0")!=0)
                fprintf(file, "%s ", first -> english[i]);
        }
        fprintf(file, "\n");
        first = first -> next;
    }
    std::cout << "Operacja zakonczona!\n\n";
	return true;
};

//Not done
bool choice_2(ADRESS first, char tab[][X], int* amount)
{
    FILE* file=open_file();
    if (first == NULL)
        return false;
    while(first != NULL)
    {
        for (int i=0;i<first -> quantity;i++)
        {
            char* eng = first -> english[i];
            //Check if eng was found in tab
            bool f1 = false;
            //Z - Max amout of english words total
            for(int k=0; k<Z; k++)
            {
                //If contest of both strings are equal
                if(strcmp(tab[k], eng) == 0)
                {
                    printf("Rowne ");
                    amount[k]++;
                    printf("ilosc= %d\n", amount[k]);
                    f1 = true;
                }
            }
            if (f1 == false)
            {
                printf("Nie rowne\n");
                for (int k=0;k<Z;k++)
                {
                    //If tab[k] is empty
                    if (strcmp(tab[k], "\0")==0)
                    {
                        strcpy(tab[k], eng);
                    }
                }
            }
        }
        first = first -> next;
    }
    std::cout << "Operacja zakonczona!\n\n";
	return true;
}

bool choice_4(ADRESS first)
{
    FILE* file=open_file();
    if (first == NULL)
        return false;
    while(first != NULL)
    {
        //T - given
        if( first -> quantity == T)
        {
            fprintf(file, "%s\n", first -> polish);
        }
        first = first -> next;
    }
    std::cout << "Operacja zakonczona!\n\n";
	return true;
};

bool choice_6(ADRESS &first, char mystring[])
{
    //If mystring was found and removed
    bool removed = false;
    FILE* file=open_file();
    if (first == NULL)
        return false;
    //if first element
    if( strcmp(mystring, first -> polish) == 0)
    {
        ADRESS temp = first;
        first = first -> next;
        delete temp;
        removed = true;
    }
    //auxiliary variable
    ADRESS temp2 = first;

    ADRESS temp3;

    while(temp2)
    {
        if (temp2 -> next != NULL)
        {
            temp3 = temp2 -> next;
        }
        if (strcmp( temp3-> polish, mystring) == 0)
        {
            temp2 -> next = temp3 -> next;
            delete temp3;
            removed = true;
        }

        fprintf(file, "%s: ", temp2 -> polish );
        for (int i=0;i<temp2 -> quantity;i++)
        {
            fprintf(file, "%s ", temp2 -> english[i]);
        }
        fprintf(file, "\n");
        temp2 = temp2 -> next;
    }
    if (removed ==  false)
    {
        std::cout << "Nie znaleziono slowa w bazie danych\n\n";
        return true;
    }
    std::cout << "Operacja zakonczona!\n\n";
	return true;
};

bool choice_7(ADRESS first, char mystring[])
{
    bool removed = false;
    FILE* file=open_file();
    if (first == NULL)
        return false;
    while(first != NULL)
    {
        fprintf(file, "%s ", first -> polish);
        for (int i=0;i<first -> quantity;i++)
        {
            if ( strcmp(mystring, first -> english[i]) == 0)
            {
                strcpy(first -> english[i], "\0");
                removed = true;
                first -> quantity--;
            }
            else
            {
                fprintf(file, "%s ", first -> english[i]);
            }
        }
        first = first -> next;
        fprintf(file, "\n");
    }
    if ( removed == false)
    {
        std::cout << "Nie znaleziono slowa w bazie danych\n\n"
;    }
    std::cout << "Operacja zakonczona!\n\n";
	return true;
};

int main()
{
    //Unique english words
    char tab[Z][X]={0};
    //Number of occurence for each english word
    int amount[Z]={0};

    for (int i=0;i<Z;i++)
    {
        printf("%s", tab[i]);
    }

	ADRESS first = NULL;

	//Read database and get ADRESS first
	if(read_data(first) == false)
    {
        return -1;
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
                if (choice_1(first) == false)
                {
                    return 1;
                }
				break;
			case 2:
			    if (choice_2(first, tab, amount) == false)
                {
                    return 2;
                }
                for (int i=0;i<Z;i++)
                {
                    printf("%s ", tab[i]);
                }
                printf("\n");
				break;
			case 3:
				break;
			case 4:
			    if (choice_4(first) == false)
                {
                    return 4;
                }
				break;
			case 5:
				break;
			case 6:
			    char mystring[X];
			    read_string(mystring);
			    if (choice_6(first, mystring) == false)
                {
                    return 6;
                }
				break;
			case 7:
			    char mystring2[X];
			    read_string(mystring2);
			    if (choice_7(first, mystring2) == false)
                {
                    return 7;
                }
				break;
			default:
				std::cout << "Niepoprawny wybor!\n";
				break;
		}
	}while ( !quit );
    return 0;
}
