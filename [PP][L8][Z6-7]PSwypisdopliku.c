#include<stdio.h>

int main(){
    //ZADANIE6
    FILE*plik=fopen("test.txt","r");
    if(plik==NULL)
        return 1;
    int i=0;
    int znak = getc(plik);
    while(znak!=EOF)
    {
        putc(znak,stdout);
        znak = getc(plik);
        i++;
    }
    printf("Ilosc znakow: %d\n\n",i);
    rewind(plik);
    char zmienna[50][100];
    i=0; int j=0;
    while(fscanf(plik,"%s", zmienna[i])!=EOF)
    {
        fprintf(stdout,"%s ", zmienna[i]);
        j+=strlen(zmienna[i]);
        i++;
    }
    printf("\n\nIlosc slow: %d Ilosc znakow: %d\n\n",i,j);
    i=0;
    rewind(plik);
    char str[50];
    i=0;j=0;
    while(fgets(str,50,plik)!=NULL)
    {
        fputs(str,stdout);
        i++;
        j+=strlen(str);
    }
    printf("Ilosc wierszy: %d Ilosc znakow: %d\n\n",i,j);
    //ZADANIE 7
    printf("\n\n++++++ZADANIE7++++++++\n\n");
    rewind(plik);
    FILE*zapis=fopen("testkopia.txt","w");
    i=0;
    znak = getc(plik);
    while(znak!=EOF)
    {
        putc(znak,zapis);
        znak = getc(plik);
        i++;
    }
    printf("Ilosc znakow: %d",i);
    rewind(plik);
    char zmienna2[50][100];
    i=0; j=0;
    while(fscanf(plik,"%s", zmienna2[i])!=EOF)
    {
        fprintf(zapis,"%s ", zmienna2[i]);
        j+=strlen(zmienna2[i]);
        i++;
    }
    printf("\n\nIlosc slow: %d Ilosc znakow: %d\n\n",i,j);
    i=0;
    rewind(plik);
    char str2[50];
    i=0;j=0;
    while(fgets(str2,50,plik)!=NULL)
    {
        fputs(str2,zapis);
        i++;
        j+=strlen(str2);
    }
    printf("Ilosc wierszy: %d Ilosc znakow: %d\n\n",i,j);
    
    fclose(plik);
    plik=NULL;
    fclose(zapis);
    zapis=NULL;
    return 0;
   
}
