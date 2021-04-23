#include <iostream>
#define MAX_N       499
#define OFFSET      2
using namespace std;
int dy[4] = {0,1,0,-1};
int dx[4] = {-1,0,1,0};
int spread[4][5][5] = {
    {
        {0,0,2,0,0},
        {0,10,7,1,0},
        {5,0,0,0,0},
        {0,10,7,1,0},
        {0,0,2,0,0}
    },
    {
        {0,0,0,0,0},
        {0,1,0,1,0},
        {2,7,0,7,2},
        {0,10,0,10,0},
        {0,0,5,0,0}
    },
    {
        {0,0,2,0,0},
        {0,1,7,10,0},
        {0,0,0,0,5},
        {0,1,7,10,0},
        {0,0,2,0,0}
    },
    {
        {0,0,5,0,0},
        {0,10,0,10,0},
        {2,7,0,7,2},
        {0,1,0,1,0},
        {0,0,0,0,0}
    }
};
int N, sand[MAX_N + OFFSET*2][MAX_N + OFFSET*2];
int sy, sx;
void input() {
    cin >> N;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        cin >> sand[i+OFFSET][j+OFFSET];
    }
    sy = N/2 + OFFSET, sx = N/2 + OFFSET;
}
void move(int dir) {
    sy = sy + dy[dir];
    sx = sx + dx[dir];

    int sumOfMovingSand = 0;
    for (int i=0; i<5; ++i) for (int j=0; j<5; ++j) {
        int tmp = sand[sy][sx] * spread[dir][i][j] / 100;
        sand[i+sy-OFFSET][j+sx-OFFSET] += tmp;
        sumOfMovingSand += tmp;
    }
    sand[sy+dy[dir]][sx+dx[dir]] += sand[sy][sx] - sumOfMovingSand;
    sand[sy][sx] = 0;
}
int sandOutside() {
    int ret = 0;
    for (int j=0; j<N+OFFSET*2; ++j) {
        for (int i=0; i<OFFSET; ++i) ret += sand[i][j];
        for (int i=N+OFFSET; i<N+OFFSET*2; ++i) ret += sand[i][j];
    }
    for (int i=OFFSET; i<N+OFFSET; ++i) {
        for (int j=0; j<OFFSET; ++j) ret += sand[i][j];
        for (int j=N+OFFSET; j<N+OFFSET*2; ++j) ret += sand[i][j];
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    input();

    int len = 0;
    int d = 0;
    while (len != N-1) {
        ++len;
        for (int i=0; i<len; ++i) move(d);
        d = (d+1)%4;
        for (int i=0; i<len; ++i) move(d);
        d = (d+1)%4;
    }
    for (int i=0; i<len; ++i) move(d);

    cout << sandOutside() << endl;

    return 0;
}