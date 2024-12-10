#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int alap;
    int kitevo;
    struct Lista* kov;
} Lista;

void kiir(Lista* lista) {
    for (Lista* i = lista; i != NULL; i = i->kov) {
        if (i != lista) printf("*");
        printf("%d^%d", i->alap, i->kitevo);
    }
    printf("\n");
}

void hozzafuz(Lista* ptr, int alap, int kitevo) {
    Lista* i = ptr;
    while (i->kov != NULL) {
        i = i->kov;
    }
    i->kov = malloc(sizeof(Lista));
    i->kov->alap = alap;
    i->kov->kitevo = kitevo;
    i->kov->kov = NULL;
}

int main() {
    // Initialize the list with a dummy head node
    Lista* lista = malloc(sizeof(Lista));
    lista->alap = 0;  // Initial dummy values
    lista->kitevo = 0;
    lista->kov = NULL;

    hozzafuz(lista, 1, 2);
    hozzafuz(lista, 2, 3);

    kiir(lista->kov);  // Skip the dummy head node for printing

    // Free allocated memory (not shown for simplicity)
    return 0;
}

