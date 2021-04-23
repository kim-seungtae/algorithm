#include <iostream>
#include <vector>
#include <queue>
//할로윈 묘지. Bellman-Ford
using namespace std;

#define INF         2100000000
#define MAX_H       30
#define MAX_W       30

typedef pair<int, int> pii;
vector<pair<int, pii>> edges;
vector<int> graves;
vector<int> holes;
int W, H, dist[MAX_H*MAX_W];
bool isCycle = false;
//구멍아니면 true
bool checkHoles(int idx) {
    for (int i : holes) {
        if (idx == i) return false;
    }
    return true;
}
//묘비 없으면 true
bool checkGraves(int idx) {
    for (int i : graves) {
        if (idx == i) return false;
    }
    return true;
}
void Bellman_Ford(int root) {
    dist[root] = 0;

    for (int i=0; i<W*H; ++i) {
        for (auto next:edges) {
            if (dist[next.second.first] == INF) continue;
            if (dist[next.second.second] > dist[next.second.first] + next.first) {
                dist[next.second.second] = dist[next.second.first] + next.first;
            }
        }
    }

    isCycle = false;
    for (auto next:edges) {
        if (dist[next.second.first] == INF) continue;
        if (dist[next.second.second] > dist[next.second.first] + next.first) {
            isCycle = true;
        }
    }
}

int main() {
    int  G, E, w, h, val;
    while(true) {
        scanf("%d %d", &H, &W);
        if (H==0 && W==0) break;

        for (int i=0; i<H*W; ++i) dist[i] = INF;
        graves.clear();
        edges.clear();
        holes.clear();
        scanf("%d", &G);
        for (int i=0; i<G; ++i) {
            scanf("%d %d", &h, &w);
            graves.push_back(h*W+w);
        }
        scanf("%d", &E);
        int w2, h2;
        for (int i=0; i<E; ++i) {
            scanf("%d %d %d %d %d", &h, &w, &h2, &w2, &val);
            edges.push_back({val, {h*W+w, h2*W+w2}});
            holes.push_back(h*W+w);
        }
        for (int i=0; i<W*H-1; ++i) {
            if (!checkGraves(i) || !checkHoles(i)) continue;
            if (i-1 >= 0 && checkGraves(i-1) && i/W == (i-1)/W) edges.push_back({1, {i, i-1}});
            if (i+1 <W*H && checkGraves(i+1) && i/W == (i+1)/W) edges.push_back({1, {i, i+1}});
            if (i-W >= 0 && checkGraves(i-W)) edges.push_back({1, {i, i-W}});
            if (i+W <W*H && checkGraves(i+W)) edges.push_back({1, {i, i+W}});
        }
        // for (auto i : edges) {
        //     printf("{%d,{%d,%d}} ", i.first, i.second.first, i.second.second);
        // }

        Bellman_Ford(0);

        if (isCycle) printf("Never\n");
        else if (dist[W*H-1] == INF) printf("Impossible\n");
        else printf("%d\n", dist[W*H-1]);
    }
    return 0;
}