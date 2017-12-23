#include "database.h"
#include "other.h"
#include "functions.h"

int main_loop()
{
    //number of lines
    int lines = 0;
    //Unique english words
    char tab[A][X]={0};
    //Number of occurence for each english word
    int amount[A]={0};

	ADRESS first = NULL;

	//Read database and get ADRESS first
	if(read_data(first, lines) == false)
    {
        std::cout << "Nie mozna wczytac bazy danych!\n\n";
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
                    std::cout<<"Blad\n";
                    return 1;
                }
				break;
			case 2:
			    if (choice_2(first, tab, amount) == false)
                {
                    std::cout<<"Blad\n";
                    return 2;
                }
                for (int i=0;i<A;i++)
                {
                    printf("%s ", tab[i]);
                }
                printf("\n");
				break;
			case 3:
			    if (choice_3(first, compare_strings) == false)
                {
                    std::cout<<"Blad\n";
                    return 3;
                }
				break;
			case 4:
			    if (choice_4(first) == false)
                {
                    std::cout<<"Blad\n";
                    return 4;
                }
				break;
			case 5:
			    std::cout<<"Blad\n";
				break;
			case 6:
			    char mystring[X];
			    read_string(mystring);
			    if (choice_6(first, mystring) == false)
                {
                    std::cout<<"Blad\n";
                    return 6;
                }
				break;
			case 7:
			    char mystring2[X];
			    read_string(mystring2);
			    if (choice_7(first, mystring2) == false)
                {
                    std::cout<<"Blad\n";
                    return 7;
                }
				break;
			default:
				std::cout << "Niepoprawny wybor!\n\n";
				break;
		}
	}while ( !quit );
    return 0;
}
