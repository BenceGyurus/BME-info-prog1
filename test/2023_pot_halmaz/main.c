#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Halmaz{
	int ertek;
	struct Halmaz* kov;
}Halmaz;


bool szerepel_E(Halmaz* halmaz, int ertek){
	for (Halmaz* i = halmaz; i != NULL; i = i->kov){
		if (i->ertek == ertek) return true;
	}
}

void bovit(Halmaz* halmaz, int uj_ertek){
	if (!szerepel_E(uj)){
		Halmaz* uj;
		uj->ertek = uj_ertek;
		uj->kov = NULL;
		if (halmaz->kov == NULL) halmaz->kov = uj;
		else{
			Halmaz* kov = halmaz;
			while (kov->kov != NULL){
				kov = kov->kov;	
			}
			kov->kov = uj;
		}
	}
}

Halmaz* metszet(Halmaz* halmaz1, Halmaz* halmaz2){
	Halmaz* uj_Halmaz = malloc(sizeof(Halmaz));
	for (Halmaz* i = halmaz1; i != NULL; i=i->kov){
		for (Halmaz* j = halmaz2; j != NULL; j = j->kov){
			if (i == j) bovit(uj_Halmaz, halmaz1, halmaz2);
		}
	}
	return uj_Halmaz;
}

