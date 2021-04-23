#include <iostream>
#include <vector>
//치킨 배달
using namespace std;

#define MAX_M       13
typedef pair<int, int> pii;
int N, M, ans;
vector<pii> chickens;
vector<pii> houses;
int visit[MAX_M+1];

int abs(int a) {return a>=0?a:-a;}
int min(int a, int b) {return a>b?b:a;}
int hamiltanD(pii a, pii b) {return abs(a.first - b.first) + abs(a.second - b.second);}
void dfs(int idx, int cnt) {
    if (cnt == M) {
        int res = 0;
        for (int i=0; i<houses.size(); ++i) {
            int tmp = __INT_MAX__;
            for (int j=0; j<chickens.size(); ++j) {
                if (visit[j]) tmp = min(tmp, hamiltanD(houses[i], chickens[j]));
            }
            res += tmp;
        }
        ans = min(ans, res);
    }
    if (idx == chickens.size() - 1) return;

    for (int i=idx+1; i<chickens.size(); ++i) {
        visit[i] = true;
        dfs(i, cnt+1);
        visit[i] = false;
    }
}
int main() {
    scanf("%d %d", &N, &M);
    int tmp;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        scanf("%d", &tmp);
        if (tmp == 1) houses.push_back({i, j});
        if (tmp == 2) chickens.push_back({i,j});
    }
    ans = __INT_MAX__;
    dfs(-1, 0);
    printf("%d\n", ans);
    return 0;
}