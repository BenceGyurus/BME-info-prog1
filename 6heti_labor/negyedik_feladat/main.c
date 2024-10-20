#include <stdio.h>

int main(void) {
    char nev[50];
    scanf("%s", &nev);
    for (int i = 0; i < 50; i++) {
        if (nev[i] != '\0') printf("%c\n", nev[i]); else break;
    }
    return 0;
}
