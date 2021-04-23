#include <iostream>
//카드 게임
using namespace std;

#define MAX_N       1000

int T, N, ans;
int card[MAX_N+1];
int dp[MAX_N+1][MAX_N+1];
int max(int a, int b) {return a>b?a:b;}
int dfs(int st, int end, int turn) {
    if (st == end) {
        if (turn) return card[st];
        else return 0;
    }
    int M = 0;
    if (turn) {
        if (dp[st][end]) return dp[st][end];
        M = max(card[st] + dfs(st+1, end, 0), card[end] + dfs(st, end-1, 0));
        dp[st][end] = M;
        return M;
    }
    else {
        M = min(dfs(st+1, end, 1), dfs(st, end-1, 1));
        return M;
    }
}

int main() {
    scanf("%d", &T);
    for (int t=0; t<T; ++t) {
        for (int i=0; i<=N; ++i) for (int j=0; j<=N; ++j) dp[i][j] = 0;
        scanf("%d", &N);
        for (int i=1; i<=N; ++i) scanf("%d", card+i);
        // init();

        ans = dfs(1, N, 1);
        printf("%d\n", ans);
    }



    return 0;
}