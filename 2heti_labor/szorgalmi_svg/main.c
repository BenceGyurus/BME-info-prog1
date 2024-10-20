#include <stdio.h>
#include <math.h>

int main(void) {
    double secs, mins, hours;
    int width = 300;
    int height = 300;
    double PI = 3.14159265359;

    scanf("%lf %lf %lf", &hours, &mins, &secs);
    FILE* fp;
    fp = fopen("ora.svg", "w");
    if (fp != NULL) {
        fprintf(fp, "<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">", width, height);
        fprintf(fp, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"#ffffff\" stroke=\"#333333\" stroke-width=\"8\" />", width/2, height/2, width/2-10);
        fprintf(fp, "<g stroke=\"#333333\" stroke-width=\"3\">");
        fprintf(fp, "\n\t<line x1=\"150\" y1=\"30\" x2=\"150\" y2=\"50\"/>");
        fprintf(fp, "\n\t\t<line x1=\"150\" y1=\"250\" x2=\"150\" y2=\"270\"/>");
        fprintf(fp, "\n\t\t<line x1=\"30\" y1=\"150\" x2=\"50\" y2=\"150\"/>");
        fprintf(fp, "\n\t\t<line x1=\"250\" y1=\"150\" x2=\"270\" y2=\"150\"/>");
        fprintf(fp, "\n\t\t<line x1=\"200\" y1=\"49\" x2=\"205\" y2=\"61\"/>");
        fprintf(fp, "\n\t\t<line x1=\"250\" y1=\"100\" x2=\"261\" y2=\"105\"/>");
        fprintf(fp, "\n\t\t<line x1=\"251\" y1=\"200\" x2=\"261\" y2=\"195\"/>");
        fprintf(fp, "\n\t\t<line x1=\"200\" y1=\"251\" x2=\"205\" y2=\"239\"/>");
        fprintf(fp, "\n\t\t<line x1=\"100\" y1=\"251\" x2=\"95\" y2=\"239\"/>");
        fprintf(fp, "\n\t\t<line x1=\"49\" y1=\"200\" x2=\"39\" y2=\"195\"/>");
        fprintf(fp, "\n\t\t<line x1=\"49\" y1=\"100\" x2=\"39\" y2=\"105\"/>");
        fprintf(fp, "\n\t\t<line x1=\"100\" y1=\"49\" x2=\"95\" y2=\"61\"/>");
        fprintf(fp, "\n\t</g>");
        fprintf(fp, "\n\t<line x1=\"%d\" y1=\"%d\" x2=\"%lf\" y2=\"%lf\"  stroke=\"#ff5555\" stroke-width=\"2\" stroke-linecap=\"round\" />", width/2, height/2, ((cos(2 * PI * (secs / 60) - PI / 2))*((width/2)-20))+width/2.0 , ((sin(2 * PI * (secs / 60) - PI / 2))*((height/2)-20))+height/2.0);
        fprintf(fp, "\n\t<line x1=\"%d\" y1=\"%d\" x2=\"%lf\" y2=\"%lf\" stroke=\"#555555\" stroke-width=\"5\" stroke-linecap=\"round\" />", width/2, height/2, ((cos(2 * PI * ((mins*60+secs) / (60*60)) - PI / 2))*((width/2)*.8))+width/2.0 , ((sin(2 * PI * ((mins*60+secs) / (60*60)) - PI / 2))*((height/2)*.8))+height/2.0);
        fprintf(fp, "\n\t<line x1=\"%d\" y1=\"%d\" x2=\"%lf\" y2=\"%lf\" stroke=\"#333333\" stroke-width=\"8\" stroke-linecap=\"round\" />", width/2, height/2, (cos(2 * PI * ((hours*60+mins) / (12*60)) - PI / 2)*((width/2)*0.6))+width/2.0 , ((sin(2 * PI * ((hours*60+mins) / (12*60)) - PI / 2))*((height/2)*.6))+height/2.0);
        fprintf(fp, "\n\t<circle cx=\"150\" cy=\"150\" r=\"5\" fill=\"#333333\"/>");
        fprintf(fp, "\n</svg>");
        fclose(fp);
    }
    else {
        perror("Hiba történt");
    }

    return 0;
}
