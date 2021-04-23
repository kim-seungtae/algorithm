#include <cstdio>
//다리 놓기
using namespace std;
#define min(a,b) ((a) > (b) ? (b) : (a))
typedef long long ll;
//다리 놓기
ll dp[31][31];

ll nk(ll x, ll y) {
    ll ans = 1;
    if (x == 0 || y == 0 || x == y) return 1;
    if (y == 1) return x;
    for (int i=1; i<=y; ++i) {
        ans = ans * (x - i + 1) / i;
    }
    dp[x][y] = ans;
    return ans;
}

int main() {
    int T, N, M;
    scanf("%d", &T);
    ll ans;
    for (int t=0; t<T; ++t) {
        scanf("%d %d", &N, &M);
        ans = nk(M, N);
        printf("%lld\n", ans);
    }

    return 0;
}