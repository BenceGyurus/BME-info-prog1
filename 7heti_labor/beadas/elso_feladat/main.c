#include <stdio.h>


int fibonacci(int i) {
    if ( i == 1) {
        return 1;
    }
    else if (i == 2) {
        return 1;
    }
    else {
        return fibonacci(i-1) + fibonacci(i-2);
    }
}

int main(void)
{
    printf("%d\n", fibonacci(1));
    printf("%d\n", fibonacci(2));
    printf("%d\n", fibonacci(3));
    printf("%d\n", fibonacci(4));
    printf("%d\n", fibonacci(5));
    printf("%d\n", fibonacci(6));
    return 0;
}
