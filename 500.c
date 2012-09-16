#include <stdio.h>

int main() {
    int n,a,b,i,asum,bsum;
    while (1) {
        scanf("%d", &n);
        if (n==0) return 0;
        asum = 0; bsum = 0;
        for (i=0;i<n;i++) {
            scanf("%d %d", &a, &b);
            if (a > b)
                asum += a + b;
            else if (a < b)
                bsum += a + b;
            else {
                asum += a;
                bsum += b;
            }
        }
        printf("%d %d\n", asum, bsum);
    }
}
