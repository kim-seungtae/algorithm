#include <iostream>
using namespace std;

int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int fishNum[4][4];
int fishPos[17];
int fishDir[4][4];
int ans;
int max(int a, int b) {return a>b?a:b;}
void moveFish() {
    for (int i=1; i<=16; ++i) {
        if (fishPos[i] == -1) {
            continue;
        }
        int y = fishPos[i] / 4;
        int x = fishPos[i] % 4;
        int d = fishDir[y][x];
        for (int j=0; j<8; ++j) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny<0||ny>=4||nx<0||nx>=4||fishNum[ny][nx] == 99) {
                d = (d+1)%8;
                continue;
            }
            // fishPos update swap
            // fishNum, d update
            if (fishNum[ny][nx] == -1) {
                fishNum[ny][nx] = fishNum[y][x];
                fishNum[y][x] = -1;
                fishDir[ny][nx] = d;
                fishPos[fishNum[ny][nx]] = ny*4+nx;
                break;
            }
            else if (fishNum[ny][nx] >= 1) {
                fishPos[fishNum[ny][nx]] = y*4+x;
                fishPos[fishNum[y][x]] = ny*4+nx;

                int tmp = fishNum[ny][nx];
                fishNum[ny][nx] = fishNum[y][x];
                fishNum[y][x] = tmp;

                fishDir[y][x] = fishDir[ny][nx];
                fishDir[ny][nx] = d;
                break;
            }
        }
    }
}
void dfs(int sy, int sx, int sd, int score) {
    int tmpNum[4][4], tmpDir[4][4], tmpPos[17];
    for (int i=0; i<4; ++i) for (int j=0; j<4; ++j) {
        tmpNum[i][j] = fishNum[i][j];
        tmpDir[i][j] = fishDir[i][j];
    }
    for (int i=1; i<17; ++i) tmpPos[i] = fishPos[i];
    moveFish();
    int moveCount = 0;
    for (int i=1; i<=3; ++i) {
        int ny = sy + dy[sd] * i;
        int nx = sx + dx[sd] * i;

        if (ny>=0&&ny<4&&nx>=0&&nx<4&&fishNum[ny][nx]>=1) {
            int tmp = fishNum[ny][nx];
            fishNum[ny][nx] = 99;
            fishPos[tmp] = -1;
            fishNum[sy][sx] = -1;
            dfs(ny, nx, fishDir[ny][nx], score + tmp);
            fishNum[ny][nx] = tmp;
            fishPos[tmp] = ny*4+nx;
            fishNum[sy][sx] = 99;
            ++moveCount;
        }
    }
    for (int i=0; i<4; ++i) for (int j=0; j<4; ++j) {
        fishNum[i][j] = tmpNum[i][j];
        fishDir[i][j] = tmpDir[i][j];
    }
    for (int i=1; i<17; ++i) fishPos[i] = tmpPos[i];

    if (moveCount == 0) {
        ans = max(ans, score);
        return;
    }
}
int main() {
    ios::sync_with_stdio(false);
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            cin >> fishNum[i][j] >> fishDir[i][j];
            fishPos[fishNum[i][j]] = i*4+j;
        }
    }
    for (int i=0; i<4; ++i) for (int j=0; j<4; ++j) fishDir[i][j] -= 1;
    ans = fishNum[0][0];
    fishPos[fishNum[0][0]] = -1;
    fishNum[0][0] = 99;
    dfs(0, 0, fishDir[0][0], ans);
    cout << ans << endl;
    return 0;
}