#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
//거의 최단 경로. 인접 배열로 해서 최단경로간선 찾기
using namespace std;

#define INF     -500001
#define MAX_L   500
typedef pair<int, int> pii;

int edges[MAX_L][MAX_L], n, m;
priority_queue<pii> pq;
int dist[MAX_L];

int max(int a, int b) {return a>b?a:b;}
void dijkstra(int root) {
    dist[root] = 0;
    pq.push({0, root});
    
    while (!pq.empty()) {
        int cur = pq.top().second;
        int val = pq.top().first;
        pq.pop();
        for (int i=0; i<n; ++i) {
            if (edges[cur][i] > 0) continue;
            if (dist[i] < val + edges[cur][i]) {
                dist[i] = val + edges[cur][i];
                pq.push({dist[i], i});
            }
        }
    }
}

int main() {
    int f, t, val, st, dest;
    while(1) {
        scanf("%d %d", &n, &m);
        if (n==0 && m==0) break;
        for (int i=0; i<n; ++i) dist[i] = INF;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            edges[i][j] = 1;
        }

        scanf("%d %d", &st, &dest);
        for (int i=0; i<m; ++i) {
            scanf("%d %d %d", &f, &t, &val);
            edges[f][t] = -val;
        }

        dijkstra(st);
        stack<int> s;
        s.push(dest);
        while (!s.empty()) {
            int top = s.top(); s.pop();
            for (int i=0; i<n; ++i) {
                if (edges[i][top] != 1 && dist[top] == dist[i] + edges[i][top]) {
                    s.push(i);
                    edges[i][top] = 1;
                }
            }
        }
        for (int i=0; i<n; ++i) dist[i] = INF;
        dijkstra(st);
        if (dist[dest] == INF) printf("-1\n");
        else printf("%d\n", -dist[dest]);
    }

    return 0;
}