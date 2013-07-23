#include <cstdio>

#define kMAX_PRECISION 10010

class Multiprecision {
public:
    char digits[kMAX_PRECISION];
    void init();
    void print(int);
    Multiprecision& operator+=(const Multiprecision&);
    Multiprecision& operator/=(int);
};

void Multiprecision::init() {
    digits[0] = 1;
    for (int i=1; i<kMAX_PRECISION; i++) {
        digits[i] = 0;
    }
}

Multiprecision& Multiprecision::operator+=(const Multiprecision& obj) {
    for (int i=kMAX_PRECISION-1; i>=0; i--) {
        digits[i] += obj.digits[i];
        if (digits[i] >= 10 && i > 0 ) {
            digits[i - 1]++;
            digits[i] %= 10;
        }
    }
    return *this;
}

Multiprecision& Multiprecision::operator/=(int d) {
    int i,a,b;
    b = 0;
    for (i=0; i<kMAX_PRECISION; i++) {
        b += digits[i];
        digits[i] = b / d;
        b %= d;
        b *= 10;
    }
    return *this;
}

void Multiprecision::print(int precision) {
    int i;
    printf("%d.", digits[0]);
    for (i=1; i<=precision; i++)
        printf("%d", digits[i]);
    printf("\n");
}

int main() {
    int n,k,m,r,i;
    Multiprecision result,buf;
    for (;;) {
        scanf("%d %d %d %d", &n, &k, &m, &r);
        if (n == 0) return 0;
        result.init();
        if (m == 0) {
            result /= n;
            result.print(r);
        } else {
            for (i=2; i<n; i++) {
                buf.init();
                buf /= i;
                result += buf;
            }
            result /= n;
            buf.init();
            buf /= n;
            result += buf;
            result.print(r);
        }
    }
}
