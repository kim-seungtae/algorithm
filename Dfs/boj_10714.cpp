#include <cstdio>
//케이크 자르기2.
using namespace std;
#define MAX_L       2000
typedef long long ll;

int N;
int cake[MAX_L];
ll dp[MAX_L][MAX_L];
ll ans;
ll max(ll a, ll b) {return a>b?a:b;}
ll dfs(int st, int end, int turn) {
    if (st == end) {
        if (turn) return cake[st];
        else return 0;
    }
    ll M = 0;
    if (turn) {
        if (dp[st][end]) return dp[st][end];
        M = max(cake[st] + dfs((st+1)%N, end, 0), cake[end] + dfs(st, (end-1+N)%N, 0));
        dp[st][end] = M;
        return M;
    }
    else {
        if (cake[st] > cake[end]) {
            return dfs((st+1)%N, end, 1);
        }
        else return dfs(st, (end-1+N)%N, 1);
    }
}
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; ++i) scanf("%d", cake+i);
    for (int i=0; i<N; ++i) {
        ans = max(ans, cake[i] + dfs((i+1)%N, (i-1+N)%N,0));
    }

    printf("%lld\n", ans);
    return 0;
}