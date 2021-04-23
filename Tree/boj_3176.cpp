#include <iostream>
#include <vector>
//도로 네트워크. LCA
using namespace std;

#define MAX_N       100000
#define MAX_DEPTH   17
int N, K;
int depth[MAX_N+1];
int par[MAX_N+1][MAX_DEPTH+1];
int min_dp[MAX_N+1][MAX_DEPTH+1], max_dp[MAX_N+1][MAX_DEPTH+1];
//인접 노드 번호, 거기까지 값
vector<pair<int, int>> adjList[MAX_N+1];

int max(int a, int b) {return a>b?a:b;}
int min(int a, int b) {return a<b?a:b;}
void swap(int& a, int& b) {int tmp = a; a = b; b = tmp;}

void make_tree(int here, int parent, int val) {
    if (here == 1) depth[here] = 1;
    else {
        depth[here] = depth[parent] + 1;
        par[here][0] = parent;
    }
    min_dp[here][0] = val;
    max_dp[here][0] = val;

    for (auto i : adjList[here]) {
        if (i.first == parent) continue; //트리니까 visit없이 이렇게해도됨
        // par[i.first][0] = here;
        make_tree(i.first, here, i.second);
    }    
}

void make_dp() {
    for (int i=1; i<=MAX_DEPTH; ++i) {
        for (int j=1; j<=N; ++j) {
            min_dp[j][i] = min(min_dp[j][i-1], min_dp[par[j][i-1]][i-1]);
            max_dp[j][i] = max(max_dp[j][i-1], max_dp[par[j][i-1]][i-1]);
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
}


int main() {
    scanf("%d", &N);
    int a, b, c, d, e;
    for (int i=0; i<N-1; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        adjList[a].push_back({b, c});
        adjList[b].push_back({a, c});

    }
    make_tree(1,0,0);
    make_dp();
    
    scanf("%d", &K);
    
    while (K--) {
        int st, end;
        int min_ans = 1000001, max_ans = -1;
        scanf("%d %d", &st, &end);

        int low = st, high = end;
        if (depth[st]!= depth[end]) {
            if (depth[st] > depth[end]) {low = st; high = end;}
            else {high = st; low = end;}
            for (int i=MAX_DEPTH; i>=0; --i) {
                if (depth[high] > depth[par[low][i]]) continue;
                min_ans = min(min_ans, min_dp[low][i]);
                max_ans = max(max_ans, max_dp[low][i]);
                low = par[low][i];
            }
        }

        if (low == high) printf("%d %d\n", min_ans, max_ans); //둘이 같으면 lca
        else { //둘이 다르면 lca 밑까지 찾아서 마지막에 lca꺼랑 비교해야됨
            for (int i=MAX_DEPTH; i>=0; --i) {
                if (par[low][i] != par[high][i]) {
                    min_ans = min(min_ans, min(min_dp[low][i], min_dp[high][i]));
                    max_ans = max(max_ans, max(max_dp[low][i], max_dp[high][i]));
                    low = par[low][i];
                    high = par[high][i];
                }
            }
            min_ans = min(min_ans, min(min_dp[high][0], min_dp[low][0]));
            max_ans = max(max_ans, max(max_dp[high][0], max_dp[low][0]));
            printf("%d %d\n", min_ans, max_ans);
        }
    }
    return 0;
}