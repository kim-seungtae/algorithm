#include <iostream>
#include <vector>
#include <queue>
//최단 경로. 다익스트라
using namespace std;
#define INF     -3000001
//시작점부터 나까지 거리, 현재 노드번호
// priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<pair<int, int>> pq;
    //To, distance
vector<pair<int, int>> edges[20001];
int dist[20001];
void dijkstra(int root) {
    dist[root] = 0;
    pq.push({0, root});

    while (!pq.empty()) {
        int cur = pq.top().second;
        int val = pq.top().first;
        pq.pop();
        for (auto i : edges[cur]) {
            if (val + i.second > dist[i.first]) {
                dist[i.first] = val + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }
}

int main() {
    int v, e, root, f, t, val;
    scanf("%d %d %d", &v, &e, &root);
    for (int i=1; i<=v; ++i) dist[i] = INF;
    for (int i=0; i<e; ++i) {
        scanf("%d %d %d", &f, &t, &val);
        edges[f].push_back({t, -val});
    }

    dijkstra(root);

    for (int i=1; i<=v; ++i) {
        if (dist[i] == INF) printf("INF\n");
        else printf("%d\n", -dist[i]);
    }
    return 0;
}