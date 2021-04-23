#include <iostream>
//나무 자르기
using namespace std;
typedef long long ll;
int N, M, m, ans;
int tree[1000000];
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; ++i) {
        scanf("%d", &tree[i]);
        if (m < tree[i]) m = tree[i];
    }

    ll low = 0, high = m, mid;
    while (low <= high) {
        mid = (low + high) / 2;

        ll total = 0;
        for (int i=0; i<N; ++i) {
            if (tree[i] - mid > 0) total += (tree[i] - mid);
        }

        if (total >= M) {
            if (ans < mid) ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    printf("%d", ans);
    return 0;
}