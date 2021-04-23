#include <cstdio>
#include <map>
#define MAX_L       500000
#define SZ_TR       1100000
typedef long long ll;
//공장
using namespace std;
int arr1[MAX_L], arr2[MAX_L];
int tree[SZ_TR];
int OFFSET;
int N;
map<int, int> m;
void init(int N) {
    for (OFFSET=1; OFFSET<N; OFFSET*=2);
    for (int i=0; i<OFFSET*2; ++i) tree[i] = 0;
}

int query(int from, int to) {
    from += OFFSET, to += OFFSET;
    int res = 0;
    while (from <= to) {
        if (from&1) res += tree[from++];
        if (to%2==0) res += tree[to--];
        from /= 2, to /= 2;
    }
    return res;
}

void update(int idx, int val) {
    idx += OFFSET;
    while (idx > 0) {
        tree[idx] += val;
        idx /= 2;
    }
}

int main() {
    scanf("%d", &N);
    for (int i=0; i<N; ++i) scanf("%d", arr1+i);
    for (int i=0; i<N; ++i) {
        scanf("%d", arr2+i);
        m[arr2[i]] = i;
    }
    init(N);
    ll ans = 0;
    for (int i=0; i<N; ++i) {
        int idx = m[arr1[i]];
        update(idx, 1);
        ans += query(idx+1, N-1);
    }
    printf("%lld\n", ans);
    return 0;
}