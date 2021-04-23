#include <iostream>
#include <queue>
#define INF         1000000000
#define MAX_N       50
using namespace std;
typedef pair<int, int> pii;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
int N, M;
int minsik, ans;
pair<char, int> map[MAX_N][MAX_N]; // first : map. second : 그 때 왔을 때 가지고 있던 key
bool visited[MAX_N][MAX_N][64];
void input() {
    cin >> N >> M;
    for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) for (int k=0; k<64; ++k) visited[i][j][k] = false;
    for (int i=0; i<N; ++i) for (int j=0; j<M; ++j) {
        cin >> map[i][j].first;
        if (map[i][j].first == '0') {
            visited[i][j][0] = true;
            minsik = i*M + j;
        }
        map[i][j].second = 0;
    }
}

int main() {
    input();
    queue<pair<int, pii>> q; //{pos, {time, keys}}
    q.push({minsik,{0, 0}});
    while(!q.empty()) {
        int y = q.front().first / M;
        int x = q.front().first % M;
        int t = q.front().second.first;
        int key = q.front().second.second;
        q.pop();

        if (map[y][x].first == '1') {
            cout << t << endl;
            return 0;
        }
        for (int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int k = 0;
            if (ny<0||ny>=N||nx<0||nx>=M||map[ny][nx].first=='#') continue;
            if (visited[ny][nx][key]) continue;
            if (map[ny][nx].first >= 'A' && map[ny][nx].first <= 'F' && (key & (1 << (map[ny][nx].first - 'A'))) == 0) continue;
            if (map[ny][nx].first >= 'a' && map[ny][nx].first <= 'f') k = 1 << (map[ny][nx].first - 'a');
            visited[ny][nx][key] = true;
            map[ny][nx].second = key|k;
            q.push({ny*M+nx,{t+1, key|k}});
        }
    }
    cout << -1 << endl;
    return 0;
}