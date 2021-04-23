#include <cstdio>
#include <vector>
//행렬 곱셈 순서
using namespace std;

#define MAX_N       500
typedef pair<int, int> pii;

int min(int a, int b) {return a>b?b:a;}
int max(int a, int b) {return a>b?a:b;}

int N, r, c;
pii matrix[MAX_N];
int dp[MAX_N+1][MAX_N+1];

//top-down
int dfs(int st, int end) {
    int res = 2000000000;
    if (st == end) return 0;
    if (dp[st][end]) return dp[st][end];
    
    for (int i=st; i<end; ++i) {
        res = min(res, dfs(st, i) + dfs(i+1, end) + matrix[st].first * matrix[i].second * matrix[end].second);
    }
    dp[st][end] = res;
    return res;
}
//bottom-up
int dfs2(int st, int end) {
    for (int i=2; i<=N; ++i) { //i는 합칠 범위 i=2면 행렬 2개 합치기
        for (int j=st; j<=N-i; ++j) { //j는 범위가 i면 시작위치가 어디까지 갈 수 있나
            dp[j][j+i-1] = __INT_MAX__;
            for (int k=j; k<=j+i-1; ++k) { //k는 그범위에서 변하는 중간 위치
                int mid = matrix[j].first * matrix[k].second * matrix[j+i-1].second;
                dp[j][j+i-1] = min(dp[j][j+i-1], dp[j][k] + dp[k+1][j+i-1] + mid);
            }
        }
    }
    return 0;
}
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        scanf("%d %d", &matrix[i].first, &matrix[i].second);
    }

    dfs2(0, N-1);
    printf("%d\n", dp[0][N-1]);
    return 0;
}