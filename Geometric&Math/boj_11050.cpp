#include <cstdio>
//이항 계수1
using namespace std;

int main() {
    int N, K, k, ans = 1;
    scanf("%d %d", &N, &K);
    k=K;
    while (K--) ans *= N--;
    while (k) ans /= k--;
    printf("%d", ans);
    return 0;
}