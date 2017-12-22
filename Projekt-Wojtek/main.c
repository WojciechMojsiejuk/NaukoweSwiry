//
//  main.c
//  Projekt
//
//  Created by Wojciech Mojsiejuk on 12.12.2017.
//  Copyright © 2017 Wojciech Mojsiejuk. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "polish_database.h"
#include "english_database.h"
#define P 4//maximum of polish words held in database
#define MAX_WORD 25 //maximum size of one word

void Input_Values_to_databases(ADRESS_TO_PL_DB, ADRESS_TO_ENG_DB);
void Make_Values_Unique(ADRESS_TO_ENG_DB);
//additional functions:
void Print_Polish_Database(ADRESS_TO_PL_DB polish_db); // zrobic jako wskazniki do funkcji
void Print_English_Database(ADRESS_TO_ENG_DB english_db); //zrobic jako wskazniki do funkcji
void Sort_Elements(ADRESS_TO_PL_DB polish_db, ADRESS_TO_ENG_DB english_db); //sortowanie alfabetycznie
/* Additional functions to find previous and next element of lists*/
ADRESS_TO_PL_DB Previous_Elemenet(ADRESS_TO_PL_DB first_element, ADRESS_TO_PL_DB search_element );
ADRESS_TO_PL_DB Next_Elemenet(ADRESS_TO_PL_DB polish_db);


/*Global*/

int main(int argc, const char * argv[]) {
    //initialization of Polish and English database
    ADRESS_TO_PL_DB init_pl=(ADRESS_TO_PL_DB)malloc(sizeof(POLISH_DATABASE));
    ADRESS_TO_ENG_DB init_eng=(ADRESS_TO_ENG_DB)malloc(sizeof(ENGLISH_DATABASE));
    Input_Values_to_databases(init_pl,init_eng);
    Print_Polish_Database(init_pl);
    Print_English_Database(init_eng);
    Make_Values_Unique(init_eng);
    printf("\n\nPO POSORTOWANIU\n\n");
    Sort_Elements(init_pl, init_eng);
    
    return 0;
}
void Input_Values_to_databases(ADRESS_TO_PL_DB polish_db, ADRESS_TO_ENG_DB english_db)
{
    printf("Give filename of database you want to migrate: ");
    //FILENAME_MAX stdio.h library macro
    char name[FILENAME_MAX];
    scanf("%s",name);
    FILE *database = fopen(name, "r");
    if(!database)
    {
        perror(name);
        fprintf(stderr,"Database file should be placed in the same folder as this executable file,\nif it's not, when asked for filename please give a fullpath to the file.\n");
        return;
    }
    int i=0,j=0,k=0,l=0;
    /*i is used in iteration for creating words
     j for primary key in polish_db and foreign key in english_db
     k is for primary key in english db
     l is used in for loop to execute it P times*/
    int c=0;
    for(l=0;l<P;l++)
    {
        while ((c = fgetc(database)) != EOF)
        {
            if(i<MAX_WORD)
            {
                if(c==':')
                    break;
                polish_db->word[i]=c;
                i++;
            }
            else
            {
                fprintf(stderr,"Word is too large to format. It'll be cropped to suitable format\n");
                i=0;
                break;
            }
           
        }
        i=0;
        polish_db->primary_key=j;
        polish_db->nast=NULL; //for a safety of data by default pointer should point to NULL
        while ((c = fgetc(database))!=EOF)
        {
            if(i<MAX_WORD)
            {
                if(c==',') //do this when a word ends
                {
                    i=0;
                    english_db->foreign_key=j;
                    english_db->primary_key=k;
                    k++;
                    english_db->nast=(ADRESS_TO_ENG_DB)malloc(sizeof(ENGLISH_DATABASE));
                    english_db=english_db->nast;
                    continue;
                }
                if(c=='\n') //do this when a line ends
                {
                    i=0;
                    break;
                }
                english_db->word[i]=c;
                i++;
            }
            else
            {
                fprintf(stderr,"1Word is too large to format. It'll be cropped to suitable format\n");
                i=0;
                break;
            }
            
        }
        english_db->foreign_key=j;
        english_db->primary_key=k;
        k++;
        j++;
        english_db->nast=NULL; //for a safety of data by default pointer should point to NULL
        
        if(c==EOF) //handling exception to not create new elements at the end of a file
        {
            break;
        }
        if((j)==P)//to handle exception when file is larger than P
        {
            fprintf(stderr,"Couldn't load whole file.\n");
            break;
        }
        polish_db->nast=(ADRESS_TO_PL_DB)malloc(sizeof(POLISH_DATABASE));
        polish_db=polish_db->nast;
        polish_db->nast=NULL;
        english_db->nast=(ADRESS_TO_ENG_DB)malloc(sizeof(ENGLISH_DATABASE));
        english_db=english_db->nast;
        english_db->nast=NULL;
}
    printf("You've loaded %d lines from %s file\n\n",l+1,name);
}

void Print_Polish_Database(ADRESS_TO_PL_DB polish_db)
{
    while(polish_db)
    {
        printf("%s %d\n",polish_db->word,polish_db->primary_key);
        polish_db=polish_db->nast;
    }
}
void Print_English_Database(ADRESS_TO_ENG_DB english_db)
{
    while(english_db)
    {
        printf("%s %d %d\n",english_db->word,english_db->foreign_key,english_db->primary_key);
        english_db=english_db->nast;
    }
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
    Print_Polish_Database(polish_db);
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

