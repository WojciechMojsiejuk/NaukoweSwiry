#include <stdio.h>
#include <string.h>

#define MAX_DL 5

int main()
{
    char napis[MAX_DL];
    int i, c=0;
    for(i=0;i<MAX_DL-1 && c!='\n';i++)
    {
        napis[i]=(c=getchar());
    }
    napis[i]='\0';
    printf("%s", napis);
    return 0;
}
