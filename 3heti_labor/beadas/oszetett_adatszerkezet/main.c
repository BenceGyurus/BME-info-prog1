#include <stdio.h>

typedef struct Datum {
    int ev, ho, nap;
} Datum;

typedef struct Versenyzo {
    char nev[31];
    Datum szuletes;
    int helyezes;
} Versenyzo;

void datum_kiir(Datum d) {
    printf("%d. %d. %d.\n", d.ev, d.ho, d.nap);
};

void versenyzo_kiir(Versenyzo v) {
    printf("Neve: %s\n", v.nev);
    printf("Szuletes: ");
    datum_kiir(v.szuletes);
    printf("Helyezés: %d. helyezett\n", v.helyezes);
};

int main() {
    Versenyzo versenyzok[5] = {
        { "Am Erika", {1984, 5, 6}, 1 },
        { "Break Elek", {1982, 9, 30}, 3 },
        { "Dil Emma", {1988, 8, 25}, 2 },
        { "Kasza Blanka", {1979, 6, 10}, 5 },
        { "Reset Elek", {1992, 4, 5}, 4 },
    };

    printf("0-s versenyző neve: %s\n", versenyzok[0].nev);
    printf("2-es versenyző helyezése: %d\n", versenyzok[1].helyezes);
    printf("4-es versenyző születési dátuma:");
    datum_kiir(versenyzok[4].szuletes);
    printf("1-es versenyző nevének kezdőbetűje: %c\n", versenyzok[1].nev[0]);
    printf("az 1-es versenyző dobogós-e? %s\n", versenyzok[1].helyezes <= 3 ? "Igen" : "Nem");
    printf("az 4-es versenyző gyorsabb-e, mint a 3-as versenyző?: %s\n", versenyzok[4].helyezes < versenyzok[3].helyezes ? "Igen" : "Nem");
    printf("az 1-es versenyző ugyanabban az évben született-e, mint a 2-es? %s\n", versenyzok[1].szuletes.ev == versenyzok[2].szuletes.ev ? "Igen" : "Nem");
    versenyzo_kiir(versenyzok[1]);
    for (int i = 0; i < 5; i++) {
        printf("Versenyző sorszáma: %d\n", i);
        versenyzo_kiir(versenyzok[i]);
        printf("\n------\n\n");
    }

    return 0;
}
