#include <stdio.h>

int main() {
    int a,b,s;
    while (1) {
        scanf("%d %d", &a, &b);
        if(a==0&&b==0) return 0;
        if(a>b) {
            s=a;a=b;b=s;
        }
        printf("%d %d\n", a, b);
    }
}
