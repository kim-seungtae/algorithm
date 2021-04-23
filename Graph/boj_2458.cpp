#include <iostream>
#include <vector>
#include <stack>
//1. 키 순서 dfs로 한 노드에서 방문가능한 노드들에  cnt++하면 내 뒤에 몇갠지 알 수 있다.
//2. Floyd_Warshall도 가능
using namespace std;

#define MAX_N       500

vector<int> edges[MAX_N+1];
int n, m;
int cnt[MAX_N+1];
bool visit[MAX_N+1];

void dfs(int root) {
    int less = 0;
    stack<int> s;
    s.push(root);
    visit[root] = true;
    while(!s.empty()) {
        int cur = s.top(); s.pop();
        if (root != cur) ++cnt[root], ++cnt[cur];
        for (int next: edges[cur]) {
            if (!visit[next]) {
                visit[next] = true;
                s.push(next);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int a, b;
    for (int i=0; i<m; ++i) {
        scanf("%d %d", &a, &b);
        edges[a].push_back(b);
    }

    for (int i=1; i<=n; ++i) {
        dfs(i);
        for (int j=1; j<=n; ++j) visit[j] = false;
    }

    int ans = 0;
    for (int i=1; i<=n; ++i) {
        if (cnt[i] == n-1) ++ans;
    }
    printf("%d\n", ans);


    return 0;
}