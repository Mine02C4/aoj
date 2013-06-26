#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef struct Rectangle {
    int x_left, x_right, y_bottom, y_top;
} StructRectangle;

StructRectangle* rectangle_list[10001];
StructRectangle* rectangle_area;
int scan_line[3][10001];
int filled_scan_line[3][10001];
vector<Rectangle*> scannig_rectangles;

int sort_rectangles_by_x_left(const void * a , const void * b) {
    int x_left_a = (*(StructRectangle**)a)->x_left;
    int x_left_b = (*(StructRectangle**)b)->x_left;
    if (x_left_a < x_left_b) {
        return -1;
    } else if(x_left_a == x_left_b) {
        return 0;
    } else {
        return 1;
    }
}

int main() {
    int n,r,i,j,unread_rectangle_list_head,number_buffer,area_result,perimeter_result;
    rectangle_area = (Rectangle*)malloc(10001*sizeof(Rectangle));
    scannig_rectangles.reserve(10001);
    while (1) {
        scanf("%d %d", &n, &r);
        if (n==0) return 0;
        for (i=0;i<10001;i++) {
            scan_line[0][i] = 0;
            scan_line[1][i] = 0;
            filled_scan_line[0][i] = 0;
        }
        area_result = 0;
        perimeter_result = 0;
        for (i=0;i<n;i++) {
            rectangle_list[i] = rectangle_area + i;
            scanf("%d %d %d %d",
                &rectangle_list[i]->x_left, &rectangle_list[i]->y_bottom, &rectangle_list[i]->x_right, &rectangle_list[i]->y_top);
        }
        qsort((void*)rectangle_list, n, sizeof(StructRectangle*), sort_rectangles_by_x_left);
        unread_rectangle_list_head = 0;
        while (unread_rectangle_list_head<n) {
            if (rectangle_list[unread_rectangle_list_head]->x_left == 0) {
                scannig_rectangles.push_back(rectangle_list[unread_rectangle_list_head]);
                scan_line[1][rectangle_list[unread_rectangle_list_head]->y_bottom]++;
                scan_line[1][rectangle_list[unread_rectangle_list_head]->y_top]--;
                unread_rectangle_list_head++;
            } else if (rectangle_list[unread_rectangle_list_head]->x_left > 0) {
                break;
            }
        }
        if (r == 2) {
            number_buffer = 0;
            for (j=0;j<10001;j++) {
                number_buffer += scan_line[1][j];
                filled_scan_line[1][j] = number_buffer;
            }
        }
        for (i=0;i<10000;i++) {
            for (j=0;j<10001;j++) {
                scan_line[(i+2)%3][j] = scan_line[(i+1)%3][j];
            }
            while (unread_rectangle_list_head<n) {
                if (rectangle_list[unread_rectangle_list_head]->x_left == (i+1)) {
                    scannig_rectangles.push_back(rectangle_list[unread_rectangle_list_head]);
                    scan_line[(i+2)%3][rectangle_list[unread_rectangle_list_head]->y_bottom]++;
                    scan_line[(i+2)%3][rectangle_list[unread_rectangle_list_head]->y_top]--;
                    unread_rectangle_list_head++;
                } else if (rectangle_list[unread_rectangle_list_head]->x_left > (i+1)) {
                    break;
                }
            }
            for (vector<Rectangle*>::iterator itr = scannig_rectangles.begin();itr != scannig_rectangles.end();) {
                if ((*itr)->x_right == (i+1)) {
                    scan_line[(i+2)%3][(*itr)->y_bottom]--;
                    scan_line[(i+2)%3][(*itr)->y_top]++;
                    itr = scannig_rectangles.erase(itr);
                } else {
                    itr++;
                }
            }
            number_buffer = 0;
            if (r == 2) {
                for (j=0;j<10000;j++) {
                    number_buffer += scan_line[(i+2)%3][j];
                    filled_scan_line[(i+2)%3][j] = number_buffer;
                    if (filled_scan_line[(i+1)%3][j] > 0) {
                        area_result++;
                        if (filled_scan_line[i%3][j] == 0)
                            perimeter_result++;
                        if (filled_scan_line[(i+2)%3][j] == 0)
                            perimeter_result++;
                        if (filled_scan_line[(i+1)%3][j+1] == 0)
                            perimeter_result++;
                        if (j == 0||filled_scan_line[(i+1)%3][j-1] == 0)
                            perimeter_result++;
                    }
                }
            } else {
                for (j=0;j<10000;j++) {
                    number_buffer += scan_line[(i+1)%3][j];
                    if (number_buffer > 0) {
                        area_result++;
                    }
                }
            }
        }
        printf("%d\n", area_result);
        if (r == 2) printf("%d\n", perimeter_result);
    }
}
