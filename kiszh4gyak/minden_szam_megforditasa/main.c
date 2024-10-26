#include <stdio.h>

int main(void)
{
    int x = 0 & 1;
    int szam = 76543210;
    szam = szam << 1 | x;
    printf("szam: %d", szam);
    return 0;

}