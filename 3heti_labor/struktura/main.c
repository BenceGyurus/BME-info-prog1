#include <stdio.h>


typedef struct Pontok {
    double x;
    double y;
} Pontok;


int main(void) {
    struct Pontok p1 = {2.2 , 1.6};
    double qx, qy;
    printf("Adja meg a pontokat: \n");
    scanf("%lf %lf", &qx, &qy);
    struct Pontok p2 = {qx, qy};
    struct Pontok p3 = {(p2.x+p1.x)/2.0, (p2.y+p1.y)/2.0};
    printf("x: %f, y: %f\n", p3.x, p3.y);
    return 0;
}
