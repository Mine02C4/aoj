#include <stdio.h>

char table[1000000];

int main() {
    long n,i,j,result;
    while (scanf("%ld", &n) != EOF) {
        result = 0;
        for (i=2; i<=n; i++) {
            table[i] = 0;
        }
        for (i=2; i<=n; i++) {
            if (table[i] == 0) {
                for (j=2; i*j<=n; j++) {
                    table[i*j] = 1;
                }
            }
        }
        for (i=2; i<=n; i++) {
            if (table[i] == 0)
                result++;
        }
        printf("%ld\n", result);
    }
    return 0;
}
