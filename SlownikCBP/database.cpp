#include "database.h"

///Read database and get ADRESS first
bool read_data(ADRESS &first)
{
    //Max size of one line
    char pom[(T+2)*X];

    //Auxiliary variable
    ADRESS temp2;

    //Amount of lines in database <not needed>
    int lines = 0;

	const char* name = "./data/database.txt";
	FILE*file = fopen(name, "r");
	if (!file)
	{
		perror(name);
		return false;
	}
	//Check if polish word was read
	bool f1 = false;
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
                //End of polish word
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
