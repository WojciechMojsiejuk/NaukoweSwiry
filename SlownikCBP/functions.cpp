#include "database.h"
#include "other.h"
#include "functions.h"

bool choice_1(ADRESS first)
{
    FILE* file=open_file();
    if (file == NULL)
        return false;
    if (first == NULL)
        return false;
    while(first != NULL)
    {
        fprintf(file, "%s: ", first -> polish );
        // i < T ??
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

bool choice_2(ADRESS first, char tab[][X])
{
    FILE* file=open_file();
    if (file == NULL)
        return false;
    if (first == NULL)
        return false;

    ADRESS temp = first, temp2 = first;

    //Get pom tab
    while(first != NULL)
    {
        for (int i=0;i<first -> quantity;i++)
        {
            char eng[X];
            strcpy(eng, first -> english[i]);
            //Check if eng was found in tab
            bool f1 = false;
            //A - Max amout of english words total
            for(int k=0; k<A; k++)
            {
                //If contest of both strings are equal
                if(strcmp(tab[k], eng) == 0)
                {
                    f1 = true;
                }
            }
            if (f1 == false)
            {
                for (int k=0;k<A;k++)
                {
                    //If tab[k] is empty, put english word
                    if (strcmp(tab[k], "\0")==0)
                    {
                        strcpy(tab[k], eng);
                        break;
                    }
                }
            }
        }
        first = first -> next;
    }
        //fprintf to file unique english words and attached polish words
        for (int i=0;i<A;i++)
        {
            temp = temp2;
            if (tab[i][0] != '\0')
            {
                fprintf(file, "%s: ", tab[i]);
                while (temp != NULL)
                {
                    for (int k=0;k<temp -> quantity;k++)
                    {
                    if (temp -> english[k][0] != '\0' && strcmp(tab[i], temp -> english[k]) == 0)
                    {
                        fprintf(file, "%s ", temp -> polish);
                    }
                }
                temp = temp -> next;
                }
                fprintf(file, "\n");
            }
        }
    std::cout << "Operacja zakonczona!\n\n";
	return true;
};

bool choice_3(ADRESS &first, int (*compare_strings)(const void*, const void*))
{
    FILE* file=open_file();
    if (file == NULL)
        return false;
    if (first == NULL)
        return false;
    ADRESS temp = first;

    //check if swap was made
    bool change;

    do
    {
        change = false;
        for (temp = first; temp -> next !=NULL; temp = temp -> next)
        {
            if(strcmp(temp -> polish, temp -> next -> polish)>0)
            {
                //Set flag
                change = true;
                //std::cout << temp -> polish << ' ' << temp -> next -> polish << '\n';
                char pom[X];
                strcpy(pom, temp -> polish);
                strcpy(temp -> polish, temp -> next -> polish);
                strcpy(temp -> next -> polish, pom);
                for (int i=0;i<T;i++)
                {
                    char pom2[X];
                    strcpy(pom2, temp -> english[i]);
                    strcpy(temp -> english[i], temp -> next -> english[i]);
                    strcpy(temp -> next ->english[i], pom2);
                }
                int pom3 = temp -> quantity;
                temp -> quantity = temp -> next -> quantity;
                temp -> next -> quantity = pom3;
            }
        }
    }while( change == true);

    //Sort english tab and printf to file
    temp = first;

    while (temp != NULL)
    {
        qsort(temp -> english, temp -> quantity, X*sizeof(char), compare_strings);
        fprintf(file, "%s: ", temp -> polish);
        for(int i=0;i<temp -> quantity;i++)
        {
            if(temp -> english[i][0] != '\0')
                fprintf(file,"%s ", temp -> english[i]);
        }
        fprintf(file, "\n");
        temp = temp -> next;
    }
    return true;
};

bool choice_4(ADRESS first)
{
    //If there is any word with max occurrence
    bool f1 = false;
    FILE* file=open_file();
    if (file == NULL)
        return false;
    if (first == NULL)
        return false;
    while(first != NULL)
    {
        //T - given
        if( first -> quantity == T)
        {
            f1 = true;
            fprintf(file, "%s\n", first -> polish);
        }
        first = first -> next;
    }
    if (f1 == false)
    {
        std::cout << "Nie ma slowa z maksymalna liczba znaczen\n";
    }
    std::cout << "Operacja zakonczona!\n\n";
	return true;
};

bool choice_5(ADRESS first, char tab[][X], int* amount)
{
    FILE* file=open_file();
    if (file == NULL)
        return false;
    if (first == NULL)
        return false;

    ADRESS temp = first, temp2 = first;

    //Get pom tab
    while(first != NULL)
    {
        for (int i=0;i<first -> quantity;i++)
        {
            char eng[X];
            strcpy(eng, first -> english[i]);
            //Check if eng was found in tab
            bool f1 = false;
            //A - Max amout of english words total
            for(int k=0; k<A; k++)
            {
                //If contest of both strings are equal
                if(strcmp(tab[k], eng) == 0)
                {
                    amount[k]++;
                    f1 = true;
                }
            }
            if (f1 == false)
            {
                for (int k=0;k<A;k++)
                {
                    //If tab[k] is empty, put english word
                    if (strcmp(tab[k], "\0")==0)
                    {
                        strcpy(tab[k], eng);
                        break;
                    }
                }
            }
        }
        first = first -> next;
    }
    //Get max element in amount table
    int maximum = amount[0];
    for (int i=1;i<A;i++)
    {
        if (amount[i]>maximum)
        {
            maximum = amount[i];
        }
    }

    //fprintf to file unique english words and attached polish words
    for (int i=0;i<A;i++)
    {
        temp = temp2;
        if (tab[i][0] != '\0' && amount[i] == maximum)
        {
            fprintf(file, "%s: ", tab[i]);
            while (temp != NULL)
            {
                for (int k=0;k<temp -> quantity;k++)
                {
                if (temp -> english[k][0] != '\0' && strcmp(tab[i], temp -> english[k]) == 0)
                {
                    fprintf(file, "%s ", temp -> polish);
                }
            }
            temp = temp -> next;
            }
            fprintf(file, "\n");
        }
    }
    std::cout << "Operacja zakonczona!\n\n";
	return true;
};

bool choice_6(ADRESS &first, char mystring[])
{
    //If mystring was found and removed
    bool removed = false;
    FILE* file=open_file();
    if (file == NULL)
        return false;
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
            if (temp2 -> english[i][0] != '\0')
            {
                fprintf(file, "%s ", temp2 -> english[i]);
            }
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
    //If any word was removed
    bool removedGlobal = false;
    //If actual word was removed
    bool removed = false;
    FILE* file=open_file();
    if (file == NULL)
        return false;
    if (first == NULL)
        return false;
    while(first != NULL)
    {
        fprintf(file, "%s: ", first -> polish);
        for (int i=0;i<first -> quantity;i++)
        {
            if ( strcmp(mystring, first -> english[i]) == 0)
            {
                strcpy(first -> english[i], "\0");
                removedGlobal = true;
                removed = true;
            }
            else
            {
                if (first -> english[i][0] != '\0')
                {
                    fprintf(file, "%s ", first -> english[i]);
                }
            }
        }
        //If word was found and removed
        if (removed == true)
        {
            first -> quantity--;
            removed = false;
        }
        first = first -> next;
        fprintf(file, "\n");
    }

    if ( removedGlobal == false)
    {
        std::cout << "Nie znaleziono slowa w bazie danych\n\n";
    }
    std::cout << "Operacja zakonczona!\n\n";
	return true;
};
