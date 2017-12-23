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

//Not done
bool choice_2(ADRESS first, char tab[][X], int* amount)
{
    FILE* file=open_file();
    if (file == NULL)
        return false;
    if (first == NULL)
        return false;
    while(first != NULL)
    {
        for (int i=0;i<first -> quantity;i++)
        {
            char* eng = first -> english[i];
            //Check if eng was found in tab
            bool f1 = false;
            //A - Max amout of english words total
            for(int k=0; k<A; k++)
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
                for (int k=0;k<A;k++)
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

//    while( temp != NULL && temp -> next != NULL)
//    {
//        if(strcmp(temp -> polish, temp -> next -> polish)>0)
//        {
//            std::cout << temp -> polish << ' ' << temp -> next -> polish << '\n';
//            char pom[X];
//            strcpy(pom, temp -> polish);
//            strcpy(temp -> polish, temp -> next -> polish);
//            strcpy(temp -> next -> polish, pom);
//            for (int i=0;i<T;i++)
//            {
//                char pom2[X];
//                strcpy(pom2, temp -> english[i]);
//                strcpy(temp -> english[i], temp -> next -> english[i]);
//                strcpy(temp -> next ->english[i], pom2);
//            }
//            int pom3 = temp -> quantity;
//            temp -> quantity = temp -> next -> quantity;
//            temp -> next -> quantity = pom3;
////            //get previous temp element
////            ADRESS prev = previous(first, temp);
////            //element after temp -> next
////            ADRESS next1 = next(first, temp -> next);
////            //If first element
////            if (prev == NULL)
////            {
////                //ADRESS pom = temp;
////                first = temp -> next -> next;
////                temp -> next = first;
////            }
////
////            else
////            {
////                ADRESS temp3 = temp;
////                prev = temp -> next;
////                temp -> next = temp;
////            }
////        }
//        temp = temp -> next;
//    }

    //Sort english tab and printf to file
    temp = first;
    qsort(temp -> english, T, X*sizeof(char), compare_strings);

    while (temp != NULL)
    {
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
    if (file == NULL)
        return false;
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

