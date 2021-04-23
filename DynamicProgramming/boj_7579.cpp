#include <cstdio>
//앱
using namespace std;
#define MAX_N       100
#define MAX_B       100
#define MAX_M       10000000
int N, M, costSum;
//dp[i]는 비용i로 확보할 수 있는 최대 메모리
int mem[MAX_N], cost[MAX_N], dp[MAX_N*MAX_B+1];
int max(int a, int b) {return a>b?a:b;}
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; ++i) scanf("%d", mem+i);
    for (int i=0; i<N; ++i) {
        scanf("%d", cost+i);
        costSum += cost[i];
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=costSum; j>=cost[i]; --j) {
            dp[j] = max(dp[j], dp[j-cost[i]] + mem[i]);
        }
    }

    for (int i=0; i<=costSum; ++i) {
        if (dp[i] >= M) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}