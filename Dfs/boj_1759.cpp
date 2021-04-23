#include <iostream>
#include <algorithm>
//암호만들기
using namespace std;
int tp[26] = {1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0};
int L, C;
char ans[16], chs[16];

void dfs(int idx, int cnt, int cnt1, int cnt2) {
    if (cnt == L) {
        if (cnt1 > 0 && cnt2 > 1) printf("%s\n", ans);
        return;
    }
    if (idx == C) return;
    for (int i=idx; i<C; i++) {
        ans[cnt] = chs[i];
        if (tp[chs[i] - 'a']) dfs(i+1, cnt+1, cnt1+1, cnt2);
        else dfs(i+1, cnt+1, cnt1, cnt2+1);
    }

}

int main() {
    scanf("%d %d", &L, &C);
    for (int i=0; i<C; ++i) {
        scanf(" %c", &chs[i]);
    }
    sort(chs, chs+C);
    dfs(0,0,0,0);
    return 0;
}