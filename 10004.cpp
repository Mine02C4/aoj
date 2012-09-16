#include <stdio.h>
#include <algorithm>

int main() {
    using namespace std;    
    int input[3];
    scanf("%d %d %d", &input[0], &input[1], &input[2]);
    sort(input, input + 3);
    printf("%d %d %d\n", input[0], input[1], input[2]);
    return 0;
}
