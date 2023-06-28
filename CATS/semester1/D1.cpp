#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

int main() {
    FILE* fin = fopen("input.txt", "r"),
        * fout = fopen("output.txt", "w");

    double xa, ya, 
           xb, yb, 
           x0, y0, 
           fi;

    double neue_xa, neue_ya,
           neue_xb, neue_yb;

    fscanf(fin, "%lf %lf", &xa, &ya);
    fscanf(fin, "%lf %lf", &xb, &yb);
    fscanf(fin, "%lf %lf", &x0, &y0);
    fscanf(fin, "%lf", &fi);

    xa -= x0;
    ya -= y0;
    xb -= x0;
    yb -= y0; // приведение к частному случаю ( центр в точке (0;0) )

    neue_xa = cos(M_PI * fi / 180) * xa - sin(M_PI * fi / 180) * ya;
    neue_ya = sin(M_PI * fi / 180) * xa + cos(M_PI * fi / 180) * ya;
    neue_xb = cos(M_PI * fi / 180) * xb - sin(M_PI * fi / 180) * yb;
    neue_yb = sin(M_PI * fi / 180) * xb + cos(M_PI * fi / 180) * yb; // формула с аналитической геометрии

    fprintf(fout, "%.9f %.9f %.9f %.9f", neue_xa + x0, neue_ya + y0, neue_xb + x0, neue_yb + y0);
} // осуждаю проблемы с точностью в подобных задачах
