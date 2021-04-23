#include <iostream>
#include <queue>
#define MAX_N       50
#define INF         999999
using namespace std;
typedef pair<int, int> pii;
int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
int N;
pii B, E; // status(vertical:0, horizental:1), y*M+x 
char map[MAX_N][MAX_N];
bool visited[2][MAX_N*MAX_N]; //status, y*M+x

bool isMovable(int y, int x, int s) {
    if (s == 0) {
        if (x<0||x>=N) return false;
        if (y-1<0||y+1>=N) return false;
        for (int i=y-1; i<y+2; ++i) {
            if (map[i][x] != '0') return false;
        }
        return true;
    }
    else {
        if (y<0||y>=N) return false;
        if (x-1<0||x+1>=N) return false;
        for (int j=x-1; j<x+2; ++j) {
            if (map[y][j] != '0') return false;
        }
        return true;
    }
}
bool isRotatable(int y, int x) {
    for (int i=y-1; i<y+2; ++i) for (int j=x-1; j<x+2; ++j) {
        if (i<0||i>=N||j<0||j>=N||map[i][j]!='0') return false;
    }
    return true;
}
int bfs() {
    queue<pair<pii, int>> q;
    q.push({B, 0}); //{{status, center pos}, t}
    visited[B.first][B.second] = true;
    int t;
    while (!q.empty()) {
        int s = q.front().first.first;
        int y = q.front().first.second / N;
        int x = q.front().first.second % N;
        t = q.front().second;
        q.pop();
        if (s == E.first && y*N+x == E.second) return t;
        for (int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (!isMovable(ny, nx, s) || visited[s][ny*N+nx]) continue;
            q.push({{s, ny*N+nx}, t+1});
            visited[s][ny*N+nx] = true;
        }
        if (visited[(s+1)%2][y*N+x]) continue;
        if (isRotatable(y, x)) {
            q.push({{(s+1)%2, y*N+x}, t+1});
            visited[(s+1)%2][y*N+x] = true;
        }
    }
    return 0;
}
int main() {
    cin >> N;
    char input[MAX_N+1];
    for (int i=0; i<N; ++i) {
        cin >> input;
        for (int j=0; j<N; ++j) {
            map[i][j] = input[j];
            if (map[i][j] == 'B') B.second = i*N+j;
            if (map[i][j] == 'E') E.second = i*N+j;
        }
    }

    int y = B.second / N, x = B.second % N;
    map[y][x] = '0';
    if (map[y-1][x] == 'B') {
        B.first = 0;
        B.second = (y-1) * N + x;
        map[y-1][x] = '0';
        map[y-2][x] = '0';
    }
    else {
        B.first = 1;
        B.second = y*N + (x-1);
        map[y][x-1] = '0';
        map[y][x-2] = '0';
    }

    y = E.second / N, x = E.second % N;
    map[y][x] = '0';
    if (map[y-1][x] == 'E') {
        E.first = 0;
        E.second = (y-1) * N + x;
        map[y-1][x] = '0';
        map[y-2][x] = '0';
    }
    else {
        E.first = 1;
        E.second = y*N + (x-1);
        map[y][x-1] = '0';
        map[y][x-2] = '0';
    }
    cout << bfs() << endl;
    return 0;
}