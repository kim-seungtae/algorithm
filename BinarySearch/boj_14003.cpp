#include <cstdio>
#include <algorithm>
#include <stack>
//가장 긴 증가하는 부분 수열5
using namespace std;

#define MAX_N       1000000
int min(int a, int b) {return a>b?b:a;}
int max(int a, int b) {return a>b?a:b;}
int arr[MAX_N+1], dp[MAX_N+1], num_idx[MAX_N+1]; //i번째 숫자가 dp의 몇번 인덱스에 들어갔는지 저장

int main() {
    int N;
    scanf("%d", &N);
    for (int i=0; i<=N; ++i) dp[i] = __INT_MAX__;
    for (int i=1; i<=N; ++i) scanf("%d", arr+i);
    int idx_max = 0;
    for (int i=1; i<=N; ++i) {
        int idx = lower_bound(dp + 1, dp + N + 1, arr[i]) - dp;
        dp[idx] = arr[i];
        num_idx[i] = idx;
        if (idx_max < idx) idx_max = idx;
    }

    printf("%d\n", idx_max);
    stack<int> s;
    int max_length = idx_max;
    while (s.size() != max_length) {
        if (idx_max == num_idx[N]) {
            --idx_max;
            s.push(arr[N]);
        }
        N--;
    }

    while (!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }

    return 0;
}