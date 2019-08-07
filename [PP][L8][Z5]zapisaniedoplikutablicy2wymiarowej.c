#include<stdio.h>
#define W 5
#define K 6
#include<time.h>
int main(){
    int tab[W][K];
    int i,j,k,l;
    srand((unsigned)time(NULL));
    for(k=0;k<W;k++){
        for(l=0;l<K;l++){
            tab[k][l]=rand();
        }
    }
    FILE*plik=fopen("plik.txt","w");
    if(plik==NULL)return;
    int size=sizeof(int);
    for(i=0;i<W;i++){
        for(j=0;j<K;j++){
            fprintf(plik,"%d\t",tab[i][j]);
        }
        fprintf(plik,"\n");
    }
    fclose(plik);
return 0;
}
