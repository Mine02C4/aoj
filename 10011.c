#include <stdio.h>

int main() {
    int n, list[100], i;
    scanf("%d", &n);
    for (i=0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    for (i=n-1; i>=0; i--) {
        printf("%d", list[i]);
        if (i>0) printf(" ");
        else printf("\n");
    }
    return 0;
}
