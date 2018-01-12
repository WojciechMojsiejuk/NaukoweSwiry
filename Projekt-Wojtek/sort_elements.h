//
//  sort_elements.h
//  Projekt
//
//  Created by Wojciech Mojsiejuk on 25.12.2017.
//  Copyright © 2017 Wojciech Mojsiejuk. All rights reserved.
//

#ifndef sort_elements_h
#define sort_elements_h
#include "functions_prototype.h"
ADRESS_TO_PL_DB Previous_Element_PL(ADRESS_TO_PL_DB first_element, ADRESS_TO_PL_DB search_element );
ADRESS_TO_PL_DB Next_Element_PL(ADRESS_TO_PL_DB first_element, ADRESS_TO_PL_DB search_element);
ADRESS_TO_ENG_DB Previous_Element_ENG(ADRESS_TO_ENG_DB first_element, ADRESS_TO_ENG_DB search_element);
ADRESS_TO_ENG_DB Next_Element_ENG(ADRESS_TO_ENG_DB first_element, ADRESS_TO_ENG_DB search_element);

ADRESS_TO_PL_DB Sort_Elements_PL(ADRESS_TO_PL_DB polish_db)
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
            if(temp1==NULL)
            {
                polish_db=sort;
            }
            else
            {
                temp1->nast=sort;
            }
            if((temp3==sort)&&(temp2==iterator))
            {
                sort->nast=temp5;
            }
            else
            {
                sort->nast=temp3;
                temp2->nast=temp5;
            }
            if(temp4!=NULL)
            {
                temp5->nast=temp4;
            }
            else
            {
                temp5->nast=NULL;
            }
            iterator=temp3;
            continue;
        }
        iterator=iterator->nast;
    }
    return polish_db;
}
ADRESS_TO_ENG_DB Sort_Elements_ENG(ADRESS_TO_ENG_DB english_db)
{
    ADRESS_TO_ENG_DB iterator=english_db;//general iterator
    ADRESS_TO_ENG_DB sort; //used to swap pointers if changed
    ADRESS_TO_ENG_DB temp1; //auxilary variable
    ADRESS_TO_ENG_DB temp2; //auxilary variable
    ADRESS_TO_ENG_DB temp3; //auxilary variable
    ADRESS_TO_ENG_DB temp4; //auxilary variable
    ADRESS_TO_ENG_DB temp5; //auxilary variable
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
            temp1=Previous_Element_ENG(english_db, iterator);
            temp2=Previous_Element_ENG(english_db, sort);
            temp3=Next_Element_ENG(english_db, iterator);
            temp4=Next_Element_ENG(english_db, sort);
            temp5=iterator;
            if(temp1==NULL)
            {
                english_db=sort;
            }
            else
            {
                temp1->nast=sort;
            }
            if((temp3==sort)&&(temp2==iterator))
            {
                sort->nast=temp5;
            }
            else
            {
                sort->nast=temp3;
                temp2->nast=temp5;
            }
            if(temp4!=NULL)
            {
                temp5->nast=temp4;
            }
            else
            {
                temp5->nast=NULL;
            }
            iterator=temp3;
            continue;
        }
        iterator=iterator->nast;
    }
    return english_db;
}
ADRESS_TO_PL_DB Previous_Element_PL(ADRESS_TO_PL_DB first_element, ADRESS_TO_PL_DB search_element)
{
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

#endif /* sort_elements_h */
