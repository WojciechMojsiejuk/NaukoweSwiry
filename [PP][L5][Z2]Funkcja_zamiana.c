#include <stdio.h>

void zamiana(int *a, int *b)
{
    int pom;
    pom=*a;
    *a=*b;
    *b=pom;
    //printf("%d %d", a, b);
}

int main()
{
    int z1, z2;
    scanf("%d %d", &z1, &z2);
    zamiana(&z1, &z2);
    printf("%d %d", z1, z2);
    return 0;
}
