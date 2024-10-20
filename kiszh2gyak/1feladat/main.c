#include <stdio.h>

int main(void) {
    char ch;
    int a;
    int sorszam = 1;
    printf("%d", scanf("%d", &a));
    while (scanf("%c", &ch)==1 && ch!='.') {
        int i;
        for (i = 2; sorszam%i!=0 && i<sorszam; i += 1)
            /*üres*/;
        if (sorszam == i)
            printf("%c", ch);
        sorszam++;
    }
    return 0;
}