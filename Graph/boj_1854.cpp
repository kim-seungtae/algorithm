#include <iostream>
#include <vector>
#include <queue>
#include <stack> //스택으로 하면 마지막에 넣은값이 top이니까
//K번째 최단경로 찾기. dijkstra
using namespace std;

#define INF     -2100000000
#define MAX_L   1001
typedef pair<int, int> pii;

int n, m, k, a, b, c;
vector<pii> edges[1001];
//거리, 노드
priority_queue<pii> pq;
stack<int> dist[MAX_L+1];

int KthDijkstra(int root) {
    pq.push({0, root});
    while (!pq.empty()) {
        int cur = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (dist[cur].size() < k) dist[cur].push(d);
        else continue;

        for (auto next : edges[cur]) {
            if (dist[next.first].size() >= k) continue;
            pq.push({d + next.second, next.first});
        }
    }
    return 0;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i=0; i<m; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        edges[a].push_back({b, -c});
    }


    KthDijkstra(1);

    for (int i=1; i<=n; ++i) {
        if (dist[i].size() < k) printf("-1\n");
        else printf("%d\n", -dist[i].top());
    }
    return 0;
}