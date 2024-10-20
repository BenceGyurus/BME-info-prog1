#include <stdio.h>

int main(void) {
    int array[10] = {25, 69, 54, 8, 77, 6, 29, 10, 3 ,98};
    int lengthOfArray = 10;
    for (int i = 0; i < lengthOfArray; i++ ) {
        printf("%d ", array[i]);
    }

    printf("\n");

    int min = array[0];

    for (int i = 0; i < lengthOfArray; i++ ) {
        if (array[i] < min) {min = array[i];}
        printf("%d=[%d] ",i, array[i]);
    }

    printf("\nmin: %d", min);
    printf("\nJelölve: ");

    for (int i = 0; i < lengthOfArray; i++ ) {
        if (array[i] < min) {min = array[i];}
        if (array[i] != min)printf("%d ", array[i]);
        else printf("%d[MIN] ", array[i]);
    }

    return 0;
}
