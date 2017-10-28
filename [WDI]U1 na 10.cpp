#include <cstdio>
#include <cmath>
#include <cstring>

int main(){
    char a[100];
    int wynik=0;
    int pom;
    scanf("%s", a);
    int dl=strlen(a);
    if (a[0]=='0'){
        for (int i=1;i<dl;i++){
            wynik+=(a[i]-48)*pow(2, dl-1-i);
        }
    }
    if (a[0]=='1'){
        for (int i=1;i<dl;i++){
            if (a[i]=='0') pom=1;
            if (a[i]=='1') pom=0;
            wynik+=pom*pow(2, dl-1-i);
        }
        wynik=wynik*(-1);
    }
    printf("%d", wynik);
}
