#include <stdio.h>

int main(void) {
    int n, szam, min = 100;
    printf("Menny?");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("szám");
        scanf("%d", &szam);
        if (szam > 30 && szam < min) min = szam;
    }
    printf("%d\n", min);
    return 0;
}
