#include <iostream>
#define MAX_N       64
#define MAX_Q       1000
using namespace std;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
int N, Q;
int L[MAX_Q], ice[2][MAX_N][MAX_N], rTmp[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
void rotate(int I, int J, int L, int p) {
    for (int i=0; i<L; ++i) for (int j=0; j<L; ++j) rTmp[i][j] = ice[p][I+i][J+j];
    for (int i=0; i<L; ++i) {
        for (int j=0; j<L; ++j) {
            ice[p][I+j][J+L-i-1] = rTmp[i][j];
        }
    }
}
void tornado(int L, int p) {
    for (int i=0; i<N; i+=L) for (int j=0; j<N; j+=L) {
        rotate(i, j, L, p);
    }
}
void fireball(int p) {
    int np = (p + 1) % 2;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        if (ice[p][i][j] == 0) {
            ice[np][i][j] = 0;
            continue;
        }
        int adj = 0;
        for (int d=0; d<4; ++d) {
            int ny = i + dy[d], nx = j + dx[d];
            if (ny<0||ny>=N||nx<0||nx>=N||ice[p][ny][nx] == 0) continue;
            ++adj;
        }
        if (adj>=3) ice[np][i][j] = ice[p][i][j];
        else ice[np][i][j] = ice[p][i][j] - 1;
    }
}
int getRemainIce(int p) {
    int ret = 0;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        ret += ice[p][i][j];
    }
    return ret;
}
int dfs(int y, int x, int p) {
    int ret = 1;
    for (int d=0; d<4; ++d) {
        int ny = y + dy[d], nx = x + dx[d];

        if (ny<0||ny>=N||nx<0||nx>=N||visited[ny][nx]||ice[p][ny][nx] == 0) continue;
        visited[ny][nx] = true;
        ret += dfs(ny, nx, p);
    }
    return ret;
}
int getBiggestIce(int p) {
    int ret = 0;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        if (ice[p][i][j] == 0 || visited[i][j]) continue;
        visited[i][j] = true;
        ret = max(ret, dfs(i, j, p));
    }
    return ret;
}
int main() {
    cin >> N >> Q;
    N = 1 << N;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) cin >> ice[0][i][j];
    for (int i=0; i<Q; ++i) cin >> L[i];

    int p = 0;
    for (int i=0; i<Q; ++i) {
        tornado(1<<L[i], p);
        fireball(p);
        p = (p + 1) % 2;
    }
    cout << getRemainIce(p) << '\n' << getBiggestIce(p) << '\n';
    return 0;
}