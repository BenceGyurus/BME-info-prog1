#include <stdio.h>
#include <stdbool.h>


bool maganhangzo(char betu) {
    return (betu == 'A' || betu == 'a' || betu == 'E' || betu == 'e' || betu == 'I' || betu == 'i' || betu == 'O' || betu == 'o' || betu == 'U' || betu == 'u' );
}

char getChar(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a'-'A');
    }
    return c;

}

int main(void) {
    char c;
    while (scanf("%c", &c) != EOF) {
        if (maganhangzo(c))
            printf("%cv%c",  c, getChar(c));
        else
            printf("%c", c);
    }

    return 0;
}