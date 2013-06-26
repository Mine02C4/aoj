#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
    int i, hills[10];
    for (i=0; i<10; i++) {
        scanf("%d", &hills[i]);
    }
    sort(hills, hills + 10, greater<int>());
    printf("%d\n%d\n%d\n", hills[0], hills[1], hills[2]);
    return 0;
}
