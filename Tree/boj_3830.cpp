#include <iostream>
//교수님은 기다리지 않는다. union find
using namespace std;
typedef long long ll;
int par[100001];
ll diff[100001];

ll find(int a) {
    if (a == par[a]) return a;
    int p = find(par[a]); //미리 루트노드 저장. find재귀로 돌면서 diff값 업데이트.
    diff[a] += diff[par[a]];
    return par[a] = p;
}

void merge(int a, int b, int w) {
    int p_a = find(a);
    int p_b = find(b);
    if (p_a == p_b) return;
    diff[p_b] = diff[a] - diff[b] + w;
    par[p_b] = p_a;
    return;
}

int main() {
    int N, M;
    while (true) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;
        for (int i=1; i<=N; ++i) {
            par[i] = i;
            diff[i] = 0;
        }
        char inst;
        int a, b, c;
        for (int i=0; i<M; ++i) {
            scanf(" %c", &inst);
            if (inst == '!') {
                scanf("%d %d %d", &a, &b, &c);
                merge(a, b, c);
            }
            else {
                scanf("%d %d", &a, &b);
                if (find(a) != find(b)) printf("UNKNOWN\n");
                else {
                    printf("%lld\n", diff[b] - diff[a]);
                }
            }
        }
    }
    return 0;
}