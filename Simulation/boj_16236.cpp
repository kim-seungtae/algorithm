#include <iostream>
#include <queue>
#define MAX_N       20
#define piii pair<pair<int, int>, int>
using namespace std;
//아기 상어
int map[MAX_N][MAX_N];
int visit[MAX_N][MAX_N];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int N, shark_size, shortest_len, sy, sx, fy, fx, ans;
void input() {
    cin >> N;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        cin >> map[i][j];
        if (map[i][j] == 9) {
            sy=i;
            sx=j;
            map[i][j] = 0;
        }
    }
    shark_size = 2;
    ans = 0;
}

int main() {
    ios::sync_with_stdio(false);
    input();

    queue<piii> q;
    int fish_count = 0;
    while(1) {
        //큐, visit 초기화
        while(!q.empty()) q.pop();
        for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) visit[i][j] = 0;
        q.push({{sy, sx}, 0});
        shortest_len = MAX_N * MAX_N;
        fy = MAX_N, fx = MAX_N;
        //bfs로 가장 가까운 먹이 찾기
        while (!q.empty()) {
            int y = q.front().first.first;
            int x = q.front().first.second;
            int len = q.front().second;
            q.pop();
            if (shortest_len < len) break;
            if (map[y][x] > shark_size) continue;
            if (map[y][x] > 0 && map[y][x] < shark_size) {
                shortest_len = len;
                if (fy > y) {
                    fy = y;
                    fx = x;
                }
                else if (fy == y) {
                    if (fx > x) {
                        fy = y;
                        fx = x;
                    }
                }
            }
            for (int i=0; i<4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                if (visit[ny][nx] == 0) {
                    visit[ny][nx] = 1;
                    q.push({{ny, nx}, len+1});
                }
            }
        }
        //먹이 없으면 break
        if (fy == MAX_N && fx == MAX_N) break;

        //먹은거 +1하고 사이즈 업데이트
        fish_count += 1;
        if (fish_count == shark_size) {
            fish_count = 0;
            shark_size += 1;
        }
        //답 업데이트
        ans += shortest_len;
        map[fy][fx] = 0;
        sy = fy, sx = fx;
    }
    cout << ans << endl;
    return 0;
}