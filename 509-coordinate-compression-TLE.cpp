#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

int x_convert[10001],y_convert[10001],x_reverse_convert[10001],y_reverse_convert[10001],
    x_left[10001],x_right[10001],y_bottom[10001],y_top[10001],x_sorted[20002],y_sorted[20002];

char table[12502501];

using namespace std;

void set_table(int pos) {
    table[pos/8] |= (1 << (pos%8));
}

int get_table(int pos) {
    if((table[pos/8]&(1 << (pos%8)))==0) {
        return 0;
    } else {
        return -1;
    }
}

int main() {
    int n,r,i,j,k,x_sorted_size,y_sorted_size,area,perimeter;
    int* ptr;
    while (1) {
        scanf("%d %d", &n, &r);
        if (n==0) return 0;
        area = 0;
        for (i=0;i<n;i++) {
            scanf("%d %d %d %d", &x_left[i], &y_bottom[i], &x_right[i], &y_top[i]);
            x_sorted[i*2] = x_left[i];
            x_sorted[i*2+1] = x_right[i];
            y_sorted[i*2] = y_bottom[i];
            y_sorted[i*2+1] = y_top[i];
        }
        sort(x_sorted, x_sorted+n*2);
        ptr = unique(x_sorted, x_sorted+n*2);
        x_sorted_size = ptr - x_sorted;
        sort(y_sorted, y_sorted+n*2);
        ptr = unique(y_sorted, y_sorted+n*2);
        y_sorted_size = ptr - y_sorted;
        for (i=0;i<x_sorted_size;i++) {
            x_convert[x_sorted[i]] = i;
            x_reverse_convert[i] = x_sorted[i];
        }
        for (i=0;i<y_sorted_size;i++) {
            y_convert[y_sorted[i]] = i;
            y_reverse_convert[i] = y_sorted[i];
        }
        memset(table, 0, x_sorted_size*y_sorted_size/8+1);
        for (i=0;i<n;i++) {
            for (j=x_convert[x_left[i]];j<x_convert[x_right[i]];j++) {
                for (k=y_convert[y_bottom[i]];k<y_convert[y_top[i]];k++) {
                    set_table(j*y_sorted_size+k);
                }
            }
        }
        for (i=0;i<x_sorted_size;i++) {
            for (j=0;j<y_sorted_size;j++) {
                if (get_table(i*y_sorted_size+j) == -1) {
                    area += (x_reverse_convert[i+1] - x_reverse_convert[i]) * (y_reverse_convert[j+1] - y_reverse_convert[j]);
                }
            }
        }
        printf("%d\n", area);
        if (r == 2) {
            perimeter = 0;
            for (i=0;i<x_sorted_size;i++) {
                for (j=0;j<y_sorted_size;j++) {
                    if (get_table(i*y_sorted_size+j) == -1) {
                        if (i==0||get_table((i-1)*y_sorted_size+j)==0) {
                            perimeter += y_reverse_convert[j+1] - y_reverse_convert[j];
                        }
                        if (i==x_sorted_size-1||get_table((i+1)*y_sorted_size+j)==0) {
                            perimeter += y_reverse_convert[j+1] - y_reverse_convert[j];
                        }
                        if (j==0||get_table(i*y_sorted_size+j-1)==0) {
                            perimeter += x_reverse_convert[i+1] - x_reverse_convert[i];
                        }
                        if (j==y_sorted_size-1||get_table(i*y_sorted_size+j+1)==0) {
                            perimeter += x_reverse_convert[i+1] - x_reverse_convert[i];
                        }
                    }
                }
            }
            printf("%d\n", perimeter);
        }
    }
}
