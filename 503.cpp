#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char MinPos(vector<char>* hanoi) {
    char mins[3];
    if (!hanoi[0].empty()) {
        mins[0] = *min_element(hanoi[0].begin(), hanoi[0].end());
    } else {
        mins[0] = 100;
    }
    if (!hanoi[1].empty()) {
        mins[1] = *min_element(hanoi[1].begin(), hanoi[1].end());
    } else {
        mins[1] = 100;
    }
    if (!hanoi[2].empty()) {
        mins[2] = *min_element(hanoi[2].begin(), hanoi[2].end());
    } else {
        mins[2] = 100;
    }
    if (mins[0] < mins[1] && mins[0] < mins[2]) return 0;
    if (mins[1] < mins[0] && mins[1] < mins[2]) return 1;
    if (mins[2] < mins[0] && mins[2] < mins[1]) return 2;
}

void RemoveMin(vector<char>* tray) {
    tray->erase(min_element(tray->begin(), tray->end()));
}

void CopyHanoi(vector<char>* src_hanoi, vector<char>* dest_hanoi) {
    for (int i=0; i<3; i++) {
        dest_hanoi[i].clear();
        dest_hanoi[i].reserve(src_hanoi[i].size());
        copy(src_hanoi[i].begin(), src_hanoi[i].end(), back_inserter(dest_hanoi[i]));
    }
}

void GatherCups(vector<char>* hanoi, char pos) {
    if (pos == 0) {
        hanoi[0].insert(hanoi[0].end(), hanoi[1].begin(), hanoi[1].end());
        hanoi[0].insert(hanoi[0].end(), hanoi[2].begin(), hanoi[2].end());
        hanoi[1].clear();
        hanoi[2].clear();
    }
    if (pos == 1) {
        hanoi[1].insert(hanoi[1].end(), hanoi[0].begin(), hanoi[0].end());
        hanoi[1].insert(hanoi[1].end(), hanoi[2].begin(), hanoi[2].end());
        hanoi[0].clear();
        hanoi[2].clear();
    }
    if (pos == 2) {
        hanoi[2].insert(hanoi[2].end(), hanoi[0].begin(), hanoi[0].end());
        hanoi[2].insert(hanoi[2].end(), hanoi[1].begin(), hanoi[1].end());
        hanoi[0].clear();
        hanoi[1].clear();
    }
}

char SumOfCups(vector<char>* hanoi) {
    return hanoi[0].size() + hanoi[1].size() + hanoi[2].size();
}


long fa(vector<char>*);
long fc(vector<char>*);

long fa(vector<char>* hanoi) {
    long a,b,c;
    vector<char> next_hanoi[3];
    if (SumOfCups(hanoi) == 0) {
        return 0;
    }
    switch (MinPos(hanoi)) {
        case 0:
            RemoveMin(&hanoi[0]);
            CopyHanoi(hanoi, next_hanoi);
            return fa(next_hanoi);
            break;
        case 1:
            RemoveMin(&hanoi[1]);
            CopyHanoi(hanoi, next_hanoi);
            a = fc(next_hanoi);
            GatherCups(hanoi, 2);
            CopyHanoi(hanoi, next_hanoi);
            b = fa(next_hanoi);
            return a + 1 + b;
            break;
        case 2:
            RemoveMin(&hanoi[2]);
            CopyHanoi(hanoi, next_hanoi);
            a = fa(next_hanoi);
            GatherCups(hanoi, 0);
            CopyHanoi(hanoi, next_hanoi);
            b = fc(next_hanoi);
            swap(hanoi[0], hanoi[2]);
            CopyHanoi(hanoi, next_hanoi);
            c = fa(next_hanoi);
            return a + b + c + 2;
            break;
    }
}

long fc(vector<char>* hanoi) {
    long a,b,c;
    vector<char> next_hanoi[3];
    if (SumOfCups(hanoi) == 0) {
        return 0;
    }
    switch (MinPos(hanoi)) {
        case 0:
            RemoveMin(&hanoi[0]);
            CopyHanoi(hanoi, next_hanoi);
            a = fc(next_hanoi);
            GatherCups(hanoi, 2);
            CopyHanoi(hanoi, next_hanoi);
            b = fa(next_hanoi);
            swap(hanoi[0], hanoi[2]);
            CopyHanoi(hanoi, next_hanoi);
            c = fc(next_hanoi);
            return a + b + c + 2;
            break;
        case 1:
            RemoveMin(&hanoi[1]);
            CopyHanoi(hanoi, next_hanoi);
            a = fa(next_hanoi);
            GatherCups(hanoi, 0);
            CopyHanoi(hanoi, next_hanoi);
            b = fc(next_hanoi);
            return a + 1 + b;
            break;
        case 2:
            RemoveMin(&hanoi[2]);
            CopyHanoi(hanoi, next_hanoi);
            return fc(next_hanoi);
            break;
    }
}

int main() {
    vector<char> hanoi[3],next_hanoi[3];
    int n,i,j;
    long int a,b,res;
    long m;
    while (1) {
        scanf("%d %ld", &n, &m);
        if (n == 0) return 0;
        for (i=0;i<3;i++) {
            hanoi[i].clear();
            scanf("%d", &a);
            for (j=0;j<a;j++) {
                scanf("%d", &b);
                hanoi[i].push_back(b);
            }
        }
        CopyHanoi(hanoi, next_hanoi);
        a = fc(next_hanoi);
        CopyHanoi(hanoi, next_hanoi);
        b = fa(next_hanoi);
        res = min(a, b);
        if (res > m)
            res = -1;
        printf("%ld\n", res);
    }
}
