#include <cstdio>
//가장 큰 정사각형
using namespace std;

#define MAX_N       1000
#define MAX_M       1000

int min(int a, int b) {return a>b?b:a;}
int max(int a, int b) {return a>b?a:b;}

int map[MAX_N+1][MAX_M+1], dp[MAX_N+1][MAX_M+1];

int main() {
    int n, m, ans=0;
    scanf("%d %d", &n, &m);
    char s[1001];
    for (int i=1; i<=n; ++i) {
        scanf("%s", s);
        for (int j=1; j<=m; ++j) {
            map[i][j] = s[j-1]-'0';
            dp[i][j] = map[i][j];
            if (dp[i][j] == 1) ans = 1;
        }
    }

    for (int i=1; i<=n; ++i) for (int j=1; j<=m; ++j) {
        if (map[i][j] && map[i-1][j-1] && map[i-1][j] && map[i][j-1]) {
            dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j]) + 1;
            if (ans < dp[i][j]) ans = dp[i][j];
        }
    }
    printf("%d", ans*ans);
    

    return 0;
}