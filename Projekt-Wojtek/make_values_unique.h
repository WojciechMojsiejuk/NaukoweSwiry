//
//  make_values_unique.h
//  Projekt
//
//  Created by Wojciech Mojsiejuk on 28.12.2017.
//  Copyright © 2017 Wojciech Mojsiejuk. All rights reserved.
//

#ifndef make_values_unique_h
#define make_values_unique_h
ADRESS_TO_ENG_DB Last_Translation(ADRESS_TO_ENG_DB english_db,ADRESS_TO_PL_DB to_search,ADRESS_TO_ENG_DB new);
ADRESS_TO_ENG_DB First_Translation(ADRESS_TO_ENG_DB english_db,ADRESS_TO_PL_DB to_search);

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
                //to handle exception
                if(temp1->foreign_key==unique->foreign_key)
                {
                    
                }
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
                temp1=Delete_Element_PL(polish_db, temp1);
                break;
                /*if there are two words which are the same, previous one gets whole words_count
                 to make sure it won't double during the search for the biggest. Next one primary key is changed
                 so it would make searching easier
                 */
            }
            temp1=temp1->nast;
        }
        iterator=iterator->nast;
    }
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

#endif /* make_values_unique_h */
