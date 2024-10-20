#include <stdio.h>


void rekurziv_vissza(int* tomb, int hossz) {
    if (hossz-1 >= 0) {
        printf("%d\n", tomb[hossz-1]);
        rekurziv_vissza(tomb, hossz-1);
    }
}

void rekurziv_elore(int* tomb, int hossz, int index) {
    if (index <= hossz-1) {
        printf("%d\n", tomb[index]);
        rekurziv_elore(tomb, hossz, index+1);
    }
}

void iterativ_vissza(int* tomb, int hossz) {
    for (int i = hossz-1; i <= 0; i--) {
        printf("%d\n", tomb[i]);
    }
}

void iterativ_elore(int* tomb, int hossz) {
    for (int i = 0; i < hossz; i++) {
        printf("%d\n", tomb[i]);
    }
}


int main(void) {
    int tomb[5]={1,2,3,4,5};
    rekurziv_vissza(tomb, 5);
    rekurziv_elore(tomb, 5, 0);
    iterativ_vissza(tomb, 5);
    iterativ_elore(tomb, 5);
    return 0;
}
