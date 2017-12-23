//
//  english_database.h
//  Projekt
//
//  Created by Wojciech Mojsiejuk on 12.12.2017.
//  Copyright © 2017 Wojciech Mojsiejuk. All rights reserved.
//

#ifndef english_database_h
#define english_database_h
#define MAX_WORD 25
typedef struct english_database
{
    char word[MAX_WORD];
    int primary_key;
    int foreign_key;
    struct english_database *nast;
}ENGLISH_DATABASE;
typedef ENGLISH_DATABASE *ADRESS_TO_ENG_DB;

#endif /* english_database_h */
