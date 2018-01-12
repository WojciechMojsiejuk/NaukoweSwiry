//
//  functions_prototype.h
//  Projekt
//
//  Created by Wojciech Mojsiejuk on 03.01.2018.
//  Copyright © 2018 Wojciech Mojsiejuk. All rights reserved.
//

#ifndef functions_prototype_h
#define functions_prototype_h
/*List of main functions with a describtion*/
int Input_Values_to_databases(ADRESS_TO_PL_DB, ADRESS_TO_ENG_DB);
/*
 Used to import data from text file to data structures created in polish_database.h and english_database.h .
 Function location: input_values_to_databases.h
 */
void Make_ENG_Values_Unique(ADRESS_TO_PL_DB,ADRESS_TO_ENG_DB);
/*
 One english word can be used to translate many polish words. This function makes sure that every word will display only once.
 It doesn't delete other encounters of the word, because it is still useful in other functions. Just change words_count so it
 won't be desplayed more than once.
 Function location: make_values_unique.h
 */
void Make_PL_Values_Unique(ADRESS_TO_PL_DB,ADRESS_TO_ENG_DB);
/*
 If the same word is put into the database, every encounter except the first one is deleted and all english words associated with them are linked to the primary version of a polish word.
 Function location: make_values_unique.h
 */
void Print_Database_PL(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db);
void Print_Database_ENG(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db);
/*
 Both functions are used to put structure to text files. If chosen option is Print_Database_PL file which was created
 can be used once more as a database (it's syntax is suitable to be read by this program).
 In case of Print_Database_ENG it is also created to match syntax,
 however if uploaded english words are treated as polish words and vice versa.
 This program was created as a Polish-English dictionary, every other use is thus not recommended.
 Function location: print_databases.h
 */
void Show_Menu(ADRESS_TO_PL_DB,ADRESS_TO_ENG_DB);
/*
 Main loop which allows user to choose options
 Function location: main.c
 */
void Most_Meanings(ADRESS_TO_PL_DB polish_db);
/*
 Function searches for polish words with the biggest value of words_count and put it to the file.
 Function location: main.c
 */
void Translate_Most(ADRESS_TO_PL_DB polish_db,ADRESS_TO_ENG_DB english_db);
/*
 Function searches for english words with the biggest value of words_count and put it to the file with all polish words which
 are connected to this words.
 Function location: main.c
 */
ADRESS_TO_PL_DB Searched_Word_PL(ADRESS_TO_PL_DB);
ADRESS_TO_ENG_DB Searched_Word_ENG(ADRESS_TO_ENG_DB,char word_name[]);
/*
 Additional functions used to find typed word
 Function location: main.c
 */
ADRESS_TO_PL_DB Matching_Key_PL(ADRESS_TO_PL_DB,ADRESS_TO_ENG_DB);
/*
 Additional function used to find polish word which primary key matches with given english word
 Function location: main.c
 */
ADRESS_TO_PL_DB Sort_Elements_PL(ADRESS_TO_PL_DB polish_db);
ADRESS_TO_ENG_DB Sort_Elements_ENG(ADRESS_TO_ENG_DB english_db);
/*
 Functions used to sort databases in alphabethical order
 Function location: sort_elements.h
 */
ADRESS_TO_PL_DB Delete_Element_PL(ADRESS_TO_PL_DB polish_db,ADRESS_TO_PL_DB to_delete);
ADRESS_TO_ENG_DB Delete_Element_ENG(ADRESS_TO_ENG_DB english_db, ADRESS_TO_ENG_DB to_delete);
/*
 Functions used to delete words from database
 Function location: delete_elements.h
 */


#endif /* functions_prototype_h */
