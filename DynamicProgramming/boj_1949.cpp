#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, dp[2][10001], population[10001], visited[10001];
vector<int> village[10001];

void dfs(int root) {
    if (visited[root]) return;
    visited[root] = 1;
    dp[0][root] = 0;
    dp[1][root] = population[root];

    for (int next: village[root]) {
        if (visited[next]) continue;

        dfs(next);
        dp[0][root] += max(dp[0][next], dp[1][next]);
        dp[1][root] += dp[0][next];
    }
}

int main() {
    cin >> N;
    for (int i=1; i<=N; i++)
        cin >> population[i];
    
    int from, to;
    for (int i=1; i<N; i++) {
        cin >> from >> to;
        village[from].push_back(to);
        village[to].push_back(from);
    }

    dfs(1);

    cout << max(dp[0][1], dp[1][1]);
}