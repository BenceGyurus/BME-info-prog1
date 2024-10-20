#include <stdio.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 0; i<n;i++) {
        for (int k = 0; k <= n; k++) {
            if (k == n-(i+1)) printf("/");
            else if (k == n) printf("|");
            else printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        printf("-");
    }
    printf("+");
    return 0;
}