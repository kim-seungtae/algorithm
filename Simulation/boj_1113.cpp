#include <iostream>
#include <queue>
#define MAX_N       50
#define MAX_M       50
using namespace std;

int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
int max(int a, int b) {return a>b?a:b;}
int min(int a, int b) {return a<b?a:b;}

int N, M, land[MAX_N][MAX_M], water[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

void bfs(int sy, int sx) {
    int height = land[sy][sx] + water[sy][sx];
    queue<pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        --water[y][x];
        q.pop();
        for (int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny<0||ny>=N||nx<0||nx>=M||visited[ny][nx]) continue;
            if (land[ny][nx]+water[ny][nx] == height && water[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
}
int main() {
    cin >> N >> M;
    char input[MAX_M+1];
    for (int i=0; i<N; ++i) {
        cin >> input;
        for (int j=0; j<M; ++j) land[i][j] = input[j] - '0';
    }
    for (int i=1; i<N-1; ++i) for (int j=1; j<M-1; ++j) {
        water[i][j] = 9 - land[i][j];
    }
    for (int h=1; h<10; ++h) {
        for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) visited[i][j] = false;

        for (int i=1; i<N-1; ++i) for (int j=1; j<M-1; ++j) {
            if (visited[i][j] || water[i][j] == 0) continue;
            for (int d=0; d<4; ++d) {
                int ny = i + dy[d];
                int nx = j + dx[d];

                if (land[ny][nx] + water[ny][nx] < land[i][j] + water[i][j]) {
                    bfs(i, j);
                    break;
                }
            }
        }
    }

    int ans = 0;
    for (int i=1; i<N-1; ++i) for (int j=1; j<M-1; ++j) ans += water[i][j];
    cout << ans << endl;
    return 0;
}