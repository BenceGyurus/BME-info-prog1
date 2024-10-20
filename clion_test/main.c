#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    double a,b,c;

    printf("Masodfoku egyenlet egyutthatoi:\n\na=");
    scanf("%lf", &a);
    printf("b=");
    scanf("%lf", &b);
    printf("c=");
    scanf("%lf", &c);

    double d = b*b-4*a*c;

    if (d > 0){
        printf("\n2 valos megoldasa van");
    }else if (d == 0){
        printf("\n1 valos megoldasa van");
    }
    else{
        printf("\nNincs valos megoldasa");
    }

    return 0;
}
