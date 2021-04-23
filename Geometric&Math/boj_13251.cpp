#include <cstdio>
#include <vector>
#include <algorithm>
//조약돌 꺼내기
using namespace std;
double combi[2502][2502];

void calc(int total) {
    for (int n=1; n<=total; ++n) {
        combi[n][0] = combi[n][n] = 1.0;
        for (int k=1; k<n; ++k) combi[n][k] = combi[n-1][k] + combi[n-1][k-1];
    }
}

int main() {
    int M, C[50], N=0, K;
    scanf("%d", &M);
    
    for (int i=0; i<M; ++i) {
        scanf("%d", C+i);
        N += C[i];
    }
    scanf("%d", &K);

    calc(N);
    
    double ans = 0.0;
    for (int i=0; i<M; ++i) ans += combi[C[i]][K];
    ans /= combi[N][K];
    printf("%.9lf", ans);
    return 0;
}