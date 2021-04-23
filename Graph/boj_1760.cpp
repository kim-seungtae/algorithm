#include <iostream>
#include <vector>
#define MAX_N       100
#define MAX_M       100
using namespace std;

int N, M;
int aMatch[MAX_N*MAX_M], bMatch[MAX_N*MAX_M];
int map[MAX_N][MAX_M], Left[MAX_N][MAX_M], Right[MAX_N][MAX_M];
vector<int> adj[MAX_N*MAX_M];
bool visited[MAX_N*MAX_M];
int n = 0, m = 0;
void fillLeft() {
    int x, cnt = 1;
    for (int i=0; i<N; ++i) {
        x = 0;
        bool flag = false;
        while (x < M) {
            if (map[i][x] == 0)  {
                Left[i][x] = cnt;
                flag = true;
            }
            else if (map[i][x] == 2) {
                if (flag) {
                    flag = false;
                    ++cnt;
                }
            }
            ++x;
        }
        if (flag) ++cnt;
    }
    n = cnt;
}
void fillRight() {
    int y, cnt = 1;
    for (int j=0; j<M; ++j) {
        y = 0;
        bool flag = false;
        while (y < N) {
            if (map[y][j] == 0) {
                Right[y][j] = cnt;
                flag = true;
            }
            else if (map[y][j] == 2) {
                if (flag) {
                    flag = false;
                    ++cnt;
                }
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
        for (int j=1; j<=N*M; ++j) visited[j] = false;
        if (dfs(i)) ++ans;
    }
    return ans;
}
int main() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) {
        cin >> map[i][j];
    }
    fillLeft();
    fillRight();

    for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) {
        if (map[i][j] != 0) continue;
        adj[Left[i][j]].push_back(Right[i][j]);
    }
    cout << bipartite() << endl;
    return 0;
}