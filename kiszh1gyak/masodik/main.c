#include <stdio.h>

int main(void) {
    int be, huszonkettedik, sum = 0, index = 0;
    printf("Szám:");
    scanf("%d", &be);
    while (be != 0) {
        index++;
        if (index == 22) {
            huszonkettedik = be;
        }
        sum += be;
        printf("Szám:");
        scanf("%d", &be);
    }
    printf("%d\n", huszonkettedik-(sum/index));
    return 0;
}
