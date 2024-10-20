#include <stdio.h>

void szamrendszer_valto(int szam, int rendszer) {
    if (szam >= 1) {
        szamrendszer_valto(szam/rendszer, rendszer);
        printf("%d", szam%rendszer);
    }

}


int main(void) {
    szamrendszer_valto(504, 2);
    return 0;
}
