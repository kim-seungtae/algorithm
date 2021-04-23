#include <iostream>
#define MAX_N       200
#define MAX_M       200
using namespace std;

int N, M;
int aMatch[MAX_N+1], bMatch[MAX_M+1];
int adj[MAX_N+1][MAX_M+1];
bool visited[MAX_N+1];

bool dfs(int idx) {
    if (visited[idx]) return false;
    visited[idx] = true;

    for (int i=1; i<=M; ++i) {
        if (adj[idx][i]) {
            if (bMatch[i] == -1 || dfs(bMatch[i])) {
                aMatch[idx] = i;
                bMatch[i] = idx;
                return true;
            }
        }
    }
    return false;
}
int bipartiteMatch() {
    for (int i=1; i<=N; ++i) aMatch[i] = -1;
    for (int i=1; i<=M; ++i) bMatch[i] = -1;
    int ans = 0;
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) visited[j] = false;

        if (dfs(i)) ++ans;
    }
    return ans;
}
int main() {
    cin >> N >> M;
    int num, b;
    for (int i=1; i<=N; ++i) {
        cin >> num;
        for (int j=1; j<=num; ++j) {
            cin >> b;
            adj[i][b] = 1;
        }
    }

    cout << bipartiteMatch() << endl;
    return 0;
}