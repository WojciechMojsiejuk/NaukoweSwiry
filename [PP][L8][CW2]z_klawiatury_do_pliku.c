#include<stdio.h>
#define N 5
#define MAX 20
int main(){
int i;
char napis[N][MAX+1];
for(i=0;i<N;i++)
{
    fgets(napis[i],MAX+1,stdin);
    fflush(stdin);
}
char nazwa[200];
scanf("%s", nazwa);
FILE*plik=fopen(nazwa,"w");
if(plik==NULL) printf("blad pliku");
else for(i=0;i<N;i++)
{
    fprintf(plik,"%s",napis[i]);
}
fclose(plik);
return 0;
}
