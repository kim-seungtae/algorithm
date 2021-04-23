#include <iostream>
using namespace std;
typedef long long ll;
//피보나치 수2
ll D[100];

void fibonacci(int n) {
    D[0] = 0; D[1] = 1;
    for (int i=2; i<=n; ++i) D[i] = D[i-1] + D[i-2];
}

int main() {
    int n;
    scanf("%d", &n);
    fibonacci(n);
    printf("%lld", D[n]);
    return 0;
}