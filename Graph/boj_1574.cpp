#include <iostream>
#include <vector>
#define MAX_N       300
#define MAX_M       300
using namespace std;

int R, C, N;
int aMatch[MAX_N*MAX_M], bMatch[MAX_N*MAX_M];
int map[MAX_N][MAX_M], Left[MAX_N][MAX_M], Right[MAX_N][MAX_M];
vector<int> adj[MAX_N*MAX_M];
bool visited[MAX_N*MAX_M];
int n = 0, m = 0;
void fillLeft() {
    int x, cnt = 1;
    for (int i=0; i<R; ++i) {
        x = 0;
        bool flag = false;
        while (x < C) {
            if (map[i][x] == 0)  {
                Left[i][x] = cnt;
                flag = true;
            }
            ++x;
        }
        if (flag) ++cnt;
    }
    n = cnt;
}
void fillRight() {
    int y, cnt = 1;
    for (int j=0; j<C; ++j) {
        y = 0;
        bool flag = false;
        while (y < R) {
            if (map[y][j] == 0) {
                Right[y][j] = cnt;
                flag = true;
            }
            ++y;
        }
        if (flag) ++cnt;
    }
    m = cnt;
}
bool dfs(int idx) {
    if (visited[idx]) return false;
    visited[idx] = true;

    for (int next : adj[idx]) {
        if (bMatch[next] == -1 || dfs(bMatch[next])) {
            aMatch[idx] = next;
            bMatch[next] = idx;
            return true;
        }
    }
    return false;
}
int bipartite() {
    for (int i=1; i<=n; ++i) aMatch[i] = -1;
    for (int i=1; i<=m; ++i) bMatch[i] = -1;

    int ans = 0;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) visited[j] = false;
        if (dfs(i)) ++ans;
    }
    return ans;
}
int main() {
    cin >> R >> C >> N;
    int y, x;
    for (int i=0; i<N; ++i){
        cin >> y >> x;
        map[y-1][x-1] = 1;
    }
    fillLeft();
    fillRight();

    for (int i=0; i<R; ++i) for (int j=0; j<C; ++j) {
        if (map[i][j] != 0) continue;
        adj[Left[i][j]].push_back(Right[i][j]);
    }
    cout << bipartite() << endl;
    return 0;
}