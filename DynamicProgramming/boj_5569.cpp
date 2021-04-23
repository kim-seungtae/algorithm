#include <cstdio>
//출근 경로 한 점까지 경로의 수를 밑에서 온거, 왼쪽에서 온거 2개로 저장한다.
//(h, w)에서: (h, w+1)에다가는 왼쪽에서 온거만, (h, w+2)에다가는 밑에서 온거만 더한다.
//(h, w+2)에 왼쪽에서 온걸 안더하는 이유는 다음 점 (h, w+1)에서 왼쪽에서 온걸 더해주기 떄문에
//(h, w)에서: (h+1, w)에다가는 밑에서 온거만, (h+2, w)에다가는 왼쪽에서 온거만 더한다.

using namespace std;

#define MAX_H       100
#define MOD         100000
//0:-> 1:up
int D[2][MAX_H+1][MAX_H+1];

int main() {
    int W, H;
    int w, h;
    scanf("%d %d", &W, &H);
    
    D[0][0][1] = D[1][1][0] = 1;

    for (h=0; h<H; ++h) {
        for (w=0; w<W; ++w) {
            if (w < W - 1) {
                D[0][h][w+1] = (D[0][h][w+1] + D[0][h][w]) % MOD;
                D[0][h][w+2] = (D[0][h][w+2] + D[1][h][w]) % MOD;
            }
            if (h < H - 1) {
                D[1][h+2][w] = (D[1][h+2][w] + D[0][h][w]) % MOD;
                D[1][h+1][w] = (D[1][h+1][w] + D[1][h][w]) % MOD;
            }
        }
    }

    int ans = 0;
    ans = D[0][H-1][W-1];
    ans = (ans + D[1][H-1][W-1]) % MOD;
    ans = (ans + D[0][H-1][W]) % MOD;
    ans = (ans + D[1][H][W-1]) % MOD;
    printf("%d\n", ans);
    return 0;
}