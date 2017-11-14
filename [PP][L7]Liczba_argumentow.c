#include <stdio.h>

int main(int argc, char*argv[])
{
    if(argc!=3)
    {
        printf("%s Nie poprawna ilosc arhumentow", argv[0]);
        return 1;
    }
    else
    {
        printf("parametr: %s parametr: %s", argv[1], argv[2]);
    }
}
