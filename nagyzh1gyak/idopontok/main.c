#include <stdio.h>

typedef struct Idopont {
    int ora;
    int perc;
    int masodperc;
} Idopont;

Idopont konvert_idopont(int string_idopont[]) {
    Idopont idopont;
    char isAm[2] = "";
    if (sscanf(string_idopont, "%d:%d:%d", &idopont.ora, &idopont.perc, &idopont.masodperc) == 3) return idopont;
    else if (sscanf(string_idopont, "%dh %dm %ds", &idopont.ora, &idopont.perc, &idopont.masodperc) == 3) return idopont;
    else {
        sscanf(string_idopont, "%d:%d %s", &idopont.ora, &idopont.perc, &isAm);
        if (isAm[0] != 'A') idopont.ora += 12; idopont.masodperc = 0; return idopont;
    };
}


int main(void) {
    char idopont1[] = "23:17:06";
    Idopont eredmeny = konvert_idopont(idopont1);
    printf("%d:%d:%d\n", eredmeny.ora, eredmeny.perc, eredmeny.masodperc);
    return 0;
}
