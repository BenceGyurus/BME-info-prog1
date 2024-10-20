#include <stdio.h>

int main(void) {
    double be, min, max;
    min = 3.0;
    max = -4.0;
    printf("Szám: ");
    scanf("%lf", &be);
    while (be != 0.0) {
        if (be > 0.0 && be < min) {
            min = be;
        }
        else if (be < 0.0 && be > max) {
            max = be;
        }
        printf("Szám: ");
        scanf("%lf", &be);
    }
    printf("Összeg: %lf", min + max);
    return 0;
}
