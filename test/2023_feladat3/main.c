#include <stdio.h>
#include <stdlib.h>

typedef struct Lista{
	int alap;
	int kitevo;
	struct Lista* kov;
} Lista;


void kiir(Lista* lista){
	for (Lista* i = lista; i != NULL; i = i->kov){
		if (i != lista) printf("*");
		printf("%d^%d", i->alap, i->kitevo);
	}
}

void hozzafuz(Lista* ptr, int alap, int kitevo){
	Lista* i = ptr;
	for (; i != NULL; i = i->kov){}
	i = malloc(sizeof(Lista));
	i->alap = alap;
	i->kitevo = kitevo;

}

int main(){
	Lista* lista = malloc(sizeof(Lista));
	hozzafuz(lista,1,2);
	hozzafuz(lista,2,3);
	kiir(lista);
	return 0;

}
