#include <iostream>
#include <vector>
#include <cstring>
//경찰차 왜 cache초기화를 0부터 W+1까지 하냐 W까지밖에 안쓰는데??
// dfs dfs2에서 a b가 W를 넘는경우가 왜 생기냐 ==으로 하면 W+1까지, >=로 하면 W까지 초기화
using namespace std;
#define INF         2000000000
#define MAX_L       1000
typedef pair<int, int> pii;
int abs(int a) {return a>0?a:-a;}
int min(int a, int b) {return a>b?b:a;}
int max(int a, int b) {return a>b?a:b;}

int N, W;
pii A[MAX_L+100], B[MAX_L+100];
int cache[MAX_L+1][MAX_L+1];

int hamiltanD(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int dfs(int a, int b) {
    if (a >= W || b >= W) return 0;
    if (cache[a][b] != -1) return cache[a][b];
    int Widx = max(a, b) + 1;

    int ret = INF;
    ret = min(ret, hamiltanD(A[a], A[Widx]) + dfs(Widx, b));
    ret = min(ret, hamiltanD(B[b], B[Widx]) + dfs(a, Widx));
    cache[a][b] = ret;
    return ret;
}

void dfs2(int a, int b) {
    if (a>=W || b>=W) return;
    int Widx = max(a, b) + 1;
    int res1 = hamiltanD(A[a], A[Widx]) + dfs(Widx, b);
    int res2 = hamiltanD(B[b], B[Widx]) + dfs(a, Widx);

    if (res1 > res2) {
        printf("%d\n", 2);
        dfs2(a, Widx);
    }
    else {
        printf("%d\n", 1);
        dfs2(Widx, b);
    }
}
int main() {
    scanf("%d %d", &N, &W);
    for (int i=0; i<=W; ++i) for (int j=0; j<=W; ++j) cache[i][j] = -1;
    A[0].first = 1, A[0].second = 1;
    B[0].first = N, B[0].second = N;
    int x,  y;
    for (int i=1; i<=W; ++i) {
        scanf("%d %d", &x, &y);
        A[i].first = x;
        A[i].second = y;
        B[i].first = x;
        B[i].second = y;
    }
    printf("%d\n", dfs(0,0));
    dfs2(0, 0);
    return 0;
}