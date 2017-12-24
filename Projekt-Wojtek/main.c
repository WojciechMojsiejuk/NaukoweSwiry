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
void Print_Database(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db);
ADRESS_TO_PL_DB Sort_Elements(ADRESS_TO_PL_DB polish_db); //sortowanie alfabetycznie
/* Additional functions to find previous and next element of lists*/
ADRESS_TO_PL_DB Previous_Element_PL(ADRESS_TO_PL_DB first_element, ADRESS_TO_PL_DB search_element );
ADRESS_TO_PL_DB Next_Element_PL(ADRESS_TO_PL_DB first_element, ADRESS_TO_PL_DB search_element);
ADRESS_TO_ENG_DB Previous_Element_ENG(ADRESS_TO_ENG_DB first_element, ADRESS_TO_ENG_DB search_element);
ADRESS_TO_ENG_DB Next_Element_ENG(ADRESS_TO_ENG_DB first_element, ADRESS_TO_ENG_DB search_element);

int main(int argc, const char * argv[]) {
    //initialization of Polish and English database
    ADRESS_TO_PL_DB init_pl=(ADRESS_TO_PL_DB)malloc(sizeof(POLISH_DATABASE));
    ADRESS_TO_PL_DB sort_pl=(ADRESS_TO_PL_DB)malloc(sizeof(POLISH_DATABASE));
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
    //Print_Database(init_pl,init_eng);
    //Make_Values_Unique(init_eng);
    printf("\n\nPO POSORTOWANIU\n\n");
    sort_pl=Sort_Elements(init_pl);
    Print_Database(sort_pl,init_eng);
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
        printf("%s p_k: %d w_c: %d\n",polish_db->word,polish_db->primary_key, polish_db->words_count);
        fprintf(output,"%s:",polish_db->word);
        ADRESS_TO_ENG_DB temp_to_iteration = english_db;
        while(temp_to_iteration)
        {
            if(temp_to_iteration->foreign_key==polish_db->primary_key)
            {
                printf(">%s f_k: %d p_k: %d w_c: %d\n",temp_to_iteration->word,temp_to_iteration->foreign_key,temp_to_iteration->primary_key, temp_to_iteration->words_count);
                if(temp_to_iteration->nast!=NULL)
                {
                    if((temp_to_iteration->nast->foreign_key)!=(polish_db->primary_key))
                        fprintf(output,"%s\n",temp_to_iteration->word);
                    else
                        fprintf(output,"%s,",temp_to_iteration->word);
                }
                else
                {
                    fprintf(output,"%s;",temp_to_iteration->word);
                }
                
            }
            temp_to_iteration=temp_to_iteration->nast;
        }
        polish_db=polish_db->nast;
    }
    fclose(output);
}
ADRESS_TO_PL_DB Sort_Elements(ADRESS_TO_PL_DB polish_db)
{
    ADRESS_TO_PL_DB iterator=polish_db;//general iterator
    ADRESS_TO_PL_DB sort; //used to swap pointers if changed
    ADRESS_TO_PL_DB temp1; //auxilary variable
    ADRESS_TO_PL_DB temp2; //auxilary variable
    ADRESS_TO_PL_DB temp3; //auxilary variable
    ADRESS_TO_PL_DB temp4; //auxilary variable
    ADRESS_TO_PL_DB temp5; //auxilary variable
    while(iterator->nast!=NULL)
    {
        sort=iterator;
        temp2=iterator->nast;
        while(temp2)
        {
            if(strcmp(temp2->word,sort->word)<0) //change sort everytime there is word which should be at the begginig of alphabetic order
                sort=temp2;
            temp2=temp2->nast;
        }
        if(sort!=iterator) //if sort is different than iterator it means there is need for changing an order of words
        {
            temp1=Previous_Element_PL(polish_db, iterator);
            temp2=Previous_Element_PL(polish_db, sort);
            temp3=Next_Element_PL(polish_db, iterator);
            temp4=Next_Element_PL(polish_db, sort);
            temp5=iterator;
            if(iterator->nast==sort&&temp4!=NULL)
            {
                temp1->nast=sort;
                sort->nast=temp5;
                temp5->nast=temp4;
                iterator=temp3;
                continue;
            }
            if(iterator->nast==sort&&temp4==NULL)
            {
                temp1->nast=sort;
                sort->nast=temp5;
                temp5->nast=NULL;
                iterator=temp3;
                continue;
            }
            if(temp1==NULL&&temp4!=NULL)
            {
                polish_db=sort;
                sort->nast=temp3;
                temp2->nast=temp5;
                temp5->nast=temp4;
            }
            if(temp1==NULL&&temp4==NULL)
            {
                polish_db=sort;
                sort->nast=temp3;
                temp2->nast=temp5;
                temp5->nast=NULL;
            }
            if(temp1!=NULL&&temp4!=NULL)
            {
                temp1->nast=sort;
                sort->nast=temp3;
                temp2->nast=temp5;
                temp5->nast=temp4;
            }
            if(temp1!=NULL&&temp4==NULL)
            {
                temp1->nast=sort;
                sort->nast=temp3;
                temp2->nast=temp5;
                temp5->nast=NULL;
            }
            iterator=temp3;
            continue;
        }
        iterator=iterator->nast;
    }
    return polish_db;
}
void Make_Values_Unique(ADRESS_TO_ENG_DB english_db)
{
    //zmiana wskaznika w liscie w zaleznosci od elementu. Elementy sprawdzic strcmp
}
ADRESS_TO_PL_DB Previous_Element_PL(ADRESS_TO_PL_DB first_element, ADRESS_TO_PL_DB search_element)
{
    //rozpatrzyć przypadek gdy początek listy
    
    if(first_element==search_element)
        return NULL;
    while((first_element->nast)!=search_element)
    {
        if(!first_element)
            return NULL;
        first_element=first_element->nast;
    }
    return first_element;
}
ADRESS_TO_ENG_DB Previous_Element_ENG(ADRESS_TO_ENG_DB first_element, ADRESS_TO_ENG_DB search_element)
{
    while((first_element->nast)!=search_element)
    {
        if(!first_element)
            return NULL;
        first_element=first_element->nast;
    }
    return first_element;
}
ADRESS_TO_PL_DB Next_Element_PL(ADRESS_TO_PL_DB first_element, ADRESS_TO_PL_DB search_element)
{
    while(first_element!=search_element)
    {
        if(!first_element)
            return NULL;
        first_element=first_element->nast;
    }
    return first_element->nast;
}
ADRESS_TO_ENG_DB Next_Element_ENG(ADRESS_TO_ENG_DB first_element, ADRESS_TO_ENG_DB search_element)
{
    while(first_element!=search_element)
    {
        if(!first_element)
            return NULL;
        first_element=first_element->nast;
    }
    return first_element->nast;
}
