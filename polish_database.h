//
//  polish_database.h
//  Projekt
//
//  Created by Wojciech Mojsiejuk on 13.12.2017.
//  Copyright © 2017 Wojciech Mojsiejuk. All rights reserved.
//

#ifndef polish_database_h
#define polish_database_h
#define MAX_WORD 25
typedef struct polish_database
{
    char word[MAX_WORD];
    int primary_key;
    int words_count;
    struct polish_database *nast;
}POLISH_DATABASE;
typedef POLISH_DATABASE *ADRESS_TO_PL_DB;

#endif /* polish_database_h */
