#include <math.h>
#include <stdio.h>

double kob(double a) {
    return a*a*a;
};

double abszolut(double a) {
    return a<0?-a:a;
}

int main(void) {
    double a = 4.0;
    printf("%.4f %.4f %.4f", kob(a), abszolut(a), sin(a));
    return 0;
}
