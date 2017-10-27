#include <cstdio>
#include <cstring>
#include <cmath>

int main(){
    int wynik=0;
    char a[100];
    scanf("%s", a);
    int dl=strlen(a);
    if (a[0]=='0'){
        for (int i=1;i<dl;i++){
            wynik+=(a[i]-48)*pow(2, dl-1-i);
        }
    }
    if (a[0]=='1'){
       for (int i=1;i<dl;i++){
            wynik+=(a[i]-48)*pow(2, dl-1-i);
        }
        wynik=wynik*(-1);
    }
    printf("%d", wynik);
}
