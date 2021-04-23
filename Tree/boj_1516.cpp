#include <iostream>
#include <vector>
#include <queue>
//게임 개발
using namespace std;
int max(int a, int b) {return a>b? a:b;}
typedef pair<int, int> pii;
vector<int> children[501];
//총 시간, 남은 부모 수
pii node[501];
int result[501];

int main() {
    int N, buildTime, pred;
    scanf("%d", &N);
    for (int i=1; i<=N; ++i) {
        scanf("%d", &buildTime);
        node[i].first = buildTime;
        result[i] = buildTime;
        while(true) {
            scanf("%d", &pred);
            if (pred == -1) break;
            children[pred].push_back(i);
            ++node[i].second;
        }
    }

    queue<int> q;
    for (int i=1; i<=N; ++i) {
        if (node[i].second == 0) q.push(i);
        //이거 있으면 왜 안됨? 상관없는데
        //--node[i].second;
    }
    while (!q.empty()) {
        int cur = q.front(); q.pop();

        int childIdx;
        for (int i=0; i<children[cur].size(); ++i) {
            childIdx = children[cur][i];
            result[childIdx] = max(result[childIdx], node[childIdx].first + result[cur]);
            --node[childIdx].second;

            if (node[childIdx].second == 0) {
                q.push(childIdx);
            }
        }
    }
    for (int i=1; i<=N; ++i) {
        printf("%d\n", result[i]);
    }
    return 0;
}