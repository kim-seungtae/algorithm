#include <cstdio>
//산책 한 점에서 무조건 아래, 오른쪽으로 반절씩 간다. 짝수일 때는 반반
//홀수일 때는 원래 방향에 한번 더. 홀수일 때 방향전환까지 하기.
//N-1번 산책했을때 cnt를 만들고 마지막N일때는 직접 탐색

#define MAX_H       1000
#define MAX_W       1000

int map[MAX_H][MAX_W];
int cnt[MAX_H+1][MAX_W+1];

int main() {
    int H, W, N, h, w;
    scanf("%d %d %d", &H, &W, &N);
    for (h=0; h<H; ++h) {
        for (w=0; w<W; ++w) {
            scanf("%d", &map[h][w]);
        }
    }
    cnt[0][0] = --N;
    for (h=0; h<H; ++h) {
        for (w=0; w<W; ++w) {
            cnt[h+1][w] += cnt[h][w] / 2;
            cnt[h][w+1] += cnt[h][w] / 2;
            if (cnt[h][w] & 1) {
                if (map[h][w]) ++cnt[h][w+1];
                else ++cnt[h+1][w];
                map[h][w] ^= 1;
            }
        }
    }

    h = w = 0;
    while (h < H && w < W) {
        if (map[h][w]) ++w;
        else ++h;
    }
    //0부터 했으니까 +1
    printf("%d %d", ++h, ++w);
    
    // for (h=0; h<H; ++h) {
    //     for (w=0; w<W; ++w) {
    //         if (h+1 < H) {
    //             cnt[h+1][w] += cnt[h][w] / 2;
    //             if (cnt[h][w] % 2 == 1 && map[h][w] == 0) ++cnt[h+1][w];
    //         }
    //         if (w + 1 < W) {
    //             cnt[h][w+1] += cnt[h][w] / 2;
    //             if (cnt[h][w] % 2 == 1 && map[h][w] == 1) ++cnt[h][w+1];
    //         }
    //     }
    // }
    // h = w = 0;
    // while (h < H && w < W) {
    //     if (cnt[h][w] % 2 == 1) map[h][w] ^= 1; //1은 0으로 0은 1으로
    //     if (map[h][w] == 1) ++w;
    //     else ++h;
    // }
    // printf("%d %d", ++h, ++w);
    return 0;
}