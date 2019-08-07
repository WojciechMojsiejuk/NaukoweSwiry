#include <stdio.h>
#define MAX 5

int DlugoscCiagu(const char* napis)
{
    int i=0;
    for(i=0;napis[i]!='\0';i++)
    {
    }
        
    return i-1;
}

int Palindrom(const char* napis,int licznik)
{
    int i;
    for(i=0;i<licznik/2;i++)
    {
        if(napis[i]!=napis[licznik-1-i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char napis[MAX+1];
    printf("Podaj swoj napis\n");
    fgets(napis,MAX+1,stdin);
    fflush(stdin);
    int w=DlugoscCiagu(napis);
    int w2=Palindrom(napis,w);
    if(w2==1) printf("Palindrom\n");
    else printf("Nie jest to palindromem\n");
    printf("dlugosc= %d\n", w);
}
