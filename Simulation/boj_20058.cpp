#include <iostream>
#include <stack>
#define MAX_N       6
#define MAX_L       64
#define MAX_K       1000
using namespace std;

typedef pair<int, int> pii;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int max(int a, int b) {return a>b?a:b;}
int N, Q, L[MAX_K];
int ice[MAX_L][MAX_L], tmp[MAX_L][MAX_L];
bool visited[MAX_L][MAX_L] = {false, };
bool isIce[MAX_L][MAX_L];

void input() {
    cin >> N >> Q;
    for (int i=0; i<(1<<N); ++i) for (int j=0; j<(1<<N); ++j) {
        cin >> ice[i][j];
    }
    for (int i=0; i<Q; ++i) cin >> L[i];
}
void rotate(int pos, int len) {
    int y = pos / (1<<N);
    int x = pos % (1<<N);
    for (int i=y; i<y+len; ++i) for (int j=x; j<x+len; ++j) {
        tmp[i][j] = ice[i][j];
    }
    for (int i=0; i<len; ++i) {
        for (int j=0; j<len; ++j) {
            ice[j+y][len-i-1+x] = tmp[i+y][j+x];
        }
    }
}
void minusIce() {
    for (int i=0; i<(1<<N); ++i) for (int j=0; j<(1<<N); ++j) {
        isIce[i][j] = false;
        if (ice[i][j]) isIce[i][j] = true;
    }

    for (int i=0; i<(1<<N); ++i) for (int j=0; j<(1<<N); ++j) {
        if (!isIce[i][j]) continue;
        int num = 0;
        for (int k=0; k<4; ++k) {
            int ny = i + dy[k];
            int nx = j + dx[k];

            if (ny<0||ny>=(1<<N)||nx<0||nx>=(1<<N)||!isIce[ny][nx]) continue;
            ++num;
        }
        if (num < 3) --ice[i][j];
    }
}
int findSizeOfLargestIce() {
    int M = 0;
    for (int i=0; i<(1<<N); ++i) for (int j=0; j<(1<<N); ++j) {
        if (ice[i][j] == 0 || visited[i][j]) continue;
        stack<pii> s;
        s.push({i, j});
        visited[i][j] = true;
        int tmp = 0;
        while (!s.empty()) {
            int y = s.top().first;
            int x = s.top().second;
            s.pop();
            ++tmp;

            for (int i=0; i<4; ++i) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny<0||nx<0||ny>=(1<<N)||nx>=(1<<N)||ice[ny][nx]==0||visited[ny][nx]) continue;
                s.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
        M = max(tmp, M);
    }
    return M;
}
int getTotalNumOfIce() {
    int sum = 0;
    for (int i=0; i<(1<<N); ++i) for (int j=0; j<(1<<N); ++j) {
        sum += ice[i][j];
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    input();
    for (int i=0; i<Q; ++i) {
        for (int j=0; j<(1<<N); j+=(1<<L[i])) {
            for (int k=0; k<(1<<N); k+=(1<<L[i])) {
                rotate(j*(1<<N)+k, (1<<L[i]));
            }
        }
        minusIce();
    }
    cout << getTotalNumOfIce() << "\n" << findSizeOfLargestIce() << endl;
    return 0;
}