#include <cstdio>
#include <vector>
#define INF         2000000000
#define MAX_N       200
//전구
using namespace std;

int color[MAX_N+1];
int dp[MAX_N+1][MAX_N+1];
int N, K;

int min(int a, int b) {return a>b?b:a;}
int dfs(int st, int end) {
    if (st == end) return 0;
    if (dp[st][end] != -1) return dp[st][end];

    int ret = INF;
    for (int i=st; i<end; ++i) {
        int tmp = color[st] == color[i+1] ? 0 : 1;
        ret = min(ret, tmp + dfs(st, i) + dfs(i+1, end));
    }
    dp[st][end] = ret;
    return ret;
}

int main() {
    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; ++i) scanf("%d", color+i);
    
    for (int i=0; i<=MAX_N; ++i) for (int j=0; j<=MAX_N; ++j) dp[i][j] = -1;

    printf("%d\n", dfs(1, N));

    return 0;
}
