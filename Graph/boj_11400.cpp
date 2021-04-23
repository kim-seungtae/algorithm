#include <iostream>
#include <vector>
#include <algorithm>
//단절선
using namespace std;

vector<int> adjList[100001];
vector<pair<int, int>> ans;
int order[100001];
int num = 0;

int dfs(int cur, int prev) {
    order[cur] = ++num;
    int ret = order[cur];

    for (int next: adjList[cur]) {
        if (next == prev) continue;
        if (order[next]) {ret = min(ret, order[next]); continue;}
        int m = dfs(next, cur);
        if (m > order[cur]) ans.push_back({min(cur, next), max(cur, next)});
        ret = min(ret, m);
    }
    return ret;
}
int main() {
    int v, e, f, t;
    scanf("%d %d", &v, &e);
    for (int i=0; i<e; ++i) {
        scanf("%d %d", &f, &t);
        adjList[f].push_back(t);
        adjList[t].push_back(f);
    }

    for (int i=1; i<=v; ++i) {
        if (!order[i]) dfs(i, 0);
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto i : ans) {
        printf("%d %d\n", i.first, i.second);
    }

    return 0;
}