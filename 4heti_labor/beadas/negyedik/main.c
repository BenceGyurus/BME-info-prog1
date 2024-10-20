#include <stdio.h>
#include <math.h>
int main(void) {
    unsigned long long int n = 1;
    int i = 0;
    while (n>=1) {
        i++;n<<=i;
    }
    printf("%d\n", i);
    return 0;
}
