#include <iostream>
//N-queens
int col[15]; //각 열에서 몇번째 idx에 퀸이 있는지 저장
int N, ans;
bool check(int level) { //현재 몇 번째 열까지 왔는지
    for (int i=0; i<level; ++i) {
        if (col[i] == col[level] || i-col[i] == level-col[level] || i+col[i] == level+col[level]) return true;
    }
    return false;
}
void backtracking(int y) {
    if (y == N) {
        ans++;
        return;
    }
    for (int i=0; i<N; i++) {
        col[y] = i;
        if (!check(y)) backtracking(y+1);
    }
}

int main() {
    scanf("%d", &N);
    backtracking(0);
    printf("%d", ans);
    return 0;
}