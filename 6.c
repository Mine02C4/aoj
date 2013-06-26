#include <stdio.h>
#include <string.h>

void reverse(char* str) {
    int n,i;
    char c;
    n = strlen(str);
    for (i=0; i<n/2; i++) {
        c = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = c;
    }
}

int main () {
    char str[21];
    scanf("%s", str);
    reverse(str);
    printf("%s\n", str);
    return 0;
}
