#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*typedef struct Vendeg {
    char nev[50+1];
    int szobaszam;
} Vendeg;

int emelet(Vendeg v) {
    return v.szobaszam / 100;
}

Vendeg *keres(Vendeg vendegek[], int meret, char *nev) {
    for (int i = 0; i < meret; ++i)
        if (strcmp(vendegek[i].nev, nev) == 0)
            return &vendegek[i];
    return NULL;
}

void betoltottseg(Vendeg vendegek[], int meret, int *szintek) {
    for (int i = 0; i <= 7; ++i)
        szintek[i] = 0;
    for (int i = 0; i < meret; ++i)
        szintek[emelet(vendegek[i])] += 1;
}

int legtobb_vendeg(Vendeg vendegek[], int meret) {
    int szintek[8];
    betoltottseg(vendegek, meret, &szintek);
    int max = 0;
    for (int i = 1; i < 8; ++i)
        if (szintek[i] > szintek[max])
            max = i;
    return max;
}*/

bool palindrome(char* s) {
    int length = strlen(s);
    for (int i = 0; i < (length) / 2; i++) {
        if (s[i] != s[length - (i + 1)]) return false;
    }
    return true;
}

int main(void) {

    printf("%s", palindrome("kek") ? "YES" : "NO");

    /*Vendeg vengek[8] = {
        {"", 201},
        {"",302},
        {"", 403},
        {"", 504},
        {"", 505},
        {"", 506},
        {"", 207},
        {"", 308},
    };*/
    /*char string[100] = "kutya";
    printf("%d\n", strlen(string));
    //printf("%d\n", legtobb_vendeg(vengek, 8));
    return 0;*/
}
