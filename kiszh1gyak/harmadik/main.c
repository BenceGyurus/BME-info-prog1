#include <stdio.h>

int main(void) {
    int n;
    printf("Szám: ");
    scanf("%d", &n);
    printf("\n ");
    for (int i = 0; i < n; i++) {
        printf(" %d", i+1);
    }
    printf("\n");
    for (int i = 1; i <= n ; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%d ", i%j);
        }
        printf("\n");
    }
    return 0;
}
