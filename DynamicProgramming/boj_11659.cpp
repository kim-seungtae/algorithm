#include <iostream>
//구간 합 구하기4
using namespace std;

#define MAX_N       100000

int sum[MAX_N+1];

int main() {
    int n, m, tmp;
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &tmp);
        sum[i] = sum[i-1] + tmp;
    }
    int i, j;
    for (int k=0; k<m; ++k) {
        scanf("%d %d", &i, &j);
        printf("%d\n", sum[j] - sum[i-1]);
    }
    return 0;
}