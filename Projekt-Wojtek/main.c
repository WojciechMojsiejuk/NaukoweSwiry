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

#define P 30//maximum of polish words held in database
#define MAX_WORD 25 //maximum size of one word

int Input_Values_to_databases(ADRESS_TO_PL_DB, ADRESS_TO_ENG_DB);
void Make_ENG_Values_Unique(ADRESS_TO_ENG_DB);
void Make_PL_Values_Unique(ADRESS_TO_PL_DB,ADRESS_TO_ENG_DB);
void Print_Database_PL(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db);
void Print_Database_ENG(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db);
void Show_Menu(ADRESS_TO_PL_DB,ADRESS_TO_ENG_DB);
void Most_Meanings(ADRESS_TO_PL_DB polish_db);
void Translate_Most(ADRESS_TO_ENG_DB english_db);
ADRESS_TO_PL_DB Searched_Word_PL(ADRESS_TO_PL_DB);
ADRESS_TO_ENG_DB Searched_Word_ENG(ADRESS_TO_ENG_DB);
ADRESS_TO_PL_DB Matching_Key_PL(ADRESS_TO_PL_DB,ADRESS_TO_ENG_DB);
ADRESS_TO_ENG_DB Matching_Key_ENG(ADRESS_TO_PL_DB,ADRESS_TO_ENG_DB);
ADRESS_TO_PL_DB Sort_Elements_PL(ADRESS_TO_PL_DB polish_db);
ADRESS_TO_ENG_DB Sort_Elements_ENG(ADRESS_TO_ENG_DB english_db);
ADRESS_TO_PL_DB Delete_Element_PL(ADRESS_TO_PL_DB polish_db,ADRESS_TO_PL_DB to_delete);
ADRESS_TO_ENG_DB Delete_Element_ENG(ADRESS_TO_ENG_DB english_db, ADRESS_TO_ENG_DB to_delete);
ADRESS_TO_ENG_DB Last_Translation(ADRESS_TO_ENG_DB english_db,ADRESS_TO_PL_DB to_search,ADRESS_TO_ENG_DB new);
ADRESS_TO_ENG_DB First_Translation(ADRESS_TO_ENG_DB english_db,ADRESS_TO_PL_DB to_search);

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
    //
    //printf("\n\nPO POSORTOWANIU\n\n");
    //sort_pl=Sort_Elements_PL(init_pl);
    //Print_Database_PL(sort_pl,init_eng);
    //sort_eng=Sort_Elements_ENG(init_eng);
    //Print_Database_PL(sort_pl,sort_eng);
    //printf("\n\nPO ZUNIFIKOWANIU\n\n");
    //Make_ENG_Values_Unique(sort_eng);
    //Make_PL_Values_Unique(sort_pl, sort_eng);
    //printf("\n\nFINALE\n\n");
    //Print_Database_PL(sort_pl,sort_eng);
    return 0;
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
void Make_PL_Values_Unique(ADRESS_TO_PL_DB polish_db, ADRESS_TO_ENG_DB english_db)
{
    ADRESS_TO_PL_DB iterator=polish_db;//general iterator
    ADRESS_TO_PL_DB unique; //used to find unique values
    ADRESS_TO_PL_DB temp1; //auxilary variable
    ADRESS_TO_ENG_DB temp2;
    ADRESS_TO_ENG_DB temp3;
    ADRESS_TO_ENG_DB temp4;
    ADRESS_TO_ENG_DB temp5;
    ADRESS_TO_ENG_DB temp6;
    ADRESS_TO_ENG_DB temp7;
    while(iterator->nast!=NULL)
    {
        unique=iterator;
        temp1=iterator->nast;
        while(temp1)
        {
            if(strcmp(temp1->word,unique->word)==0)
            {
                temp3=First_Translation(english_db, temp1);
                temp2=Last_Translation(english_db, unique,NULL);
                temp4=Next_Element_ENG(english_db, temp2);
                temp5=Previous_Element_ENG(english_db, temp3);
                temp6=Last_Translation(english_db, temp1,temp2);
                temp7=Next_Element_ENG(english_db, temp6);
                temp2->nast=temp3;
                if(temp4==temp3)
                    {
                        ;
                    }
                else
                    {
                        temp6->nast=temp4;
                        temp5->nast=temp7;
                    }
                unique->words_count=(unique->words_count)+(temp1->words_count);
                Delete_Element_PL(polish_db, temp1);
                continue;
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
ADRESS_TO_PL_DB Delete_Element_PL(ADRESS_TO_PL_DB polish_db,ADRESS_TO_PL_DB to_delete)
{
    ADRESS_TO_PL_DB temp1=Previous_Element_PL(polish_db, to_delete);
    ADRESS_TO_PL_DB temp2=Next_Element_PL(polish_db, to_delete);
    if(temp1==NULL)
    {
        polish_db=temp2;
    }
    if(temp2==NULL)
    {
        temp1->nast=NULL;
    }
    if(temp1!=NULL&temp2!=NULL)
    {
        temp1->nast=temp2;
    }
    free(to_delete);
    to_delete=NULL;
    return polish_db;
}
ADRESS_TO_ENG_DB Delete_Element_ENG(ADRESS_TO_ENG_DB english_db, ADRESS_TO_ENG_DB to_delete)
{
    ADRESS_TO_ENG_DB temp1=Previous_Element_ENG(english_db, to_delete);
    ADRESS_TO_ENG_DB temp2=Next_Element_ENG(english_db, to_delete);
    if(temp1==NULL)
    {
        english_db=temp2;
    }
    if(temp2==NULL)
    {
        temp1->nast=NULL;
    }
    if(temp1!=NULL&temp2!=NULL)
    {
        temp1->nast=temp2;
    }
    free(to_delete);
    to_delete=NULL;
    return english_db;
}
ADRESS_TO_ENG_DB First_Translation(ADRESS_TO_ENG_DB english_db,ADRESS_TO_PL_DB to_search)
{
    while(english_db)
    {
        if(english_db->foreign_key==to_search->primary_key)
            return english_db;
        english_db=english_db->nast;
    }
    fprintf(stderr, "Element not found");
    return NULL;
}
ADRESS_TO_ENG_DB Last_Translation(ADRESS_TO_ENG_DB english_db,ADRESS_TO_PL_DB to_search,ADRESS_TO_ENG_DB new)
{
    ADRESS_TO_ENG_DB last=NULL;
    while(english_db)
    {
        if(english_db->foreign_key==to_search->primary_key)
        {
            last=english_db;
            if(new!=NULL)
                last->foreign_key=new->foreign_key;
        }
        english_db=english_db->nast;
    }
    if(last==NULL)
    {
        fprintf(stderr, "Element not found");
        return NULL;
    }
    return last;
}
void Show_Menu(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db)
{
    ADRESS_TO_PL_DB temp_pl=(ADRESS_TO_PL_DB)malloc(sizeof(POLISH_DATABASE));
    ADRESS_TO_ENG_DB temp_eng=(ADRESS_TO_ENG_DB)malloc(sizeof(ENGLISH_DATABASE));
    int choice;
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
                Translate_Most(english_db);
                break;
            case 6:
                temp_pl=Searched_Word_PL(polish_db);
                polish_db=Delete_Element_PL(polish_db, temp_pl);
                Print_Database_PL(polish_db, english_db);
                break;
            case 7:
                temp_eng=Searched_Word_ENG(english_db);
                english_db=Delete_Element_ENG(english_db, temp_eng);
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
            fprintf(output,"%s:", polish_db->word);
        }
        polish_db=polish_db->nast;
    }
    fclose(output);
    output=NULL;
}
void Translate_Most(ADRESS_TO_ENG_DB english_db)
{
        ADRESS_TO_ENG_DB maximum_meanings=english_db;
        ADRESS_TO_ENG_DB temp1;
        temp1=english_db;
        printf("Save output as: ");
        //FILENAME_MAX stdio.h library macro
        char output_name[FILENAME_MAX];
        scanf("%s",output_name);
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
    scanf("%s",word_name);
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
        fprintf(stderr, "Couldn't find a word");
    return search;
}
ADRESS_TO_ENG_DB Searched_Word_ENG(ADRESS_TO_ENG_DB english_db)
{
    printf("Insert searched word: ");
    char word_name[FILENAME_MAX];
    scanf("%s",word_name);
    ADRESS_TO_ENG_DB search = NULL;
    while(english_db)
    {
        if(strcmp(english_db->word, word_name)==0)
        {
            search=english_db;
        }
        english_db=english_db->nast;
    }
    if(search==NULL)
        fprintf(stderr, "Couldn't find a word");
    return search;
}
//sortowanie angielskich done
//unikatowosc angielskich done
//unikatowosc polskich
//ile slow max done
//usuwanie elementów
//menu done
//sprawozdanie
//testy
