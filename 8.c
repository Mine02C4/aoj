#include <stdio.h>

int x[4],n,result;

void search(int i) {
    for (x[i]=0; x[i]<10; x[i]++) {
        if (i == 3) {
            if (x[0] + x[1] + x[2] + x[3] == n)
                result++;
        }
        else
            search(i+1);
    }
}

int main() {
    while (scanf("%d", &n) != EOF) {
        result = 0;
        search(0);
        printf("%d\n", result);
    }
    return 0;
}
