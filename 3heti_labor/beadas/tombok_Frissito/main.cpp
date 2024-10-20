#include <stdio.h>



int main(void) {
    double array[10] = { 2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8};
    int lengthOfArray = 10;
    int indexesOfNegativeNumbers[10];
    int index = 0;
    printf("Összesen %d szám van.\n", lengthOfArray);
    for (int i = 0; i < lengthOfArray; i++) {
        printf("[%d]=%g ", i, array[i]);
        if (array[i] < 0.0) {
            indexesOfNegativeNumbers[index] = i;
            index++;
        }
    }

    printf("\n\n");
    printf("Ebből %d szám negatív\n", index);

    for (int i = 0; i < index; i++) {
        printf("[%d]=%g ",indexesOfNegativeNumbers[i], array[indexesOfNegativeNumbers[i]]);
    }


    return 0;
}
