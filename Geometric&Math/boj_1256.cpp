#include <cstdio>
//사전
using namespace std;

#define MAX_N       200
#define MOD         10007
#define INF         1000000001

int N, M, K, combi[201][201];
char ans[201];
int min(int a, int b) { return a > b ? b : a;}

// void calcCombination() {
//     int n, k;
//     for (n=0; n <= MAX_N; ++n) {
//         combi[n][0] = combi[n][n] = 1;
//         for (k=1; k<n; ++k) combi[n][k] = min(1000000001, combi[n-1][k] + combi[n-1][k-1]);
//     }
// }

// int main() {
//     int L, loc = 0;
//     scanf("%d %d %d", &N, &M, &K);
//     L = N + M;
//     calcCombination();

//     if (K <= combi[L][M]) {
//         while (--L >= 0) {
//             if (combi[L][M] >= K) ans[loc++] ='a';
//             else {
//                 ans[loc++] = 'z';
//                 K -= combi[L][M];
//                 --M;
//             }
//         }
//         ans[loc] = '\0';
//         printf("%s\n", ans);
//     }
//     else printf("-1\n");

//     return 0;
// }


void nk() {
    int n, k;
    for (n=0; n<=MAX_N; ++n) {
        combi[n][0] = combi[n][n] = 1;
        for (k=1; k<n; ++k) combi[n][k] = min(1000000001, combi[n-1][k-1] + combi[n-1][k]);
    }
}

int main() {
    int L, loc=0;
    scanf("%d %d %d", &N, &M, &K);
    L = N + M;

    nk();

    if (K <= combi[L][M]) {
        while (--L >= 0) {
            if (combi[L][M] >= K) ans[loc++] = 'a';
            else {
                K -= combi[L][M];
                ans[loc++] = 'z';
                M--;
            }
        }
        ans[loc] = '\0';
        printf("%s\n", ans);
    }
    else printf("-1\n");

}