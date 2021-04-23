#include <iostream>
#include <stack>
using namespace std;

int visit[500001], p[500001], c[500001];
int N, ans;
//나를 찍은 사람이 없으면 마피아 가능
void dfs(int idx, bool flag) {
    if(visit[idx]) return;
    visit[idx] = 1;  //방문확인
    ans += flag;

    int next = p[idx];
    c[next] -= 1;
    if (c[next] == 0 || flag) dfs(next, !flag);

}

int main() {
    scanf("%d", &N);
    
    for (int i=1; i<=N; i++) {
        int tmp;
        scanf("%d", &tmp);
        p[i] = tmp;
        c[tmp]++;
    }

    for (int i=1; i<=N; i++) {
        if (c[i] == 0) dfs(i, true);
    }

    for (int i=1; i<=N; i++) {
        dfs(i, false);
    }

    cout << ans;
}

