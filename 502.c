#include <stdio.h>

enum {
    kTOP = 0,
    kBOTTOM,
    kNORTH,
    kSOUTH,
    kEAST,
    kWEST
};

char dice[6];

void north() {
    char tmp;
    tmp = dice[kTOP];
    dice[kTOP] = dice[kSOUTH];
    dice[kSOUTH] = dice[kBOTTOM];
    dice[kBOTTOM] = dice[kNORTH];
    dice[kNORTH] = tmp;
}

void east() {
    char tmp;
    tmp = dice[kTOP];
    dice[kTOP] = dice[kWEST];
    dice[kWEST] = dice[kBOTTOM];
    dice[kBOTTOM] = dice[kEAST];
    dice[kEAST] = tmp;
}

void west() {
    char tmp;
    tmp = dice[kTOP];
    dice[kTOP] = dice[kEAST];
    dice[kEAST] = dice[kBOTTOM];
    dice[kBOTTOM] = dice[kWEST];
    dice[kWEST] = tmp;
}

void south() {
    char tmp;
    tmp = dice[kTOP];
    dice[kTOP] = dice[kNORTH];
    dice[kNORTH] = dice[kBOTTOM];
    dice[kBOTTOM] = dice[kSOUTH];
    dice[kSOUTH] = tmp;
}

void right() {
    char tmp;
    tmp = dice[kSOUTH];
    dice[kSOUTH] = dice[kEAST];
    dice[kEAST] = dice[kNORTH];
    dice[kNORTH] = dice[kWEST];
    dice[kWEST] = tmp;
}

void left() {
    char tmp;
    tmp = dice[kSOUTH];
    dice[kSOUTH] = dice[kWEST];
    dice[kWEST] = dice[kNORTH];
    dice[kNORTH] = dice[kEAST];
    dice[kEAST] = tmp;
}

int main () {
    int i,n,result;
    char roll[6];
    while (1) {
        scanf("%d", &n);
        if (n==0) return 0;
        dice[kTOP]      = 1;
        dice[kBOTTOM]   = 6;
        dice[kNORTH]    = 5;
        dice[kSOUTH]    = 2;
        dice[kEAST]     = 3;
        dice[kWEST]     = 4;
        result = 1;
        for (i=0;i<n;i++) {
            scanf("%s", roll);
            switch (roll[0]) {
                case 'N':
                    north();
                    break;
                case 'E':
                    east();
                    break;
                case 'W':
                    west();
                    break;
                case 'S':
                    south();
                    break;
                case 'R':
                    right();
                    break;
                case 'L':
                    left();
                    break;
            }
            result += dice[kTOP];
        }
        printf("%d\n", result);

    }
}
