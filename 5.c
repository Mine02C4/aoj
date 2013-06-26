#include <stdio.h>

unsigned long gcd(unsigned long a, unsigned long b) {
    unsigned long remainder;
    while ((remainder = a % b) != 0) {
        a = b;
        b = remainder;
    }
    return b;
}

int main() {
    unsigned long a, b, c;
    while (scanf("%lu %lu", &a, &b) != EOF) {
        c = gcd(a, b);
        printf("%lu %lu\n", c, a / c * b);
    }
    return 0;
}
