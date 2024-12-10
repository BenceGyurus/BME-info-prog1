#include <stdio.h>
 
int main() {
    typedef enum GondolatAll { szoveg, lehet, gondolat, vege } GondolatAll;
    int c;
    GondolatAll allapot = szoveg;
    
    while ((c = getchar()) != EOF) {
        switch (allapot) {
            case szoveg:
                if (c == ' ') allapot = lehet;
                else putchar(c);
                break;
            case lehet:
                if (c == ' ') putchar(' ');
                else if (c == '-') allapot = gondolat;
                else { putchar(' '); putchar(c); allapot = szoveg; }
                break;
            case gondolat:
                if (c == ' ') allapot = vege;
                break;
            case vege:
                if (c == ' ') /* semmi */;
                else if (c == '-') allapot = szoveg;
                else allapot = gondolat;
                break;
        }
    }
    
    return 0;
}
