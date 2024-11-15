#include <stdio.h>
#include <stdlib.h>

typedef struct BiFa {
    int ertek;
    struct BiFa *bal, *jobb;
} BiFa;

BiFa *beszur(BiFa *gyoker, int ertek) {
    if (gyoker == NULL) {
        BiFa *uj = (BiFa*) malloc(sizeof(BiFa));
        uj->ertek = ertek;
        uj->bal = uj->jobb = NULL;
        return uj;
    }
    if (ertek < gyoker->ertek) {        /* balra szur */
        gyoker->bal = beszur(gyoker->bal, ertek);
    }
    else if (ertek > gyoker->ertek) {   /* jobbra szur */
        gyoker->jobb = beszur(gyoker->jobb, ertek);
    }
    else {
        /* mar benne van */
    }
    return gyoker;
}

void inOrderPrint(BiFa *ag)
{
    if (ag->bal != NULL) { inOrderPrint(ag->bal); }
    printf("%d\n", ag->ertek);
    if (ag->jobb != NULL) { inOrderPrint(ag->jobb); }
}


int fa_Hossz(BiFa *ag, int hossz)
{
    if (ag->bal != NULL) { hossz = fa_Hossz(ag->bal, hossz);}
    if (ag->jobb != NULL) { hossz = fa_Hossz(ag->jobb, hossz);}
    hossz++;
    return hossz;
}

BiFa *keres(BiFa *gyoker, int adat) {
    BiFa *mozgo = gyoker;
    while (mozgo != NULL && mozgo->ertek != adat) {
        if (adat > mozgo->ertek) mozgo = mozgo->bal;
        else mozgo = mozgo->jobb;
    }
    return mozgo;
}

void invert(BiFa *ag)
{
    if (ag->bal != NULL) { invert(ag->bal); }
    if (ag->jobb != NULL) { invert(ag->jobb); }
    ag->ertek = -1*ag->ertek;
}

void  tukroz(BiFa *ag)
{
    if (ag->bal != NULL) { tukroz(ag->bal); }
    if (ag->jobb != NULL) { tukroz(ag->jobb); }
    BiFa* temp = ag->jobb;
    ag->jobb = ag->bal;
    ag->bal = temp;
}

int main(void) {
    int minta[] = {15, 96, 34, 12, 14, 56, 21, 11, 10, 9, 78, 43, 0};
    BiFa *gyoker = NULL;
    for (int i = 0; minta[i] > 0; i++)
        gyoker = beszur(gyoker, minta[i]);

    /* Ide tedd be a kipróbálandó függvények hívásait! */
    inOrderPrint(gyoker);
    invert(gyoker);
    tukroz(gyoker);
    inOrderPrint(gyoker);
    printf("Keres:%p\n", keres(gyoker, 96));
    //printf("Hossz: %d", fa_Hossz(gyoker, 0));
    return 0;
}