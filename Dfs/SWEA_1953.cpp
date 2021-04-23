#include <iostream>
#include <queue>
#define MAX_M       50
#define MAX_L       20
using namespace std;

int map[MAX_M][MAX_M];
int visit[MAX_M][MAX_M];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int T, N, M, R, C, L, ans;
int isConnected(int ny, int nx, int y, int x, int d) {
    if (d == 0) {
        if (map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 4 || map[y][x] == 7) {
            if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 5 || map[ny][nx] == 6) {
                return 1;
            }
        }
    }
    else if (d == 1) {
        if (map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 4 || map[y][x] == 5) {
            if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 6 || map[ny][nx] == 7) {
                return 1;
            }
        }
    }
    else if (d == 2) {
        if (map[y][x] == 1 || map[y][x] == 2 || map[y][x] == 5 || map[y][x] == 6) {
            if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 4 || map[ny][nx] == 7) {
                return 1;
            }
        }
    }
    else if (d == 3) {
        if (map[y][x] == 1 || map[y][x] == 3 || map[y][x] == 6 || map[y][x] == 7) {
            if (map[ny][nx] == 1 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5) {
                return 1;
            }
        }
    }
    return 0;
}
void dfs(int sy, int sx) {
    queue<pair<pair<int, int>, int>> q;
    q.push({{sy, sx}, 1});
    visit[sy][sx] = 1;
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int t = q.front().second;
        q.pop();
        for (int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < M && map[ny][nx] != 0 && visit[ny][nx] == 0 && t < L) {
                if (isConnected(ny, nx, y, x, i)) {
                    ans += 1;
                    visit[ny][nx] = 1;
                    q.push({{ny, nx}, t+1});
                }
            }
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t=1; t<=T; ++t) {
        cin >> N >> M >> R >> C >> L;
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                cin >> map[i][j];
            }
        }
        ans = 1;
        for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) visit[i][j] = 0;
        dfs(R, C);
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}