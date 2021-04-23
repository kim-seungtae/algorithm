#include <cstdio>
//1학년
using namespace std;
typedef long long ll;
ll cnt[21][100];
int N, num[101];

// int main() {
//     scanf("%d", &N);
//     for (int i=1; i<=N; ++i) scanf("%d", num+i);
    
//     cnt[num[1]][1] = 1;
//     for (int i=2; i<N; ++i) {
//         for (int j=0; j<=20; ++j) {
//             if (j - num[i] >= 0) cnt[j - num[i]][i] += cnt[j][i-1];
//             if (j + num[i] <= 20) cnt[j + num[i]][i] += cnt[j][i-1];
//         }
//     }

//     printf("%lld\n", cnt[num[N]][N-1]);

//     return 0;
// }

int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) scanf("%d", num + i);
    cnt[num[1]][1] = 1;

    for (int i=2; i<=N; ++i) {
        for (int j=0; j<=20; ++j) {
            int plus = num[i] + j;
            int minus = j - num[i];
            if (plus <= 20) cnt[plus][i] += cnt[j][i-1];
            if (minus >= 0) cnt[minus][i] += cnt[j][i-1];
        }
    }
    printf("%lld", cnt[num[N]][N-1]);
    return 0;
}