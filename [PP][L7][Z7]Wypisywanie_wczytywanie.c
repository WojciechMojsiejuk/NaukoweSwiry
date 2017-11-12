#include <stdio.h>
#include <string.h>

#define W 50
#define MAX_L 100

int main()
{
    char nazwa[100]="[PP][L7][Z7]dane.txt", nazwa2[100]="[PP][L7][Z7]zapis.txt", napis[W][MAX_L];
    int dl[W], i=0;
    for(i=0;i<W;i++)
    {
        dl[i]=0;
    }
    i=0;
    FILE*dane=fopen(nazwa, "r");
    if(!dane)
    {
        perror(nazwa);
        return -1;
    }
    FILE*zapis=fopen(nazwa2, "w+");
    if(!zapis)
    {
        perror(nazwa2);
        return -2;
    }
    while(fscanf(dane,"%s ", napis[i])!=EOF)
    {
        dl[i]=strlen(napis[i]);
        printf("%d ", dl[i]);
        i++;
    }
    close(dane);
    close(zapis);
    return 0;
}
