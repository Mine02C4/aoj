#include <stdio.h>

int main() {
    int a,b,result;
    char op;
    while (1) {
        scanf("%d %c %d", &a, &op, &b);
        switch (op) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            default:
                return 0;
                break;
        }
        printf("%d\n", result);
    }
}
