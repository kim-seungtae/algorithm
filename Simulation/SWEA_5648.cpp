#include <iostream>
#define MAX_N       1000
using namespace std;
int dx[4] = {0,0,-1,1}, dy[4] = {1,-1,0,0};
struct atom {
    int y, x, d, k;
    bool deadFlag;
};
int T, N, numOfAliveAtom, ans;
atom alist[MAX_N];
int map[4001][4001];

void input() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> alist[i].x >> alist[i].y >> alist[i].d >> alist[i].k;
        alist[i].x *= 2, alist[i].x += 2000;
        alist[i].y *= 2, alist[i].y += 2000;
        alist[i].deadFlag = 0;
    }
    ans = 0;
    numOfAliveAtom = N;
}
void move() {
    for (int i=0; i<N; ++i) {
        if (alist[i].deadFlag) continue;
        map[alist[i].x][alist[i].y] = 0;
        alist[i].x += dx[alist[i].d];
        alist[i].y += dy[alist[i].d];
        if (alist[i].x < 0 || alist[i].x >= 4000 || alist[i].y < 0 || alist[i].y >= 4000) {
            --numOfAliveAtom;
            alist[i].deadFlag = true;
        }
        else map[alist[i].x][alist[i].y] += alist[i].k;
    }
}
void collide() {
    for (int i=0; i<N; ++i) {
        if (alist[i].deadFlag) continue;
        if (alist[i].k != map[alist[i].x][alist[i].y]) {
            alist[i].deadFlag = true;
            --numOfAliveAtom;
            ans += alist[i].k;
            ans += map[alist[i].x][alist[i].y];
            map[alist[i].x][alist[i].y] = 0;
        }
    }
}


int main() {
    cin >> T;
    for (int t=1; t<=T; ++t) {
        input();
        while (numOfAliveAtom >= 1) {
            move();
            collide();
        }
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}