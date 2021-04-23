#include <iostream>
//집합의 표현
int par[1000001];

int find(int a) {
    if (a == par[a]) return a;
    return par[a] = find(par[a]);
}

void merge(int a, int b) {
    int p_a = find(a);
    int p_b = find(b);
    if (p_a == p_b) return;
    else par[p_a] = p_b;
}

bool check(int a, int b) {
    int p_a = find(a);
    int p_b = find(b);
    if (p_a == p_b) return true;
    else return false;
}

int main() {
    int N, M, a, b, c;
    scanf("%d %d", &N, &M);
    for (int i=0; i<=N; ++i) par[i] = i;

    for (int i=0; i<M; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0) merge(b, c);
        else {
            bool ret = check(b,c);
            if (ret) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}