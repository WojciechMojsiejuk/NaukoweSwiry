#include <stdio.h>
#include <string.h>

int DlugoscCiagu(const char* napis)
{
    int dl=strlen(napis);
    return dl;
}

int Palindrom(const char* napis)
{
    int i, warunek=1, dl=strlen(napis);
    for(i=0;i<dl/2;i++)
    {
        if(napis[i]!=napis[dl-1-i])
        {
            warunek=0;
            break;
        }
    }
    return warunek;
}

int main()
{
    char napis[100];
    scanf("%s", napis);
    int w=DlugoscCiagu(napis);
    int w2=Palindrom(napis);
    if(w2==1) printf("Palindrom\n");
    else printf("Nie jest to palindrom\n");
    printf("dlugosc= %d", w);
}
