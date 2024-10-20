#include <stdio.h>

int main(){
    //unsigned long int a = 29;
    int array[32] = {0};
    unsigned long szamok[24] = { 0, 0, 0, 0, 0, 0, 0, 268435424, 134217760,134217760,134217760,134217760,134217760,134217760,134217760,134217760, 268435424 };
    for (int j = 0; j < 24; j++) {
        for (int i = 0; i < 32; i++){
            array[i] = (1 & szamok[j]>>i);
        }
        for (int i = 31; i >= 0; i--) {
            printf("%c", array[i] ? '#' : ' ');
        }
        printf("\n");
    }
    return 0;
}
