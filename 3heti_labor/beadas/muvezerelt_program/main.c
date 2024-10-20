#include <stdio.h>

int alap(void) {
    return 1;
}

int hozzaad(int a) {
    return a+1;
}

int elojel(int a) {
    return -a;
}

int szorzas(int a) {
    return a*2;
}

int main(void) {

    int a = 1;
    int feladat;

    do {
        printf("A értéke: %d\n", a);
        printf("0. Alapertek visszaallitasa (a = 1)\n"
      "1. Hozzaad 1-et\n"
      "2. Megforditja az elojelet\n"
      "3. Szorozza 2-vel\n"
      "9. Kilepes\n");
        scanf("%d", &feladat);

        switch (feladat) {
            case 0: a=alap(); break;
            case 1: a=hozzaad(a); break;
            case 2: a=elojel(a); break;
            case 3: a=szorzas(a); break;
        }

    }
    while (feladat != 9);

    return 0;
}
