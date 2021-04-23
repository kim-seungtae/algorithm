#include <iostream>
#include <vector>
#include <algorithm>
//네트워크 연결 MST
using namespace std;
typedef pair<int, int> pii;
int par[1001];
vector<pair<int, pii>> adjList;

int find(int a) {
    if (a == par[a]) return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b) {
    int p_a = find(a);
    int p_b = find(b);
    if (p_a == p_b) return;
    par[p_a] = p_b;
}

int main() {
    int N, M, a, b, c;
    scanf("%d %d", &N, &M);
    for (int i=1; i<=N; ++i) par[i] = i;
    for (int i=0; i<M; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        adjList.push_back({c, {a,b}});
    }
    sort(adjList.begin(), adjList.end());
    int ans = 0, edge = 0;
    int s = adjList.size();
    for (int i=0; i<s; ++i) {
        if (edge == N-1) break;
        int x = adjList[i].second.first;
        int y = adjList[i].second.second;

        if (find(x) == find(y)) continue;
        ++edge;
        merge(x, y);
        ans += adjList[i].first;
    }

    printf("%d", ans);
    return 0;
}