#include <iostream>
#define MAX_N       300
#define MAX_M       300
using namespace std;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
int N, M, p;
int map[2][MAX_N][MAX_M];
int visited[MAX_N][MAX_M];
void dfs(int y, int x) {
    visited[y][x] = true;
    for (int i=0; i<4; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny<0||ny>=N||nx<0||nx>=M||visited[ny][nx]||map[p][ny][nx] == 0) continue;
        visited[ny][nx] = true;
        dfs(ny, nx);
    }
}
int divide() {
    int t = 0;
    for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) {
        if (visited[i][j] || map[p][i][j] == 0) continue;
        if (t != 0) return 1;
        ++t;
        dfs(i, j);
    }
    if (t == 0) return 2;
    else return 0;
}
void melt() {
    for (int i=0;i<N; ++i) for (int j=0; j<M; ++j) {
        if (map[p][i][j] == 0) continue;
        int w = 0;
        for (int d=0; d<4; ++d) {
            int ny = i + dy[d];
            int nx = j + dx[d];

            if (ny<0||ny>=N||nx<0||nx>=M||map[p][ny][nx] != 0) continue;
            ++w;
        }
        map[(p+1)%2][i][j] = max(map[p][i][j] - w, 0);
    }
}
int main() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) cin >> map[0][i][j];

    int ans = 0, d;
    p = 0;
    while ((d = divide()) == 0) {
        ++ans;
        melt();
        for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) {
            map[p][i][j] = 0;
            visited[i][j] = false;
        }
        p = (p+1)%2;
    }
    if (d == 2) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}