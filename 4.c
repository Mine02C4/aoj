#include <stdio.h>
#include <math.h>

double _round(double val) {
    return round(val * pow(10, 3)) * pow(10, -3);
}

double fix(double val) {
    if (val == -0.0)
        return 0.0;
    else
        return val;
}

int main() {
    double a, b, c, d, e, f, x, y;
    while (scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &e, &f) != EOF) {
        x = _round((c * e - b * f)/(a * e - b * d));
        y = _round((a * f - d * c)/(a * e - b * d));
        printf("%.3f %.3f\n", fix(x), fix(y));
    }
    return 0;
}
