#include <iostream>
#define SIZE_M       101
using namespace std;

int dy[4] = {0,-1,0,1}, dx[4] = {1,0,-1,0};
int N;
bool map[SIZE_M][SIZE_M];
int DC[1024], idx;

int make_next_generation(int pos) {
    int y = pos / SIZE_M, x = pos % SIZE_M;
    for (int i=idx-1; i>=0; --i) {
        DC[idx] = (DC[i]+1)%4;
        y += dy[DC[idx]], x += dx[DC[idx]];
        ++idx;
        map[y][x] = true;
    }
    return y*SIZE_M + x;
}

int getAnswer() {
    int ans = 0;
    for (int i=0; i<SIZE_M-1; ++i) for (int j=0; j<SIZE_M-1; ++j) {
        if (map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1]) ++ans;
    }
    return ans;
}

int main() {
    cin >> N;
    int x, y, d, g;
    for (int n=0; n<N; ++n) {
        cin >> x >> y >> d >> g;
        idx = 0;
        DC[idx] = d;
        map[y][x] = true;
        y += dy[DC[idx]], x += dx[DC[idx++]];
        map[y][x] = true;
        int lastPos = y*SIZE_M + x;
        for (int i=0; i<g; ++i) {
            lastPos = make_next_generation(lastPos);
        }
    }
    cout << getAnswer() << endl;
    return 0;
}