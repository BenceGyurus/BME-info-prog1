#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

typedef struct ListaElem {
    int adat;
    struct ListaElem *kov;
} ListaElem;


/* létrehoz egy listát, benne egy csomó számmal */
ListaElem *lista_letrehoz(void) {
    int szamok[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, 11, 2,
                     15, 9, 10, 6, 22, 4, 7, 18, 27, -1 };
    ListaElem *lis = NULL;

    for (int i = 0; szamok[i] != -1; ++i) {
        ListaElem *u;
        u = (ListaElem*) malloc(sizeof(ListaElem));
        u->kov = lis;
        u->adat = szamok[i];
        lis = u;
    }
    return lis;
}


int lista_Hossza(ListaElem *elso)
{
    int count = 0;
    for (ListaElem* i = elso; i != NULL; i = i->kov) {count++;}
    return count;
}


void lista_felszabadit(ListaElem* elso)
{

    ListaElem *u = elso;
    while (u != NULL)
    {
        ListaElem *kov = u->kov;
        free(u);
        u = kov;
    }
}

ListaElem* lista_elejere_beszur(ListaElem* elso, int adat){
    ListaElem *uj_elso = malloc(sizeof(ListaElem));
    uj_elso->adat = adat;
    uj_elso->kov = elso;
    return uj_elso;
}

void lista_Kiir(ListaElem* eleje)
{
    for (ListaElem *u = eleje; u; u = u->kov)
    {
        printf("%d ", u->adat);
    }
}

ListaElem* lista_vegehez_hozzafuz(ListaElem* eleje, int uj_adat)
{
    ListaElem* uj_elem = malloc(sizeof(ListaElem));
    uj_elem->adat = uj_adat;
    uj_elem->kov = NULL;
    if (eleje == NULL)
    {
        return uj_elem;
    }
    ListaElem* elozo = eleje;
    while (elozo->kov != NULL)
    {
        elozo = elozo->kov;
    }
    elozo->kov = uj_elem;
    return eleje;
}

ListaElem* kereses(ListaElem* elso, int adat)
{
    for (ListaElem *iter = elso; iter != NULL; iter = iter->kov)
    {
        if (iter->adat == adat) return iter;
    }
    return NULL;
}


int main(void) {
    ListaElem *eleje;

    eleje = lista_letrehoz();
    lista_Kiir(eleje);
    printf("\n%d", lista_Hossza(eleje));
    eleje = lista_elejere_beszur(eleje, 1);
    eleje = lista_vegehez_hozzafuz(eleje, 1);
    printf("\n%p", kereses(eleje, 23));
    printf("\n");
    lista_Kiir(eleje);
    lista_felszabadit(eleje);
    return 0;
}