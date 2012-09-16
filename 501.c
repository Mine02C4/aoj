#include <stdio.h>

int main() {
    char table[256],a,b;
    int n,m,i;
    while (1) {
        scanf("%d", &n);
        if (n==0) return 0;
        for (i=0;i<256;i++)
            table[i]=i;
        for (i=0;i<n;i++) {
            scanf(" %c %c",&a,&b);
            table[a] = b;
        }
        scanf("%d", &m);
        for (i=0;i<m;i++) {
            scanf(" %c", &a);
            printf("%c", table[a]);
        }
        printf("\n");
    }
    return 0;
}
