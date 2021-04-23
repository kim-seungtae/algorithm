#include <cstdio>
#include <string>
#include <set>
//카드 놓기
using namespace std;

int n, k;
int num[10];
set<string> st;
int visit[10];

void dfs(string s, int cur) {
    if (cur == k) {
        st.insert(s);
        return;
    }
    for (int i=0; i<n; ++i) {
        if (visit[i]) continue;
        visit[i] = true;
        string tmp = s + to_string(num[i]);
        dfs(tmp, cur+1);
        visit[i] = false;
    }
}
int main() {
    scanf("%d", &n);
    scanf("%d", &k);
    for (int i=0; i<n; ++i) scanf("%d", num+i);

    for (int i=0; i<n; ++i) {
        visit[i] = true;
        dfs(to_string(num[i]), 1);
        visit[i] = false;
    }
    printf("%lu", st.size());
    return 0;
}