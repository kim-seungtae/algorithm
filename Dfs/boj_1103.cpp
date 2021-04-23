#include <cstdio>
using namespace std;
#define MAX_N   50

int map[MAX_N][MAX_N];
int mvX[4] = {1,-1,0,0}, mvY[4] = {0,0,1,-1};
bool visited[MAX_N][MAX_N], loop = false;
int dp[MAX_N][MAX_N];
int R, C, ans;
//게임
void backtracking(int y, int x, int cnt) {
    if (cnt > ans) ans = cnt;
    dp[y][x] = cnt;

    for (int i=0; i<4; i++) {
        int ny = y + map[y][x] * mvY[i];
        int nx = x + map[y][x] * mvX[i];

        if (ny >= 0 && ny < R && nx >= 0 && nx < C && map[ny][nx] != -1) {
            if (visited[ny][nx]) {
                loop = true;
                return;
            }
            if (dp[ny][nx] > cnt) continue;
            visited[ny][nx] = true;
            backtracking(ny, nx, cnt+1);
            visited[ny][nx] = false;
        }
    }
}
int main() {
    scanf("%d %d", &R, &C);
    for (int y=0; y<R; y++) {
        char ch[51];
        scanf("%s", ch);
        for (int x=0; x<C; x++) {
            if (ch[x] == 'H') map[y][x] = -1;
            else map[y][x] = ch[x] - '0';
        }
    }
    backtracking(0,0,1);
    if (loop) printf("-1");
    else printf("%d", ans);
    return 0;
}