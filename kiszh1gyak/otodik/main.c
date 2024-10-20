#include <stdio.h>

int main(void) {
    int n, szam, max = 0;
    printf("Mennyi? hm? \n");
    scanf("%d", &n);
    while (n != 0) {
        printf("szám? hm? \n");
        scanf("%d", &szam);
        if (szam < 25 && max < szam) max = szam;
        n--;
    }
    printf("%d\n", max);
    return 0;
}
