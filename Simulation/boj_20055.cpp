#include <iostream>
#define MAX_N       100
using namespace std;

int N, K, numOfEndBlock, s, e;
int durability[MAX_N*2];
bool robot[MAX_N*2];

void input() {
    cin >> N >> K;
    for (int i=0; i<2*N; ++i) cin >> durability[i];

    for (int i=0; i<N; ++i) robot[i] = false;
    numOfEndBlock = 0;
    s = 0;
    e = N-1;
}

void addRobot() {
    if (durability[s]) {
        robot[s] = true;
        --durability[s];
        if (durability[s] == 0) ++numOfEndBlock;
    }
}
void deleteLastRobot() {
    if (robot[e]) robot[e] = false;
}
void moveBelt() {
    --s;
    --e;
    if (s < 0) s = 2*N - 1;
    if (e < 0) e = 2*N - 1;

    deleteLastRobot();
}
void moveRobot() {
    int i=e+1;
    while(i!=s) {
        --i;
        if (i<0) i = 2*N - 1;
        int before = i-1;
        if (before < 0) before = 2*N - 1;
        
        if (robot[before] && !robot[i] && durability[i]) {
            robot[i] = true;
            robot[before] = false;
            --durability[i];
            if (durability[i] == 0) ++numOfEndBlock;
        }
    }

    deleteLastRobot();
}

int main() {
    ios::sync_with_stdio(false);
    input();
    int ans = 0;
    while (true) {
        ++ans;
        moveBelt();
        if (numOfEndBlock >= K) break;
        moveRobot();
        if (numOfEndBlock >= K) break;
        addRobot();
        if (numOfEndBlock >= K) break;
    }
    cout << ans << endl;
    return 0;
}
