#include <iostream>
#define MAX_N       500
#define MAX_M       500
using namespace std;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
int M, N, H;
int height[MAX_N][MAX_M];
int dp[MAX_N][MAX_M];
int dfs(int sy, int sx) {
    if (sy == N-1 && sx == M-1) return 1;
    if (dp[sy][sx] != -1) return dp[sy][sx];
    dp[sy][sx] = 0;
    for (int i=0; i<4; ++i) {
        int ny = sy + dy[i];
        int nx = sx + dx[i];
        if (ny<0||ny>=N||nx<0||nx>=M) continue;
        if (height[ny][nx] >= height[sy][sx]) continue;
        dp[sy][sx] += dfs(ny, nx);
    }
    return dp[sy][sx];
}
int main() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) {
        cin >> height[i][j];
        dp[i][j] = -1;
    }
    H = dfs(0, 0);
    cout << H << endl;
    return 0;
}
