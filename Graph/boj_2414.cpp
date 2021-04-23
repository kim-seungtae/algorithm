#include <iostream>
#include <vector>
#define MAX_N       50
#define MAX_M       50
#define MAX_H       1250
using namespace std;
int N, M;
int aMatch[MAX_H+1], bMatch[MAX_H+1];
char map[MAX_N][MAX_N];
int rMap[MAX_N][MAX_N], cMap[MAX_N][MAX_M];
bool holeNum[MAX_H+1];
int tapeNum;
vector<int> adj[MAX_H+1];
bool visited[MAX_H+1];
bool dfs(int idx) {
    if (visited[idx]) return false;
    visited[idx] = true;

    for (int next : adj[idx]) {
        if (bMatch[next] == -1 || dfs(bMatch[next])) {
            aMatch[idx] = next;
            bMatch[next] = idx;
            return true;
        }
    }
    return false;
}
int bipartite() {
    for (int i=1; i<=MAX_H; ++i) aMatch[i] = -1;
    for (int i=1; i<=MAX_H; ++i) bMatch[i] = -1;

    int ans = 0;
    for (int i=1; i<=tapeNum; ++i) {
        for (int j=1; j<=MAX_H; ++j) visited[j] = false;
        if (dfs(i)) ++ans;
    }
    return ans;
}
int main() {
    cin >> N >> M;
    char ch[MAX_M+1];
    for (int i=0; i<N; ++i) {
        cin >> ch;
        for (int j=0; j<M; ++j)
            map[i][j] = ch[j];
    }

    tapeNum = 1;
    for (int i=0; i<N; ++i) {
        if (holeNum[tapeNum]) ++tapeNum;
        for (int j=0; j<M; ++j) {
            if (map[i][j] == '*') {
                rMap[i][j] = tapeNum;
                holeNum[tapeNum] = true;
            }
            else {
                if (holeNum[tapeNum]) ++tapeNum;
            }
        }
    }
    int tmp = tapeNum;
    tapeNum = 1;
    for (int i=1; i<=MAX_H; ++i) holeNum[i] = false;
    for (int j=0; j<M; ++j) {
        if (holeNum[tapeNum]) ++tapeNum;
        for (int i=0; i<N; ++i) {
            if (map[i][j] == '*') {
                cMap[i][j] = tapeNum;
                holeNum[tapeNum] = true;
            }
            else {
                if (holeNum[tapeNum]) ++tapeNum;
            }
        }
    }
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (rMap[i][j] != 0) {
                adj[rMap[i][j]].push_back(cMap[i][j]);
            }
        }
    }
    tapeNum = tmp;
    cout << bipartite() << endl;
    return 0;
}