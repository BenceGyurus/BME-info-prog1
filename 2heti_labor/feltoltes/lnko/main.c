#include <stdio.h>

int main(void) {
        int a = 11220;
        int b = 2002;
        while (b > 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        printf("lnko = %d\n", a);
        return 0;
}
