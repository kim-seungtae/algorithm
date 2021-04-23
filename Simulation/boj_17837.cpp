#include <iostream>
#include <vector>
#include <deque>
#define MAX_N       12
#define MAX_K       10
using namespace std;
typedef pair<int, int> pii;
int N, K;
int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
int color[MAX_N][MAX_N];
pii piece[MAX_K];
deque<int> map[MAX_N][MAX_N];

void input() {
    cin >> N >> K;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        cin >> color[i][j];
    }
    int y, x, d;
    for (int i=0; i<K; ++i) {
        cin >> y >> x >> d;
        piece[i].first = (y-1)*N+(x-1);
        piece[i].second = d - 1;
        map[y-1][x-1].push_back(i);
    }
}
void mov(int idx) {
    int y = piece[idx].first / N;
    int x = piece[idx].first % N;
    int& d = piece[idx].second;

    int ny = y + dy[d];
    int nx = x + dx[d];

    if (ny < 0 || ny >= N || nx < 0 || nx >= N || color[ny][nx] == 2) {
        if (d == 0) d = 1;
        else if (d == 1) d = 0;
        else if (d == 2) d = 3;
        else if (d == 3) d = 2;

        ny = y + dy[d];
        nx = x + dx[d];
        if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
            if (color[ny][nx] == 2) return;
            mov(idx);
        }
        else return;
    }
    else {
        deque<int> dq;
        int tmp;
        while (true) {
            tmp = map[y][x].back();
            dq.push_back(tmp);
            map[y][x].pop_back();
            if (tmp == idx) break;
        }
        if (color[ny][nx] == 0) {
            while (!dq.empty()) {
                map[ny][nx].push_back(dq.back());
                piece[dq.back()].first = ny*N+nx;
                dq.pop_back();
            }
        }
        else {
            while (!dq.empty()) {
                map[ny][nx].push_back(dq.front());
                piece[dq.front()].first = ny*N+nx;
                dq.pop_front();
            }
        }
    }
}
bool check(int idx) {
    int y = piece[idx].first / N;
    int x = piece[idx].first % N;
    if (map[y][x].size() >= 4) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    input();
    for (int t=1; t<=1000; ++t) {
        for (int i=0; i<K; ++i) {
            mov(i);
            if (check(i)) {
                cout << t << endl;
                return 0;
            }
        }
        
    }
    cout << -1 << endl;
    return 0;
}