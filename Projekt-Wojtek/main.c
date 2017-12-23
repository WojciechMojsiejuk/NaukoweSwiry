//
//  main.c
//  Projekt
//
//  Created by Wojciech Mojsiejuk on 12.12.2017.
//  Copyright © 2017 Wojciech Mojsiejuk. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "polish_database.h"
#include "english_database.h"
#include "input_values_to_databases.h"

#define P 30//maximum of polish words held in database
#define MAX_WORD 25 //maximum size of one word

int Input_Values_to_databases(ADRESS_TO_PL_DB, ADRESS_TO_ENG_DB);
void Make_Values_Unique(ADRESS_TO_ENG_DB);
//additional functions:
void Print_Database(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db);
void Sort_Elements(ADRESS_TO_PL_DB polish_db, ADRESS_TO_ENG_DB english_db); //sortowanie alfabetycznie
/* Additional functions to find previous and next element of lists*/
ADRESS_TO_PL_DB Previous_Elemenet(ADRESS_TO_PL_DB first_element, ADRESS_TO_PL_DB search_element );
ADRESS_TO_PL_DB Next_Elemenet(ADRESS_TO_PL_DB polish_db);

int main(int argc, const char * argv[]) {
    //initialization of Polish and English database
    ADRESS_TO_PL_DB init_pl=(ADRESS_TO_PL_DB)malloc(sizeof(POLISH_DATABASE));
    ADRESS_TO_ENG_DB init_eng=(ADRESS_TO_ENG_DB)malloc(sizeof(ENGLISH_DATABASE));
    int problems_with_loading_a_file=Input_Values_to_databases(init_pl,init_eng);
    if(problems_with_loading_a_file==1)
    {
        fprintf(stderr, "Couldn't migrate the data correctly.\n");
        return 1;
    }
    else
    {
        printf("File was loaded successfully.\n\n");
    }
    Print_Database(init_pl,init_eng);
    Make_Values_Unique(init_eng);
    printf("\n\nPO POSORTOWANIU\n\n");
    //Sort_Elements(init_pl, init_eng);
    return 0;
}
void Print_Database(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db)
{
    printf("Save output as: ");
    //FILENAME_MAX stdio.h library macro
    char output_name[FILENAME_MAX];
    scanf("%s",output_name);
    FILE *output = fopen(output_name, "w");
    while(polish_db)
    {
        printf("%s %d\n",polish_db->word,polish_db->primary_key);
        fprintf(output,"%s:",polish_db->word);
        ADRESS_TO_ENG_DB temp_to_iteration = english_db;
        while(temp_to_iteration)
        {
            if(temp_to_iteration->foreign_key==polish_db->primary_key)
                {
                printf("%s %d %d\n",temp_to_iteration->word,temp_to_iteration->foreign_key,temp_to_iteration->primary_key);
                if((temp_to_iteration->nast->foreign_key)!=(polish_db->primary_key))
                    fprintf(output,"%s\n",temp_to_iteration->word);
                else
                    fprintf(output,"%s,",temp_to_iteration->word);
                }
            temp_to_iteration=temp_to_iteration->nast;
        }
        polish_db=polish_db->nast;
    }
    fclose(output);
}
void Sort_Elements(ADRESS_TO_PL_DB polish_db, ADRESS_TO_ENG_DB english_db)
{
    ADRESS_TO_PL_DB temp_pl=polish_db;
    ADRESS_TO_PL_DB temp_pl_asc;
    ADRESS_TO_PL_DB temp_pl_2;
    while(temp_pl->nast!=NULL)
    {
        temp_pl_asc=temp_pl;
        temp_pl_2=temp_pl->nast;
        while(temp_pl_2)
        {
            if(strcmp(temp_pl_2->word,temp_pl_asc->word)<0)
                temp_pl_asc=temp_pl_2;
            temp_pl_2=temp_pl_2->nast;
        }
        if(temp_pl_asc!=temp_pl) //to zrobic na wskaznikach
        {
            char temp_word[MAX_WORD];
            strcpy(temp_word,temp_pl_asc->word);
            strcpy(temp_pl_asc->word, temp_pl->word);
            strcpy(temp_pl->word, temp_word);
        }
        temp_pl=temp_pl->nast;
    }
    Print_Database(polish_db,english_db);
}
void Make_Values_Unique(ADRESS_TO_ENG_DB english_db)
{

    //zmiana wskaznika w liscie w zaleznosci od elementu. Elementy sprawdzic strcmp
}
ADRESS_TO_PL_DB Previous_Elemenet(ADRESS_TO_PL_DB first_element, ADRESS_TO_PL_DB search_element)
{
    while(first_element->nast!=search_element)
    {
        first_element=first_element->nast;
    }
    return first_element;
}
ADRESS_TO_PL_DB Next_Elemenet(ADRESS_TO_PL_DB polish_db);

//gdy linii jest wiecej niz dopuszczalny rozmiar
//gdy polski nie bd oddzielony :

