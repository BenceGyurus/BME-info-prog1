#include <stdio.h>

int* find_number(int array[], int meret, int number) {
    for (int i = 0; i < meret; i++) {
        if (array[i] == number) return &array[i];
    }
    return NULL;
}


int main(void) {
    int tomb[10] = {1,2,3,46,7,34,34,51,42,3413};
    printf("%ld\n", find_number(tomb,10, 34) - &tomb[0]);
    for (int* i = &tomb[0]; i < &tomb[9]; i++) {
        printf("[%p] = %d\n",i, *i);
    }
    return 0;
}
