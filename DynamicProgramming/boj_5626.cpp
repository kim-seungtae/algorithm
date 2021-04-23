#include <cstdio>
#define MAX_N       10000
#define MOD         1000000007
typedef long long ll;
//제단
using namespace std;

int N;
int arr[MAX_N+1];
ll dp[2][MAX_N+2];

int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) {
        scanf("%d", arr+i);
    }
    int t = 1;
    dp[0][0] = (arr[1] == -1 || arr[1] == 0) ? 1 : 0;
    for (int i=2; i<=N; ++i, t=1-t) {
        for (int j=0; j<=MAX_N+1; ++j) dp[t][j] = 0;
        if (arr[i] == -1) {
            //j가 0일때는 -1없으니까 따로해주고
            dp[t][0] = (dp[1-t][0] + dp[1-t][1]) % MOD;
            for (int j=1; j<=N; ++j) { //높이는 최대로 올라도 N/2인가?
                dp[t][j] = (dp[1-t][j-1] + dp[1-t][j] + dp[1-t][j+1]) % MOD;
            }
        }
        else if (arr[i] == 0) {
            dp[t][0] = (dp[1-t][0] + dp[1-t][1]) % MOD;
        }
        else {
            dp[t][arr[i]] = (dp[1-t][arr[i]-1] + dp[1-t][arr[i]] + dp[1-t][arr[i]+1]) % MOD;
        }
    }

    printf("%lld\n", dp[1-t][0] % MOD);

    return 0;
}