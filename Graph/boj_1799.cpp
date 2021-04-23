#include <iostream>
#include <vector>
#define MAX_N       10
using namespace std;
vector<int> adj[MAX_N*2];
int aMatch[MAX_N*2+1], bMatch[MAX_N*2+1];
bool visited[MAX_N*2];
int map[MAX_N][MAX_N], Left[MAX_N][MAX_N], Right[MAX_N][MAX_N];
int N;
void fillLeft() {
    int y = 0, x = N - 1, cnt = 1;
    for (int i=0; i<2*N-1; ++i) {
        int ny = y, nx = x;
        while (ny<N&&nx<N) {
            Left[ny++][nx++] = cnt;
        }
        ++cnt;
        if (x == 0) ++y;
        else --x;
    }
}
void fillRight() {
    int y = 0, x = 0, cnt = 1;
    for (int i=0; i<2*N-1; ++i) {
        int ny = y, nx = x;
        while (ny<N&&nx>=0) {
            Right[ny++][nx--] = cnt;
        }
        ++cnt;
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
    for (int i=1; i<=2*N-1; ++i) aMatch[i] = -1;
    for (int i=1; i<=2*N-1; ++i) bMatch[i] = -1;

    int ans = 0;
    for (int i=1; i<=2*N-1; ++i) {
        for (int j=1; j<=MAX_N*2; ++j) visited[j] = false;
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
        if (map[i][j] == 0) continue;
        adj[Left[i][j]].push_back(Right[i][j]);
    }

    cout << bipartite() << endl;
    return 0;
}