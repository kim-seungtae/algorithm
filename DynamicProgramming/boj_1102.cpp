#include <iostream>
#include <cstring>
#define INF         2000000000
#define MAX_N       16
//발전소. 이전노드에서 출발해야할 필요없으니까 cache가 1차원배열. dfs안에서도 2중포문으로 다 찾아야됨.
using namespace std;

int N, P;
int cost[MAX_N][MAX_N];
int cache[1<<(MAX_N)];

int min(int a, int b) {return a>b?b:a;}
bool finish(int v) {
    int On = 0;
    for (int i=0; i<N; ++i) {
        if (v & 1<<i) ++On;
    }
    if (On >= P) return true;
    else return false;
}

int dfs(int cnt, int v) {
    if (cnt >= P) return 0;
    if (cache[v] != -1) return cache[v];

    int ret = INF;
    for (int i=0; i<N; ++i) {
        if (!(v & 1<<i)) continue;
        for (int j=0; j<N; ++j) {
            if (i==j) continue;
            if (v & (1 << j)) continue;
            ret = min(ret, cost[i][j] + dfs(cnt+1, v|(1<<j)));
        }
    }
    cache[v] = ret;
    return ret;
}
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) scanf("%d", &cost[i][j]);
    char tmp[MAX_N+1];
    scanf("%s", tmp);
    scanf("%d", &P);

    int visit = 0, cnt = 0;
    for (int i=1; i<=strlen(tmp); ++i) {
        if (tmp[i-1] == 'Y') visit |= 1<<(i-1), ++cnt;
    }

    for (int i=0; i<(1<<N); ++i) cache[i] = -1;

    if (cnt == 0 && P > 0) printf("-1\n");
    else if(cnt == 0 && P == 0) printf("0\n");
    else printf("%d\n", dfs(cnt, visit));
    
    return 0;
}