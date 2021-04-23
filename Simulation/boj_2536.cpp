#include <iostream>
#include <vector>
#include <queue>
#define MAX_M       100000
#define MAX_N       100000
#define MAX_B       5000
using namespace std;
struct Bus {
    int x1, x2, y1, y2;
};
bool transfer (Bus& a, Bus& b) {
    if (a.y1 == a.y2 && b.y1 == b.y2) {
        if (a.y1 == b.y1) {
            if (a.x1 <= b.x1 && a.x2 >= b.x1) return true;
            if (a.x1 >= b.x1 && a.x1 <= b.x2) return true;
        }
        return false;
    }
    else if (a.y1 == a.y2 && b.x1 == b.x2) {
        if (a.y1 >= b.y1 && a.y1 <= b.y2 && b.x1 >= a.x1 && b.x1 <= a.x2) return true;
        return false;
    }
    else if (a.x1 == a.x2 && b.x1 == b.x2) {
        if (a.x1 == b.x1) {
            if (a.y1 >= b.y1 && a.y1 <= b.y2) return true;
            if (a.y1 <= b.y1 && a.y2 >= b.y1) return true;
        }
        return false;
    }
    else if (a.x1 == a.x2 && b.y1 == b.y2) {
        if (a.y1 <= b.y1 && a.y2 >= b.y1 && b.x1 <= a.x1 && b.x2 >= a.x1) return true;
        return false;
    }
    return false;
}
int m, n, k, sy, sx, ey, ex;
Bus bus[MAX_B+1];
bool visited[MAX_B+1];
int bfs() {
    queue<pair<Bus, int>> q;
    for (int i=1; i<=k; ++i) {
        if (bus[i].x1 == bus[i].x2 && bus[i].x1 == sx && bus[i].y1 <= sy && bus[i].y2 >= sy) {
            q.push({bus[i], 1});
            visited[i] = true;
        }
        else if (bus[i].y1 == bus[i].y2 && bus[i].y1 == sy && bus[i].x1 <= sx && bus[i].x2 >= sx) {
            q.push({bus[i], 1});
            visited[i] = true;
        }
    }
    int ret;
    while (!q.empty()) {
        Bus cur = q.front().first;
        int t = q.front().second;
        q.pop();
        if ((cur.x1 == cur.x2 && cur.x1 == ex && ey >= cur.y1 && ey <= cur.y2) || (cur.y1 == cur.y2 && cur.y1 == ey && ex >= cur.x1 && ex <= cur.x2)) {
            ret = t;
            break;
        }
        for (int i=1; i<=k; ++i) {
            if (visited[i]) continue;
            if (transfer(cur, bus[i])) {
                q.push({bus[i], t+1});
                visited[i] = true;
            }
        }
    }
    return ret;
}
int main() {
    cin >> m >> n >> k;
    int num, y1, x1, y2, x2;
    for (int i=0; i<k; ++i) {
        cin >> num >> x1 >> y1 >> x2 >> y2;
        bus[num].x1 = min(x1, x2);
        bus[num].y1 = min(y1, y2);
        bus[num].x2 = max(x1, x2);
        bus[num].y2 = max(y1, y2);
    }
    cin >> sx >> sy >> ex >> ey;

    cout << bfs() << endl;
    return 0;
}