#include <stdio.h>
#include <stdlib.h>


char* string_darabjainak_elhagyasa(char* string, int also, int felso)
{
    if (also < 0)  also = 0;
    char* cpy = malloc((felso-also + 1)*sizeof(char));
    int i;
    for (i = also; &(string[i]) != &(string[felso]) && string[i] != '\0' ;i++)
    {
        cpy[i-also] = string[i];
    }
    cpy[i] = '\0';
    return cpy;
}

int main(void)
{
    char* str = string_darabjainak_elhagyasa("Hello, World!\n", -1,15);
    printf("str: %s\n", str);

    return 0;
}
