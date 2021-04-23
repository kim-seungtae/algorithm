#include <iostream>
#include <vector>
#include <queue>
//줄 세우기. topological sort
using namespace std;
vector<int> children[32001];
int parCount[32001];
int main() {
    int N, M, A, B;
    scanf("%d %d", &N, &M);
    for (int i=0; i<M; ++i) {
        scanf("%d %d", &A, &B);
        parCount[B] += 1;
        children[A].push_back(B);
    }

    queue<int> q;
    
    while (true) {
        for (int i=1; i<=N; ++i) {
            if (parCount[i] == 0) {
                q.push(i);
                --parCount[i];
            }
        }
        if (q.empty()) break;
        int top = q.front(); q.pop();
        for (int i=0; i<children[top].size(); ++i) {
            --parCount[children[top][i]];
        }
        printf("%d ", top);
    }

    return 0;
}