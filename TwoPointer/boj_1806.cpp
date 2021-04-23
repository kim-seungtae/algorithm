#include <iostream>
//부분합
using namespace std;

int main() {
    int N, S, sum, l=0, r=0, ans=100001, num[100000];
    scanf("%d %d", &N, &S);

    for (int i=0; i<N; ++i)
        scanf("%d", &num[i]);

    sum = num[0];
    while (r < N) {
        if (sum >= S) {
            if (r-l+1 < ans) ans = r-l+1;
            if (sum == S) sum += num[++r];
            else sum -= num[l++];
        }
        else sum += num[++r];
    }
    if (ans == 100001) printf("0");
    else printf("%d", ans);
    return 0;
}