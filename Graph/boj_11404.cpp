#include <iostream>
#include <vector>
//플로이드. Floyd-Warshall 왜 INF 21억은 안돼
#define INF         210000000
#define MAX_N       100
int n, m, f, t, d;
int map[MAX_N+1][MAX_N+1];
int min(int a, int b) {return a>b?b:a;}
int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; ++i) {
        scanf("%d %d %d", &f, &t, &d);
        if (map[f][t]) map[f][t] = min(d, map[f][t]);
        else map[f][t] = d;
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (i == j) map[i][j] = 0;
            else if (map[i][j] == 0) map[i][j] = 210000000;
        }
    }

    for (int k=1; k<=n; ++k) {
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {\
            if (map[i][j] == INF) map[i][j] = 0;
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}