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
#define P 10 //maximum of polish words held in database
#define MAX_WORD 25 //maximum size of one word

void Input_Values_to_databases(ADRESS_TO_PL_DB, ADRESS_TO_ENG_DB);
void Print_Polish_Database(ADRESS_TO_PL_DB polish_db);
void Print_English_Database(ADRESS_TO_ENG_DB english_db);
int main(int argc, const char * argv[]) {
    // insert code here...
    //initialization of Polish and English database
    ADRESS_TO_PL_DB init_pl=(ADRESS_TO_PL_DB)malloc(sizeof(POLISH_DATABASE));
    ADRESS_TO_ENG_DB init_eng=(ADRESS_TO_ENG_DB)malloc(sizeof(ENGLISH_DATABASE));
    Input_Values_to_databases(init_pl,init_eng);
    Print_Polish_Database(init_pl);
    Print_English_Database(init_eng);
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
    //i for iteration j for primary key in polish_db and foreign key in english_db k is for primary key in english db
    int c=0;
    for(l=0;l<P;l++)
    {
        while ((c = fgetc(database)) != EOF)
        {
            if(c==':')
                break;
            polish_db->word[i]=c;
            i++;
        }
        i=0;
        while ((c = fgetc(database)) != EOF)
        {
            if(c==' ')
            {
                i=0;
                english_db->foreign_key=j;
                english_db->primary_key=k;
                k++;
                english_db->nast=(ADRESS_TO_ENG_DB)malloc(sizeof(ENGLISH_DATABASE));
                english_db=english_db->nast;
                continue;
            }
            if(c=='\n')
            {
                i=0;
                english_db->foreign_key=j;
                english_db->primary_key=k;
                k++;
                english_db->nast=(ADRESS_TO_ENG_DB)malloc(sizeof(ENGLISH_DATABASE));
                english_db=english_db->nast;
                break;
            }
            english_db->word[i]=c;
            i++;
        }
        polish_db->primary_key=j;
        j++;
        polish_db->nast=(ADRESS_TO_PL_DB)malloc(sizeof(POLISH_DATABASE));
        polish_db=polish_db->nast;
    }
}
void Print_Polish_Database(ADRESS_TO_PL_DB polish_db)
{
    while(polish_db)
    {
        printf("%s ",polish_db->word);
        polish_db=polish_db->nast;
    }
}
void Print_English_Database(ADRESS_TO_ENG_DB english_db)
{
    while(english_db)
    {
        printf("%s ",english_db->word);
        english_db=english_db->nast;
    }
}
