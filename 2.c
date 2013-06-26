#include <stdio.h>
#include <math.h>

int main () {
    long a,b;
    while (scanf("%ld %ld", &a, &b) != EOF) {
        printf("%d\n", (int)log10(a+b) + 1);
    }
    return 0;
}
