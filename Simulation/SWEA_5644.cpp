#include <iostream>
#include <vector>
#define MAX_M       100
#define MAX_A       8
#define MAX_C       4
using namespace std;

struct BC {
    int y, x, c, p;
};
int T, M, A, ans, ay, ax, by, bx;
int dy[5] = {0, -1, 0, 1, 0};
int dx[5] = {0, 0, 1, 0, -1};
int a[MAX_M], b[MAX_M];
BC bc[MAX_A];
int abs(int a) {return a >= 0 ? a : -a;}
int dis(int ay, int ax, int by, int bx) {
    return abs(ay - by) + abs(ax - bx);
}
int cal() {
    vector<int> a, b;
    int max = 0;
    for (int i=0; i<A; ++i) {
        if (dis(bc[i].y, bc[i].x, ay, ax) <= bc[i].c) a.push_back(i);
        if (dis(bc[i].y, bc[i].x, by, bx) <= bc[i].c) b.push_back(i);
    }
    if (a.size() != 0 && b.size() != 0) {
        for (int i=0; i<a.size(); ++i) for (int j=0; j<b.size(); ++j) {
            int tmp = 0;
            if (a[i] == b[j]) tmp = bc[a[i]].p;
            else tmp = bc[a[i]].p + bc[b[j]].p;

            if (max < tmp) max = tmp;
        }
    }
    else if (a.size() != 0) {
        for (int i=0; i<a.size(); ++i) {
            if (max < bc[a[i]].p) max = bc[a[i]].p;
        }
    }
    else if (b.size() != 0) {
        for (int i=0; i<b.size(); ++i) {
            if (max < bc[b[i]].p) max = bc[b[i]].p;
        }
    }
    return max;
}
void init() {
    ans = 0;
    ay = 1, ax = 1, by = 10, bx = 10;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t=1; t<=T; ++t) {
        cin >> M >> A;
        for (int i=0; i<M; ++i) cin >> a[i];
        for (int i=0; i<M; ++i) cin >> b[i];
        for (int i=0; i<A; ++i) cin >> bc[i].x >> bc[i].y >> bc[i].c >> bc[i].p;
        init();
        
        ans += cal();
        for (int i=0; i<M; ++i) {
            ay += dy[a[i]], ax += dx[a[i]], by += dy[b[i]], bx += dx[b[i]];
            ans += cal();
        }
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}