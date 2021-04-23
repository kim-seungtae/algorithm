#include <iostream>
#include <algorithm>
#define pii pair<int, int>
using namespace std;

int map[10][10];
int T, N, numOfP, numOfS, ans;
pii stairs[2];
int K[2];
pii person[10];
int dist[2][10];
int selectStairs[10];
int max(int a, int b) {return a>b?a:b;}
int min(int a, int b) {return a<b?a:b;}
int abs(int a) {return a>0?a:-a;}
void Input() {
    cin >> N;
    int tmp;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        cin >> tmp;
        map[i][j] = tmp;
        if (tmp == 1) {
            person[numOfP].first = i;
            person[numOfP++].second = j;
        }
        if (tmp > 1) {
            K[numOfS] = tmp;
            stairs[numOfS].first = i;
            stairs[numOfS++].second = j;
        }
    }
}
void Init() {
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        map[i][j] = 0;
    }
    ans = 99999;
    numOfP = 0;
    numOfS = 0;
}
int calcManD(pii a, pii b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int calcMinTime() {
    int firstStairIdx = 0, secondStairIdx = 0;
    int firstStairTime[10] = {0, }, secondStairTime[10] = {0, };
    for (int i=0; i<numOfP; ++i) {
        if (selectStairs[i] == 0)
            dist[0][firstStairIdx++] = calcManD(stairs[0], person[i]);
        else
            dist[1][secondStairIdx++] = calcManD(stairs[1], person[i]);
    }
    sort(dist[0], dist[0] + firstStairIdx);
    sort(dist[1], dist[1] + secondStairIdx);
    
    for (int i=0; i<firstStairIdx; ++i) {
        if (i < 3) firstStairTime[i] = dist[0][i] + 1 + K[0];
        else {
            if (firstStairTime[i-3] >= dist[0][i] + 1) firstStairTime[i] = firstStairTime[i-3] + K[0];
            else firstStairTime[i] = dist[0][i] + 1 + K[0];
        }
    }

    for (int i=0; i<secondStairIdx; ++i) {
        if (i < 3) secondStairTime[i] = dist[1][i] + 1 + K[1];
        else {
            if (secondStairTime[i-3] >= dist[1][i] + 1) secondStairTime[i] = secondStairTime[i-3] + K[1];
            else secondStairTime[i] = dist[1][i] + 1 + K[1];
        }
    }

    return max(firstStairTime[firstStairIdx-1], secondStairTime[secondStairIdx-1]);
}
void Dfs(int idx) {
    if (idx == numOfP) {
        ans = min(ans, calcMinTime());
        return;
    }

    for (int i=0; i<2; ++i) {
        selectStairs[idx] = i;
        Dfs(idx+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t=1; t<=T; ++t) {
        Init();
        Input();
        Dfs(0);
        cout << "#" << t << " " << ans << endl;
    }

    return 0;
}