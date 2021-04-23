#include <iostream>
#include <vector>
#include <queue>
#define MAX_N       500
using namespace std;
int N, K, x, y;
int aMatch[MAX_N+1], bMatch[MAX_N+1];
vector<int> adj[MAX_N+1];
bool visited[MAX_N+1];
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
    for (int i=1; i<=N; ++i) {
        aMatch[i] = -1;
        bMatch[i] = -1;
    }
    int ans = 0;
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) visited[j] = false;

        if (dfs(i)) ++ans;
    }
    return ans;
}
int main() {
    cin >> N >> K;
    for (int i=0; i<K; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
    }

    cout << bipartite() << endl;
    return 0;
}