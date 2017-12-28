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
#include "print_databases.h"
#include "delete_elements.h"
#include "make_values_unique.h"
#define P 30//maximum of polish words held in database
#define MAX_WORD 25 //maximum size of one word

int Input_Values_to_databases(ADRESS_TO_PL_DB, ADRESS_TO_ENG_DB);
void Make_ENG_Values_Unique(ADRESS_TO_ENG_DB);
void Make_PL_Values_Unique(ADRESS_TO_PL_DB,ADRESS_TO_ENG_DB);
void Print_Database_PL(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db);
void Print_Database_ENG(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db);
void Show_Menu(ADRESS_TO_PL_DB,ADRESS_TO_ENG_DB);
void Most_Meanings(ADRESS_TO_PL_DB polish_db);
void Translate_Most(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db);
ADRESS_TO_PL_DB Searched_Word_PL(ADRESS_TO_PL_DB);
ADRESS_TO_ENG_DB Searched_Word_ENG(ADRESS_TO_ENG_DB,char word_name[]);
ADRESS_TO_PL_DB Matching_Key_PL(ADRESS_TO_PL_DB,ADRESS_TO_ENG_DB);
ADRESS_TO_PL_DB Sort_Elements_PL(ADRESS_TO_PL_DB polish_db);
ADRESS_TO_ENG_DB Sort_Elements_ENG(ADRESS_TO_ENG_DB english_db);
ADRESS_TO_PL_DB Delete_Element_PL(ADRESS_TO_PL_DB polish_db,ADRESS_TO_PL_DB to_delete);
ADRESS_TO_ENG_DB Delete_Element_ENG(ADRESS_TO_ENG_DB english_db, ADRESS_TO_ENG_DB to_delete);

/* Additional functions to find previous and next element of lists*/

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
    Show_Menu(init_pl,init_eng);
    return 0;
}




void Show_Menu(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db)
{
    ADRESS_TO_PL_DB temp_pl=polish_db;
    ADRESS_TO_ENG_DB temp_eng=english_db;
    int choice;
    int counter=1;
    do
    {
    printf("1.Print database polish order\n");
    printf("2.Print database  english order\n");
    printf("3.Sort database\n");
    printf("4. Print polish words which has the most meanings\n");
    printf("5. Print english words which translate the biggest number of polish words\n");
    printf("6. Delete polish word\n");
    printf("7. Delete english word\n");
    printf("0.Exit\n");
    printf("What do you want to do?\n");
    scanf("%d",&choice);
        switch (choice) {
            case 1:
                Make_PL_Values_Unique(polish_db, english_db);
                 Print_Database_PL(polish_db, english_db);
                break;
            case 2:
                Make_ENG_Values_Unique(english_db);
                Print_Database_ENG(polish_db, english_db);
                break;
            case 3:
                polish_db=Sort_Elements_PL(polish_db);
                english_db=Sort_Elements_ENG(english_db);
                Print_Database_PL(polish_db, english_db);
                break;
            case 4:
                Make_PL_Values_Unique(polish_db, english_db);
                Most_Meanings(polish_db);
                break;
            case 5:
                Make_ENG_Values_Unique(english_db);
                Translate_Most(polish_db,english_db);
                break;
            case 6:
                temp_pl=Searched_Word_PL(polish_db);
                if(!temp_pl)
                {
                    fprintf(stderr, "Fatal error. Abort program.\n");
                    return;
                }
                for(counter=1;counter<=temp_pl->words_count;counter++)
                {
                    temp_eng=First_Translation(english_db, temp_pl);
                    Delete_Element_ENG(english_db,temp_eng);
                }
                polish_db=Delete_Element_PL(polish_db, temp_pl);
                counter=1;
                Print_Database_PL(polish_db, english_db);
                
                break;
            case 7:
                printf("Insert searched word: ");
                char eng_word_name[FILENAME_MAX];
                fgets(eng_word_name, FILENAME_MAX, stdin); /* TU JEST PROBLEM" */
                printf("%s",eng_word_name);
                temp_eng=Searched_Word_ENG(english_db,eng_word_name);
                if(!temp_eng)
                {
                    fprintf(stderr, "Fatal error. Abort program.\n");
                    return;
                }
                int temp_counter=temp_eng->words_count;
                for(counter=1;counter<=temp_counter;counter++)
                {
                    temp_eng=Searched_Word_ENG(temp_eng,eng_word_name);
                    temp_pl=Matching_Key_PL(polish_db, temp_eng);
                    temp_pl->words_count=temp_pl->words_count-1;
                    english_db=Delete_Element_ENG(english_db, temp_eng);
                }
                Print_Database_PL(polish_db, english_db);
                break;
            case 0:
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }while(choice);
    
}
void Most_Meanings(ADRESS_TO_PL_DB polish_db)
{
    ADRESS_TO_PL_DB maximum_translations=polish_db;
    ADRESS_TO_PL_DB temp1;
    temp1=polish_db;
    printf("Save output as: ");
    //FILENAME_MAX stdio.h library macro
    char output_name[FILENAME_MAX];
    scanf("%s",output_name);
    FILE *output = fopen(output_name, "w");
    while(temp1)
    {
        if(temp1->words_count>maximum_translations->words_count)
            maximum_translations=temp1;
        temp1=temp1->nast;
    }
    while(polish_db)
    {
        if(polish_db->words_count==maximum_translations->words_count)
        {
            fprintf(output,"%s\n", polish_db->word);
        }
        polish_db=polish_db->nast;
    }
    fclose(output);
    output=NULL;
}
void Translate_Most(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db)
{
    ADRESS_TO_ENG_DB maximum_meanings=english_db;
    ADRESS_TO_ENG_DB temp1;
    ADRESS_TO_PL_DB temp2;
    temp1=english_db;
    printf("Save output as: ");
    //FILENAME_MAX stdio.h library macro
    char output_name[FILENAME_MAX];
    scanf("%s",output_name);
    int counter;
    FILE *output = fopen(output_name, "w");
    while(temp1)
    {
        if(temp1->words_count>maximum_meanings->words_count)
            maximum_meanings=temp1;
        temp1=temp1->nast;
    }
    while(english_db)
    {
        if(english_db->words_count==maximum_meanings->words_count)
        {
            fprintf(output,"%s:", english_db->word);
            temp1=english_db;
            temp2=polish_db;
            for(counter=1;counter<=english_db->words_count;counter++)
            {
                if(counter!=1)
                {
                    temp1=temp1->nast;
                    temp1=Searched_Word_ENG(temp1, english_db->word);

                }
                temp2=Matching_Key_PL(temp2, temp1);
                if(counter==english_db->words_count)
                {
                    fprintf(output, "%s\n",temp2->word);
                }
                else
                {
                    fprintf(output, "%s,",temp2->word);
                }
            }
        }
        english_db=english_db->nast;
    }
    fclose(output);
    output=NULL;
}
ADRESS_TO_PL_DB Searched_Word_PL(ADRESS_TO_PL_DB polish_db)
{
    printf("Insert searched word: ");
    char word_name[FILENAME_MAX];
    fgets(word_name, FILENAME_MAX, stdin);
    ADRESS_TO_PL_DB search = NULL;
    while(polish_db)
    {
        if(strcmp(polish_db->word, word_name)==0)
        {
            search=polish_db;
        }
        polish_db=polish_db->nast;
    }
    if(search==NULL)
        fprintf(stderr, "Couldn't find a polish word\n");
    return search;
}
ADRESS_TO_ENG_DB Searched_Word_ENG(ADRESS_TO_ENG_DB english_db, char word_name[])
{
    ADRESS_TO_ENG_DB search = NULL;
    while(english_db)
    {
        if(strcmp(english_db->word, word_name)==0)
        {
            search=english_db;
            return search;
        }
        english_db=english_db->nast;
    }
    if(search==NULL)
        fprintf(stderr, "Couldn't find an english word\n");
    return search;
}
ADRESS_TO_PL_DB Matching_Key_PL(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db)
{
    while(polish_db)
    {
        if(polish_db->primary_key==english_db->foreign_key)
            return polish_db;
        polish_db=polish_db->nast;
    }
    fprintf(stderr,"Couldn't find a matching key");
    return NULL;
}


//sprawozdanie
//testy
