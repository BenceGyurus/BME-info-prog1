#include <stdio.h>

int main(void) {
    int a = 1;

    int osszeg = 1;

    while (a<=8) {
        osszeg*=a;
        a++;
    }

    printf("%d! = %d", a,osszeg);


    return 0;
}

