#include <cstdio>
//정수삼각형
using namespace std;

#define MAX_N       500

int dp[MAX_N+1];
int map[MAX_N+1][MAX_N+1];
int max(int a, int b) {return a>b?a:b;}
int main() {
    int N;
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=i; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    dp[1] = map[1][1];
    for (int i=2; i<=N; ++i) {
        for (int j=i; j>=1; --j) {
            if (j==1) dp[j] = dp[j] + map[i][j];
            else if (j==i) dp[j] = dp[j-1] + map[i][j];
            else {
                dp[j] = map[i][j] + max(dp[j-1], dp[j]);
            }
        }
    }
    int res = dp[1];
    for (int i=2; i<=N; ++i) {
        if (res < dp[i]) res = dp[i];
    }
    printf("%d\n", res);
    return 0;
}