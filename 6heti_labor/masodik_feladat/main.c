#include <stdio.h>


void kocka_terulet(double a, double* felulet, double* terfogat) {
    *felulet = 6*a*a;
    *terfogat = a*a*a;
}

int main(void) {
    double a = 2.7;
    double felulet = 0.0;
    double terfogat = 0.0;
    kocka_terulet(a, &felulet, &terfogat);
    printf("felület: %lf\ntérfogat: %lf", felulet, terfogat);
    return 0;
}
