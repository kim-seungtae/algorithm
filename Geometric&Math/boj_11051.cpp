#include <cstdio>
//이항 계수2
using namespace std;
#define min(a,b) ((a) > (b) ? (b) : (a))
typedef long long ll;
ll dp[1001][1001];
ll nk(ll x, ll y) {
    y = min(y, x-y);
    if (x==1 || x==y) return 1;
    if (y == 1) return x;
    if (dp[x][y]) return dp[x][y];
    dp[x][y] = nk(x-1, y-1) % 10007 + nk(x-1, y) % 10007;
    return dp[x][y];
}

int main() {
    ll N, K, k, ans;
    scanf("%lld %lld", &N, &K);
    K = min(K, N-K);
    ans = nk(N, K);
    printf("%lld", ans % 10007);
    return 0;
}