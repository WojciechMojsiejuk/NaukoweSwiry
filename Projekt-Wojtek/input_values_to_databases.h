//
//  input_values_to_databases.h
//  Projekt
//
//  Created by Wojciech Mojsiejuk on 23.12.2017.
//  Copyright © 2017 Wojciech Mojsiejuk. All rights reserved.
//

#ifndef input_values_to_databases_h
#define input_values_to_databases_h
#define P 4//maximum of polish words held in database
#define MAX_WORD 25 //maximum size of one word
int Input_Values_to_databases(ADRESS_TO_PL_DB polish_db, ADRESS_TO_ENG_DB english_db)
{
#ifdef __Linux__
    printf("Sorry your system is currently not supported\n");
    return 1;
#endif
#ifdef _WIN32
    /*Code was originally written on MacOS, unix based system.
     Therefore there might be some problems with UTF-8 coding
     which is different in Windows OS */
    printf("Your OS might have problems coping with UTF-8 files.\nIf you load data successfully, but there are some strange artefact,\nyou may want to abandon letters from polish alphabet in your database\n");
#endif
    printf("Give filename of database you want to migrate: ");
    //FILENAME_MAX stdio.h library macro
    char name[FILENAME_MAX];
    scanf("%s",name);
    FILE *database = fopen(name, "r");
    if(!database)
    {
        perror(name);
        fprintf(stderr,"Database file should be placed in the same folder as this executable file,\nif it's not, when asked for filename please give a fullpath to the file.\n");
        return 1;
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
                #ifdef _WIN32
                if(!isascii(c)) //in Win OS at the begining of a file are meta which need to be skipped
                    continue;
                #endif // _WIN32
                if(c==':')
                {
                    polish_db->word[i]='\0';
                    break;
                }
                polish_db->word[i]=c;
                i++;
            }
            else
            {
                polish_db->word[i]='\0';
                fprintf(stderr,"Polish word is too large. It'll be cropped to suitable format.\nData might be corrupted because of this process.\nTo make sure there won't be any damage, change manually word to fit %d size. \nWord: %s...\n",MAX_WORD, polish_db->word);
                i=0;
                while ((c = fgetc(database)) != ':')
                    ;
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
                #ifdef _WIN32
                if(!isascii(c)) //in Win OS to omit polish characters
                    continue;
                #endif // _WIN32
                if(c==',') //do this when a word ends
                {
                    english_db->word[i]='\0';
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
                    english_db->word[i]='\0';
                    i=0;
                    break;
                }
                if(c==';')//do this when a file ends
                {
                    english_db->word[i]='\0';
                    while ((c = fgetc(database))!=EOF)
                        ;
                    break;
                }
                english_db->word[i]=c;
                i++;
            }
            else
            {
                fprintf(stderr,"English word is too large. It'll be cropped to suitable format.\nData might be corrupted because of this process.\nTo make sure there won't be any damage, change manually word to fit %d size. \nWord: %s...\n",MAX_WORD, english_db->word);
                i=0;
                english_db->foreign_key=j;
                english_db->primary_key=k;
                k++;
                english_db->nast=(ADRESS_TO_ENG_DB)malloc(sizeof(ENGLISH_DATABASE));
                english_db=english_db->nast;
                char temp_word[MAX_WORD];
                while ((c = fgetc(database)) != ',')
                {
                    #ifdef _WIN32
                        if(!isascii(c)) //in Win OS to omit polish characters
                        continue;
                    #endif // _WIN32
                    if(c=='\n')
                    {

                        english_db->foreign_key=j;
                        english_db->primary_key=k;
                        strcpy(english_db->word,temp_word);
                        break;
                    }
                    if(c==EOF)
                    {
                        fprintf(stderr, "Fatal error, word too large at the end of a file. Can't handle this exception.\n");
                        return 1;
                    }
                    temp_word[i]=c;
                    i++;
                }
                i=0;
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
    return 0;
}

#endif /* input_values_to_databases_h */
