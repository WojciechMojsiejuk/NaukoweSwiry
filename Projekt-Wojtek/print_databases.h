//
//  print_databases.h
//  Projekt
//
//  Created by Wojciech Mojsiejuk on 26.12.2017.
//  Copyright © 2017 Wojciech Mojsiejuk. All rights reserved.
//

#ifndef print_databases_h
#define print_databases_h
#include "functions_prototype.h"
void Print_Database_PL(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db)
{
    if(polish_db==NULL||english_db==NULL||strcmp(polish_db->word,"")==0||strcmp(english_db->word,"")==0)
    {
        fprintf(stderr, "Database is empty\n");
        return;
    }
    printf("Save output as: ");
    //FILENAME_MAX stdio.h library macro
    char output_name[FILENAME_MAX];
    scanf("%s",output_name);
    FILE *output = fopen(output_name, "w");
    if(!output)
    {
        perror(output_name);
        fprintf(stderr,"Fatal error.Couldn't create a file\n");
        return;
    }
    ADRESS_TO_ENG_DB temp_to_iteration;

    while(polish_db)
    {
        printf("%s p_k: %d w_c: %d\n",polish_db->word,polish_db->primary_key, polish_db->words_count);
        fprintf(output,"%s:",polish_db->word);
        if(polish_db->words_count==0)
        {
            fprintf(output, "\n");
            polish_db=polish_db->nast;

        }
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
    if(polish_db==NULL||english_db==NULL||strcmp(polish_db->word,"")==0||strcmp(english_db->word,"")==0)
    {
        fprintf(stderr, "Database is empty\n");
        return;
    }
    printf("Save output as: ");
    //FILENAME_MAX stdio.h library macro
    char output_name[FILENAME_MAX];
    scanf("%s",output_name);
    FILE *output = fopen(output_name, "w");
    if(!output)
    {
        perror(output_name);
        fprintf(stderr,"Couldn't create a file\n");
        return;
    }
    ADRESS_TO_ENG_DB temp_to_unique;
    ADRESS_TO_PL_DB temp_to_unique2;
    ADRESS_TO_PL_DB temp_to_unique3=polish_db;
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
                temp_to_unique2=temp_to_unique3->nast;
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
                {
                    temp_to_unique3=temp_to_unique2;
                    break;
                }

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
#endif /* print_databases_h */
