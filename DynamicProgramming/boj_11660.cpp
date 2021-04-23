#include <iostream>
//구간합 구하기5
using namespace std;

#define MAX_N       1024

int map[MAX_N+1][MAX_N+1];
int dp[MAX_N+1][MAX_N+1];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    dp[1][1] = map[1][1];
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + map[i][j];
        }
    }
    int i1, j1, i2, j2;
    for (int i=0; i<m; ++i) {
        scanf("%d %d %d %d", &i1, &j1, &i2, &j2);
        printf("%d\n", dp[i2][j2] - dp[i1-1][j2] - dp[i2][j1-1] + dp[i1-1][j1-1]);
    }

    return 0;
}