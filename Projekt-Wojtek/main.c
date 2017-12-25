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
#include "sort_elements.h"

#define P 30//maximum of polish words held in database
#define MAX_WORD 25 //maximum size of one word

int Input_Values_to_databases(ADRESS_TO_PL_DB, ADRESS_TO_ENG_DB);
void Make_ENG_Values_Unique(ADRESS_TO_ENG_DB);
void Print_Database_PL(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db);
void Print_Database_ENG(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db);
ADRESS_TO_PL_DB Sort_Elements_PL(ADRESS_TO_PL_DB polish_db);
ADRESS_TO_ENG_DB Sort_Elements_ENG(ADRESS_TO_ENG_DB polish_db);

/* Additional functions to find previous and next element of lists*/

int main(int argc, const char * argv[]) {
    //initialization of Polish and English database
    ADRESS_TO_PL_DB init_pl=(ADRESS_TO_PL_DB)malloc(sizeof(POLISH_DATABASE));
    ADRESS_TO_PL_DB sort_pl=(ADRESS_TO_PL_DB)malloc(sizeof(POLISH_DATABASE));
    ADRESS_TO_ENG_DB init_eng=(ADRESS_TO_ENG_DB)malloc(sizeof(ENGLISH_DATABASE));
    ADRESS_TO_ENG_DB sort_eng=(ADRESS_TO_ENG_DB)malloc(sizeof(ENGLISH_DATABASE));
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
    Print_Database_PL(init_pl,init_eng);
    //Print_Database_ENG(init_pl, init_eng);
    printf("\n\nPO POSORTOWANIU\n\n");
    sort_pl=Sort_Elements_PL(init_pl);
    //Print_Database_PL(sort_pl,init_eng);
    sort_eng=Sort_Elements_ENG(init_eng);
    //Print_Database_PL(sort_pl,sort_eng);
    printf("\n\nPO ZUNIFIKOWANIU\n\n");
    Make_ENG_Values_Unique(sort_eng);
    printf("\n\nFINALE\n\n");
    Print_Database_ENG(sort_pl,sort_eng);
    return 0;
}
void Print_Database_PL(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db)
{
    printf("Save output as: ");
    //FILENAME_MAX stdio.h library macro
    char output_name[FILENAME_MAX];
    scanf("%s",output_name);
    FILE *output = fopen(output_name, "w");
    ADRESS_TO_ENG_DB temp_to_iteration;
    while(polish_db)
    {
        printf("%s p_k: %d w_c: %d\n",polish_db->word,polish_db->primary_key, polish_db->words_count);
        fprintf(output,"%s:",polish_db->word);
        temp_to_iteration = english_db;
        int counter = 1;
        while(temp_to_iteration)
        {
            if(temp_to_iteration->foreign_key==polish_db->primary_key)
            {
               printf(">%s f_k: %d p_k: %d w_c: %d\n",temp_to_iteration->word,temp_to_iteration->foreign_key,temp_to_iteration->primary_key, temp_to_iteration->words_count);
                if(counter==polish_db->words_count)
                {
                    if(polish_db->nast==NULL)
                        fprintf(output,"%s;",temp_to_iteration->word);
                    else
                        fprintf(output,"%s\n",temp_to_iteration->word);
                    counter=1;
                }
                else
                {
                    fprintf(output,"%s,",temp_to_iteration->word);
                    counter++;
                }
            }
            temp_to_iteration=temp_to_iteration->nast;
        }
        polish_db=polish_db->nast;
    }
    fclose(output);
}
void Print_Database_ENG(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db)
{
    printf("Save output as: ");
    //FILENAME_MAX stdio.h library macro
    char output_name[FILENAME_MAX];
    scanf("%s",output_name);
    FILE *output = fopen(output_name, "w");
    ADRESS_TO_ENG_DB temp_to_unique;
    ADRESS_TO_PL_DB temp_to_unique2;
    int counter;
    while(english_db)
    {
        if(english_db->words_count!=0)
            fprintf(output,"%s:",english_db->word);
        
        for(counter=1;counter<=english_db->words_count;counter++)
        {
            temp_to_unique=english_db;
            temp_to_unique2=polish_db;
            if(counter>1)
            {
                temp_to_unique=temp_to_unique->nast;
                while(temp_to_unique!=NULL)
                {
                    if(temp_to_unique->primary_key==english_db->primary_key)
                        break;
                    temp_to_unique=temp_to_unique->nast;
                }
            }
            while(temp_to_unique2)
                {
                    if(temp_to_unique2->primary_key==temp_to_unique->foreign_key)
                        break;
                    temp_to_unique2=temp_to_unique2->nast;
                }
            if(english_db->nast==NULL)
                    fprintf(output,"%s;",temp_to_unique2->word);
            else
            {
                if(counter!=english_db->words_count)
                    fprintf(output,"%s,",temp_to_unique2->word);
                else
                    fprintf(output,"%s\n",temp_to_unique2->word);
            }
        }
        english_db=english_db->nast;
    }
    fclose(output);
}

void Make_ENG_Values_Unique(ADRESS_TO_ENG_DB english_db)
{
    ADRESS_TO_ENG_DB iterator=english_db;//general iterator
    ADRESS_TO_ENG_DB unique; //used to find unique values
    ADRESS_TO_ENG_DB temp1; //auxilary variable
    while(iterator->nast!=NULL)
    {
        unique=iterator;
        temp1=iterator->nast;
        while(temp1)
        {
            if(strcmp(temp1->word,unique->word)==0)
            {
                temp1->primary_key=unique->primary_key;
                unique->words_count=(unique->words_count)+(temp1->words_count);
                temp1->words_count=0;
                /*if there are two words which are the same, previous one gets whole words_count
                 to make sure it won't double during the search for the biggest. Next one primary key is changed
                 so it would make searching easier
                 */
            }
            //printf("%s f_k: %d p_k: %d w_c: %d\n",temp1->word, temp1->foreign_key, temp1->primary_key, temp1->words_count);
            temp1=temp1->nast;
        }
        iterator=iterator->nast;
    }
}


//sortowanie angielskich done
//unikatowosc angielskich done
//unikatowosc polskich
//ile slow max
//usuwanie elementów
//menu
//sprawozdanie
//testy
