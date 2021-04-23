#include <cstdio>
//Dance Dance Revolution
using namespace std;

#define INF         200000000
#define MAX_L       100000
int N, s;
int arr[MAX_L+1];
int dp[5][5][MAX_L+1]; //0중앙 1위 2왼쪽 3밑 4오른쪽
int abs(int a) {return a>0?a:-a;}
int min(int a, int b) {return a>b?b:a;}

int move(int leftPos, int rightPos, int nextPosIdx) {
    if (arr[nextPosIdx] == 0) return 0;
    if (dp[leftPos][rightPos][nextPosIdx]) return dp[leftPos][rightPos][nextPosIdx];
    int res = INF, cost;
    if (arr[nextPosIdx] == leftPos || arr[nextPosIdx] == rightPos)
        res = min(res, 1 + move(leftPos, rightPos, nextPosIdx+1));
    else {
        //move left
        if (leftPos == 0) cost = 2;
        else if (abs(leftPos - arr[nextPosIdx]) == 2) cost = 4;
        else cost = 3;

        res = min(res, cost + move(arr[nextPosIdx], rightPos, nextPosIdx+1));
        //move right
        if (rightPos == 0) cost = 2;
        else if (abs(rightPos - arr[nextPosIdx]) == 2) cost = 4;
        else cost = 3;

        res = min(res, cost + move(leftPos, arr[nextPosIdx], nextPosIdx+1));
    }
    dp[leftPos][rightPos][nextPosIdx] = res;
    return res;
}
int main() {
    s=0;
    while (1) {
        scanf("%d", &arr[s++]);
        if (arr[s-1] == 0) break;
    }

    int ans = move(0, 0, 0);
    printf("%d\n", ans);
    return 0;
}