#include <stdio.h>
#include <stdbool.h>

void trimmer(char str[], char* str2){
    int index = 0;
    int index2 = 0;
    int lengthOfString = 0;
    while (str[index] == ' ' || str[index] != '\0') {
        if (str[index] != ' ') {
            *(str2+index2) = str[index];
            index2++;
        }
        index++;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        bool control = true;
        if (str[i] == ' ') {
            for (int k = i; str[k]!='\0'; k++) {
                if (str[k] != ' ') control = false;
            }
        }else control = false;
        if (control) return;

    }
}

int main(void) {
    char str1[50] =  "  helló, mizu?       ";
    char str2[50] = "";
    trimmer(str1, &str2[0]);
    for (int i = 0; str1[i] != '\0'; i++) {
        printf("%c\n", str1[i]);
    }
    printf("----\n");
    for (int i = 0; str2[i] != '\0'; i++) {
        printf("%c\n", str2[i]);
    }
    //printf("%s\n", str2);
    return 0;
}
