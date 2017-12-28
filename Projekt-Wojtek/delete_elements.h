//
//  delete_elements.h
//  Projekt
//
//  Created by Wojciech Mojsiejuk on 28.12.2017.
//  Copyright © 2017 Wojciech Mojsiejuk. All rights reserved.
//

#ifndef delete_elements_h
#define delete_elements_h
ADRESS_TO_PL_DB Delete_Element_PL(ADRESS_TO_PL_DB polish_db,ADRESS_TO_PL_DB to_delete)
{
    ADRESS_TO_PL_DB temp1=Previous_Element_PL(polish_db, to_delete);
    ADRESS_TO_PL_DB temp2=Next_Element_PL(polish_db, to_delete);
    if(temp1==NULL)
    {
        polish_db=temp2;
    }
    if(temp2==NULL)
    {
        temp1->nast=NULL;
    }
    if(temp1!=NULL&temp2!=NULL)
    {
        temp1->nast=temp2;
    }
    free(to_delete);
    to_delete=NULL;
    return polish_db;
}
ADRESS_TO_ENG_DB Delete_Element_ENG(ADRESS_TO_ENG_DB english_db, ADRESS_TO_ENG_DB to_delete)
{
    ADRESS_TO_ENG_DB temp1=Previous_Element_ENG(english_db, to_delete);
    ADRESS_TO_ENG_DB temp2=Next_Element_ENG(english_db, to_delete);
    if(temp1==NULL)
    {
        english_db=temp2;
    }
    if(temp2==NULL)
    {
        temp1->nast=NULL;
    }
    if(temp1!=NULL&temp2!=NULL)
    {
        temp1->nast=temp2;
    }
    free(to_delete);
    to_delete=NULL;
    return english_db;
}

#endif /* delete_elements_h */
