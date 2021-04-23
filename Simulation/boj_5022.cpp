#include <iostream>
#include <vector>
#include <queue>
#define MAX_N       100
#define MAX_M       100
using namespace std;
typedef pair<int, int> pii;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
struct Line {
    int sy, sx;
    vector<pii> route;
    Line (int _sy, int _sx) : sy(_sy), sx(_sx) { route.clear(); };
    Line (pii a) : sy(a.first), sx(a.second) { route.clear(); };
};
int N, M;
pii s[2], d[2];
bool visited[MAX_N+1][MAX_M+1];

int bfs(pii start, int o) {
    int ret = 0;
    queue<Line> q;
    Line root(start);
    root.route.push_back(start);
    q.push({root});
    visited[start.first][start.second] = true;
    while (!q.empty()) {
        Line cur = q.front();
        int y = cur.route.back().first;
        int x = cur.route.back().second;
        q.pop();
        if (y == d[o].first && x == d[o].second) {
            for (int i=0; i<=N; ++i) for (int j=0; j<=M; ++j) visited[i][j] = false;
            for (pii p : cur.route) visited[p.first][p.second] = true;
            ret = cur.route.size() - 1;
            break;
        }

        for (int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny<0||ny>N||nx<0||nx>M||visited[ny][nx]||(ny==s[(o+1)%2].first&&nx==s[(o+1)%2].second)||(ny==d[(o+1)%2].first&&nx==d[(o+1)%2].second)) continue;
            visited[ny][nx] = true;
            Line tmp(ny, nx);
            tmp.route = cur.route;
            tmp.route.push_back({ny, nx});
            q.push(tmp);
        }
    }
    return ret;
}

int main() {
    cin >> N >> M;
    cin >> s[0].first >> s[0].second;
    cin >> d[0].first >> d[0].second;
    cin >> s[1].first >> s[1].second;
    cin >> d[1].first >> d[1].second;

    int fLen, sLen, a, b;
    a = bfs(s[0], 0);
    b = bfs(s[1], 1);
    if (a == 0 || b == 0) fLen = 0;
    else fLen = a + b;
    
    for (int i=0; i<=N; ++i) for (int j=0; j<=M; ++j) visited[i][j] = false;
    a = bfs(s[1], 1);
    b = bfs(s[0], 0);
    if (a == 0 || b == 0) sLen = 0;
    else sLen = a + b;

    if (fLen == 0 && sLen == 0) cout << "IMPOSSIBLE" << endl;
    else if (fLen == 0) cout << sLen << endl;
    else if (sLen == 0) cout << fLen << endl;
    else cout << min(fLen, sLen) << endl;
    return 0;
}