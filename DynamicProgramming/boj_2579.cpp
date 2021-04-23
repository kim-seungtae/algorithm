#include <iostream>
//계단 오르기
using namespace std;

#define MAX_N       300
//dp배열은 dp까지의 최대값이 아니라 dp를 밟았을 때 최대값을 저장한다. 30 50 10에서 dp[2] = 80이 아니고 60.
int max(int a, int b) {return a>b?a:b;}
int stairs[MAX_N], dp[MAX_N]; 

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", stairs+i);
    }
    
    dp[0] = stairs[0];
    dp[1] = stairs[0] + stairs[1];
    dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
    for (int i=3; i<n; ++i) {
        dp[i] = max(dp[i-2] + stairs[i], dp[i-3] + stairs[i-1] + stairs[i]);
    }
    printf("%d", dp[n-1]);
    return 0;
}