#include <stdio.h>

int main(void) {
    char text[10] ={ 'P', 'i', 't', 'a', 'g', 'o', 'r', 'a', 's', 'z' };
    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 10; i++) {
            printf("%c ", text[i]);
        }
        int j = 1;
        char l = text[0];
        while (j < 10) {
            text[j - 1] = text[j];
            j++;
        }
        text[9] = l;
        printf("\n");
    }
    return 0;
}
