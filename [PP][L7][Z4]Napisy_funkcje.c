#include <stdio.h>
#include <string.h>
char napis2[100];
char* Napis_malymi(const char* napis)
{
    int dl=strlen(napis), i;
    for(i=0;i<dl;i++)
    {
        if(napis[i]>='A' && napis[i]<='Z')
            napis2[i]=napis[i]+32;
        else
            napis2[i]=napis[i];
    }
    napis2[i]='\0';
    return napis2;
}

char* Napis_duzymi(const char* napis)
{
    int dl=strlen(napis), i;
    for(i=0;i<dl;i++)
    {
        if(napis[i]>='a' && napis[i]<='z')
            napis2[i]=napis[i]-32;
        else
            napis2[i]=napis[i];
    }
    napis2[i]='\0';
    return napis2;
}

char* Zmiana_wielkosci(const char* napis)
{
    int dl=strlen(napis), i;
    for (i=0;i<dl;i++)
    {
        if(napis[i]>='A' && napis[i]<='Z')
        {
            napis2[i]=napis[i]+32;
        }
        else
        {
            if(napis[i]>='a' && napis[i]<='z')
            {
                napis2[i]=napis[i]-32;
            }
            else
            {
                napis2[i]=napis[i];
            }
        }
    }
    napis2[i]='\0';
    return napis2;
}

char* Napis_wspak(const char* napis)
{
    int dl=strlen(napis), i;
    for(i=0;i<dl;i++)
    {
        napis2[i]=napis[dl-i-1];
    }
    napis2[i]='\0';
    return napis2;
}

char* Ten_sam_napis(const char* napis)
{
    int dl=strlen(napis), i;
    for(i=0;i<dl;i++)
    {
        napis2[i]=napis[i];
    }
    napis2[i]='\0';
    return napis2;
}

int main()
{
    char napis[100]="eMoO_MartYnkA";
    printf("Nasz napis to: %s\n", napis);
    char *napis2=Napis_malymi(napis);
    printf("Napis malymi: %s\n", napis2);
    char *napis3=Napis_duzymi(napis);
    printf("Napis duzymi: %s\n", napis3);
    char *napis4=Zmiana_wielkosci(napis);
    printf("Zmiana wielkosci liter: %s\n", napis4);
    char *napis5=Napis_wspak(napis);
    printf("Napis wspak: %s\n", napis5);
    char *napis6=Ten_sam_napis(napis);
    printf("Ten sam napis: %s\n", napis6);
}
