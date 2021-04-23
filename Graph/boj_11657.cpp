#include <iostream>
#include <vector>
#include <queue>
//타임머신. Bellman-Ford
using namespace std;

#define MAX_L       500
#define INF         5000001

typedef pair<int, int> pii;
typedef long long ll;
int N, M;
int dist[MAX_L+1];
//{거리, {from, to}}
vector<pair<ll, pii>> edges;
bool isCycle;
void Bellman_Ford(int root) {
    dist[root] = 0;
    
    for (int i=1; i<=N; ++i) {
        for (auto next : edges) {
            if (dist[next.second.first] == INF) continue;
            if (dist[next.second.second] > dist[next.second.first] + next.first) {
                dist[next.second.second] = dist[next.second.first] + next.first;
            }
        }
    }
    isCycle = false;
    for (auto i : edges) {
        if (dist[i.second.first] == INF) continue;
        if (dist[i.second.second] > dist[i.second.first] + i.first) {
            isCycle = true;
        }
    }
}

int main() {
    int A, B, C;
    scanf("%d %d", &N, &M);
    for (int i=0; i<M; ++i) {
        scanf("%d %d %lld", &A, &B, &C);
        edges.push_back({C, {A, B}});
    }
    for (int i=0; i<=N; ++i) dist[i] = INF;    

    Bellman_Ford(1);
    if (isCycle) printf("-1");
    else {
        for (int i=2; i<=N; ++i) {
            if (dist[i] == INF) printf("-1\n");
            else printf("%d\n", dist[i]);
        }
    }
    return 0;
}