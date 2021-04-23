#include <iostream>
//구간 합 구하기
#define MAX_L       1000000
#define SZ_TR       2100000

typedef long long ll;

ll nos[MAX_L], tree[SZ_TR + 1];
int OFFSET;
void init(int N) {
    for (OFFSET=1; OFFSET<N; OFFSET*=2);
    for (int i=0; i<N; ++i) tree[OFFSET+i] = nos[i];
    for (int i=N; i<OFFSET; ++i) tree[OFFSET+i] = 0;
    for (int i=OFFSET-1; i>0; --i) tree[i] = tree[i*2] + tree[i*2+1];
}

ll query(int from, int to) {
    ll res = 0;
    from += OFFSET, to += OFFSET;
    while (from <= to) {
        if (from&1) {
            res += tree[from];
            ++from;
        }
        if (to%2==0) {
            res += tree[to];
            --to;
        }
        from /= 2, to /= 2;
    }
    return res;
}

void update(int idx, ll val) {
    idx += OFFSET;
    tree[idx] = val;
    idx /= 2;
    while (idx > 0) {
        tree[idx] = tree[idx*2] + tree[idx*2+1];
        idx /= 2;
    }
}

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i=0; i<N; ++i) scanf("%lld", nos+i);
    init(N);
    for (int t=0; t<M+K; ++t) {
        int a, b;
        ll c;
        scanf("%d %lld %lld", &a, &b, &c);
        if (a == 1) update(b-1, c);
        else printf("%lld\n", query(b-1, c-1));
    }
    return 0;
}