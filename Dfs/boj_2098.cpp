#include <cstdio>
#define INF         200000000
#define MAX_N       16
//외판원 순회
using namespace std;

int cache[MAX_N + 1][1 << (MAX_N + 1)];
int map[MAX_N + 1][MAX_N + 1];
int N;
int min(int a, int b) {return a>b?b:a;}
int dfs(int here, int visit) {
    if (visit == (1<<N) - 1) return map[here][1] ? map[here][1] : INF;
    if (cache[here][visit] != -1) return cache[here][visit];

    int ret = INF;
    for (int i=1; i<=N; ++i) {
        if (visit & (1<<(i-1))) continue;
        if (map[here][i] == 0) continue;
        ret = min(ret, dfs(i, visit | 1 << (i-1)) + map[here][i]);
    }
    cache[here][visit] = ret;
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) for (int j=1; j<=N; ++j) scanf("%d", &map[i][j]);
    for (int i=0; i<=N; ++i) for (int j=0; j<=1<<N; ++j) cache[i][j] = -1;
    printf("%d\n", dfs(1, 1));
    return 0;
}