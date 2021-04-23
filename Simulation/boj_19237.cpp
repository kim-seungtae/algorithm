#include <iostream>
#define MAX_N       20
#define MAX_M       400
using namespace std;

int dy[5] = {0,-1,1,0,0};
int dx[5] = {0,0,0,-1,1};
int map[MAX_N][MAX_N];
int tmpMap[MAX_N][MAX_N];
int smell[2][MAX_N][MAX_N]; //smell[0][i][j]: 상어 번호. smell[1][i][j]: 남은 시간
int priority[MAX_M+1][5][5]; // priority[i][j][1~4]: 상어i가 j를 보고 있을때 우선순위
bool isAlive[MAX_M+1];
int sharkPos[MAX_M+1]; //i번째 상어의 위치를 y*N+x로 저장
int sharkDir[MAX_M+1];
int numOfLivingShark;
int N, M, k;
void input() {
    cin >> N >> M >> k;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        cin >> map[i][j];
        if (map[i][j]) sharkPos[map[i][j]] = i*N+j;
    }
    for (int i=1; i<=M; ++i) {
        cin >> sharkDir[i];
    }
    for (int i=1; i<=M; ++i) {
        for (int j=1; j<=4; ++j) {
            for (int k=1; k<=4; ++k) {
                cin >> priority[i][j][k];
            }
        }
    }
    numOfLivingShark = M;
    for (int i=1; i<=M; ++i) isAlive[i] = true;
}
void addSmell() {
    for (int i=1; i<=M; ++i) {
        if (!isAlive[i]) continue;
        int y = sharkPos[i] / N;
        int x = sharkPos[i] % N;

        smell[0][y][x] = i;
        smell[1][y][x] = k;
    }
}
void deleteSmell() {
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        if (smell[1][i][j]) --smell[1][i][j];
    }
}
void move() {
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        tmpMap[i][j] = 0;
    }
    for (int i=1; i<=M; ++i) {
        if (!isAlive[i]) continue;
        bool isMoving = false;
        int y = sharkPos[i] / N;
        int x = sharkPos[i] % N;
        int d = sharkDir[i];
        for (int j=1; j<=4; ++j) {
            int ny = y + dy[priority[i][d][j]];
            int nx = x + dx[priority[i][d][j]];

            if (ny<0||ny>=N||nx<0||nx>=N||smell[1][ny][nx]) continue;
            if (tmpMap[ny][nx]) {
                isAlive[i] = false;
                --numOfLivingShark;
            }
            else {
                sharkPos[i] = ny*N+nx;
                sharkDir[i] = priority[i][d][j];
                tmpMap[ny][nx] = i;
            }
            isMoving = true;
            break;
        }
        if (isMoving) continue;
        for (int j=1; j<=4; ++j) {
            int ny = y + dy[priority[i][d][j]];
            int nx = x + dx[priority[i][d][j]];

            if (ny<0||ny>=N||nx<0||nx>=N||smell[0][ny][nx]!=i) continue;
            sharkPos[i] = ny*N+nx;
            sharkDir[i] = priority[i][d][j];
            tmpMap[ny][nx] = i;
            break;
        }
    }
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        map[i][j] = tmpMap[i][j];
    }
}
int main() {
    ios::sync_with_stdio(false);
    input();

    int t = 0;
    while (numOfLivingShark != 1 && t <= 1000) {
        addSmell();
        move();
        deleteSmell();
        ++t;
    }
    if (t > 1000) cout << -1 << endl;
    else cout << t << endl;
    return 0;
}