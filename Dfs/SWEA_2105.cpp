#include <iostream>
using namespace std;

int ans, T, N, sy, sx;
int cafe[20][20], dessert[101];
int dy[4] = {1,1,-1,-1};
int dx[4] = {1,-1,1,-1};
int max(int a, int b) {return a>b?a:b;}
int dfs(int y, int x, int score, int curD, int curve_count) {
    if (curve_count >= 5) return -1;
    dessert[cafe[y][x]] = 1;
    int tmp = -1;
    for (int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
            if (sy == ny && sx == nx && curve_count >= 3) {
                dessert[cafe[y][x]] = 0;
                return score;
            }
            if (!dessert[cafe[ny][nx]]) {
                if (curD == i) tmp = max(tmp, dfs(ny, nx, score+1, i, curve_count));
                else tmp = max(tmp, dfs(ny, nx, score+1, i, curve_count+1));
            }
        }
    }
    dessert[cafe[y][x]] = 0;
    return tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N;
        for (int y=0; y<N; y++) for (int x=0; x<N; x++)
            cin >> cafe[y][x];

        ans = -1;
        for (int y=0; y<N; y++) for (int x=0; x<N; x++) {
            sy = y;
            sx = x;
            ans = max(ans, dfs(sy, sx, 1, -1, 0)); // 방향을 -1로해서 처음에 다 꺾이게 한다음에 꺾인 횟수가 3,4가 아니라 4,5면 사각형
        }
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}