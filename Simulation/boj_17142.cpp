#include <iostream>
#include <queue>
#define MAX_N       50
#define MAX_M       10
using namespace std;

int N, M, mIdx, ans;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int map[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int mList[MAX_M]; // i*N + j
int selectedM[MAX_M];
int max(int a, int b) {return a>b?a:b;}
bool check() {
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        if (map[i][j] != 0) continue;
        if (visited[i][j] == -1) return false;
    }
    return true;
}
int bfs() {
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        visited[i][j] = -1;
    }
    if (check()) return 0;
    queue<int> q;
    for (int i=0; i<mIdx; ++i) {
        if (selectedM[i] == 1) {
            q.push(mList[i]);
            visited[mList[i]/N][mList[i]%N] = 0;
        }
    }
    while (!q.empty()) {
        int y = q.front() / N;
        int x = q.front() % N;
        q.pop();
        for (int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < N && map[ny][nx] != 1) {
                if (visited[ny][nx] == -1) {
                    visited[ny][nx] = visited[y][x] + 1;
                    q.push(ny*N+nx);
                }
            }
        }
    }
    int ret = 0;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        if (map[i][j] == 0) {
            if (visited[i][j] == -1) return 999999;
            else ret = max(ret, visited[i][j]);
        }
    }
    return ret;
}
void dfs(int idx, int selected) {
    if (selected == M) {
        int tmp = bfs();
        if (ans > tmp) ans = tmp;
        return;
    }
    if (idx >= mIdx) return;

    for (int i=idx; i<mIdx; ++i) {
        selectedM[i] = 1;
        dfs(i+1, selected+1);
        selectedM[i] = 0;
    }
}
void input() {
    cin >> N >> M;
    mIdx = 0;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        cin >> map[i][j];
        if (map[i][j] == 2) mList[mIdx++] = i*N + j;
    }
    for (int i=0; i<mIdx; ++i) selectedM[i] = 0;
    ans = 999999;
}
int main() {
    input();
    dfs(0, 0);
    if (ans == 999999) ans = -1;
    cout << ans << endl;
    return 0;
}