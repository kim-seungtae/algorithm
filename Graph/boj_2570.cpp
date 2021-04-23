#include <iostream>
#include <vector>
#define MAX_N       100
using namespace std;
vector<int> adj[MAX_N*MAX_N];
int aMatch[MAX_N*MAX_N], bMatch[MAX_N*MAX_N];
bool visited[MAX_N*MAX_N];
int map[MAX_N][MAX_N], Left[MAX_N][MAX_N], Right[MAX_N][MAX_N];
int N, M;
void fillLeft() {
    int y = 0, x = N - 1, cnt = 1;
    for (int i=0; i<2*N-1; ++i) {
        bool check = false;
        int ny = y, nx = x;
        while (ny<N&&nx<N) {
            if (map[ny][nx] == 1) {
                if (check) ++cnt;
                check = false;
            }
            else {
                Left[ny][nx] = cnt;
                check = true;
            }
            ++ny, ++nx;
        }
        if (check) ++cnt;
        if (x == 0) ++y;
        else --x;
    }
}
void fillRight() {
    int y = 0, x = 0, cnt = 1;
    for (int i=0; i<2*N-1; ++i) {
        bool check = false;
        int ny = y, nx = x;
        while (ny<N&&nx>=0) {
            if (map[ny][nx] == 1) {
                if (check) ++cnt;
                check = false;
            }
            else {
                Right[ny][nx] = cnt;
                check = true;
            }
            ++ny, --nx;
        }
        if (check) ++cnt;
        if (x == N-1) ++y;
        else ++x;
    }
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
    for (int i=1; i<=N*N; ++i) aMatch[i] = -1;
    for (int i=1; i<=N*N; ++i) bMatch[i] = -1;

    int ans = 0;
    for (int i=1; i<=N*N; ++i) {
        for (int j=1; j<=N*N; ++j) visited[j] = false;
        if (dfs(i)) ++ans;
    }
    return ans;
}
int main() {
    cin >> N;
    cin >> M;
    int y, x;
    for (int i=0; i<M; ++i) {
        cin >> y >> x;
        map[y-1][x-1] = 1;
    }
    fillLeft();
    fillRight();
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        if (map[i][j] == 1) continue;
        adj[Left[i][j]].push_back(Right[i][j]);
    }
    cout << bipartite() << endl;
    return 0;
}