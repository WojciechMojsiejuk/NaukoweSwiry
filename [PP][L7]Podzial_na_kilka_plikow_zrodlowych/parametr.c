#include <stdio.h>
#include "parametr.h"

void warunek()
{
    i=0;
    printf("Podaj parametry (ENTER konczy podawanie parametrow):\n");
    /*while((c=getchar())!='\n'){
        int w=scanf("%d", &parametr[i]);
        //printf("%d ", parametr[i]);
        if(w==0)
        {
            printf("Podaj liczbe!\n");
            continue;
        }
        i++;
    }*/
    do
    {
        int w=scanf("%d", &parametr[i]);
        //printf("%d ", parametr[i]);
        if(w==0)
        {
            printf("Podaj liczbe!\n");
            continue;
        }
        i++;
    }while((c=getchar())!='\n');
    //printf("\n");
    if(i!=2)
    {
        printf("Program 'Nazwa' powinien miec 2 parametry, natomiast ten ma %d", i);
    }
    else
    {
        printf("Podane parametry to: ");
        for (i=0;i<2;i++)
            printf("%d ", parametr[i]);
    }
}
