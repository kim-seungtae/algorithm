#include <iostream>
//수들의 합2
using namespace std;
int main() {
    int N, M, A[10000];
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; ++i)
        scanf("%d", &A[i]);

    int left=0, right=0, ans=0;
    while (right < N) {
        int sum = 0;
        for (int i=left; i<=right; ++i)
            sum += A[i];
        
        if (sum > M) ++left;
        else if(sum < M) ++right;
        else {
            ++ans;
            ++right; // ++left도 됨
        }
    }
    printf("%d", ans);
    return 0;
}