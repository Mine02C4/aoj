#include <stdio.h>

long result,x;

int main() {
    int n,i;
    result = 100000;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        result *= 1.05;
        if ((x = result % 1000) != 0)
            result += 1000 - x;
    }
    printf("%ld\n", result);
    return 0;
}
