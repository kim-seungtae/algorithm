#include <iostream>
#include <vector>
#include <algorithm>
//합이 0인 네 정수 배열 2개 완탐으로 합 구하고 2개 2-pointer
using namespace std;
typedef long long ll;
int n;
ll ans;
int A[4000], B[4000], C[4000], D[4000];
vector<ll> a, b;
int main() {
    scanf("%d", &n);
    for (int i=0; i<n; ++i)
        scanf("%d %d %d %d", A+i, B+i, C+i, D+i);

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; j++) {
            a.push_back(A[i]+B[j]);
            b.push_back(C[i]+D[j]);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());

    int i1=0, i2=0;
    while (i1 < a.size() && i2 < b.size()) {
        if (a[i1] + b[i2] > 0) ++i2;
        else if (a[i1] + b[i2] < 0) ++i1;
        else {
            ll t1 = a[i1], t2 = b[i2], cnt1=0, cnt2=0;
            while (i1 < a.size() && a[i1] == t1)  {
                ++cnt1;
                ++i1;
            }
            while (i2 < b.size() && b[i2] == t2) {
                ++cnt2;
                ++i2;
            }
            ans += cnt1 * cnt2;
        }
    }
    printf("%lld", ans);
    return 0;
}