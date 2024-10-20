#include <stdio.h>

void csoportositas(int szam) {
    if (szam > 0) {
        csoportositas(szam/1000);
        printf("%d ", szam%1000);
    }

}


int main(void) {
    csoportositas(9910230999);
    return 0;
}