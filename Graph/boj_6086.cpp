#include <iostream>
#include <vector>
#include <queue>
#define MAX_N       52
#define INF         10000000
using namespace std;

int min(int a, int b) {return a<b?a:b;}
int N;
int c[MAX_N][MAX_N], f[MAX_N][MAX_N];
vector<int> adj[MAX_N];
int main() {
    cin >> N;
    for (int i=0; i<N; ++i) {
        char chfrom, chto;
        int from, to, capacity;
        cin >> chfrom >> chto >> capacity;

        if (chfrom >= 'a') from = chfrom - 'a' + 26;
        else from = chfrom - 'A';

        if (chto >= 'a') to = chto - 'a' + 26;
        else to = chto - 'A';

        c[from][to] += capacity;
        c[to][from] += capacity;
        adj[from].push_back(to);
        adj[to].push_back(from);

    }
    int ans = 0, S = 0, T = 'Z'-'A';
    
    while(true) {
        queue<int> q;
        q.push(S);
        int prev[MAX_N];
        for (int i=0; i<MAX_N; ++i) prev[i] = -1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int next : adj[cur]) {
                if (prev[next] != -1) continue;
                if (c[cur][next] - f[cur][next] > 0) {
                    prev[next] = cur;
                    q.push(next);
                    if (next == T) break;
                }
            }
        }
        if (prev[T] == -1) break;
        int flow = INF;
        for (int i=T; i!=S; i=prev[i]) {
            flow = min(flow, c[prev[i]][i] - f[prev[i]][i]);
        }
        ans += flow;

        for (int i=T; i!=S; i = prev[i]) {
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
    }
    cout << ans << endl;
    return 0;
}