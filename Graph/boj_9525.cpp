#include <iostream>
#include <vector>
#define MAX_N       100
using namespace std;

int N;
int aMatch[MAX_N*MAX_N], bMatch[MAX_N*MAX_N];
char map[MAX_N][MAX_N];
int Left[MAX_N][MAX_N], Right[MAX_N][MAX_N];
vector<int> adj[MAX_N*MAX_N];
bool visited[MAX_N*MAX_N];
int n = 0, m = 0;
void fillLeft() {
    int x, cnt = 1;
    for (int i=0; i<N; ++i) {
        x = 0;
        bool flag = false;
        while (x < N) {
            if (map[i][x] == '.')  {
                Left[i][x] = cnt;
                flag = true;
            }
            else {
                if (flag) ++cnt;
                flag = false;
            }
            ++x;
        }
        if (flag) ++cnt;
    }
    n = cnt;
}
void fillRight() {
    int y, cnt = 1;
    for (int j=0; j<N; ++j) {
        y = 0;
        bool flag = false;
        while (y < N) {
            if (map[y][j] == '.') {
                Right[y][j] = cnt;
                flag = true;
            }
            else {
                if (flag) ++cnt;
                flag = false;
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
    cin >> N;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        cin >> map[i][j];
    }

    fillLeft();
    fillRight();

    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        if (map[i][j] != '.') continue;
        adj[Left[i][j]].push_back(Right[i][j]);
    }
    cout << bipartite() << endl;
    return 0;
}