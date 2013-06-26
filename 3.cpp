#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int N, i;
    long edges[3];
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        scanf("%ld %ld %ld", &edges[0], &edges[1], &edges[2]);
        sort(edges, edges + 3);
        if (edges[0] * edges[0] + edges[1] * edges[1] == edges[2] * edges[2])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
