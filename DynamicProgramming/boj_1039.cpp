#include <cstdio>
#include <cstring>
//교환
using namespace std;

#define MAX_L   7
#define MAX_K   10
int multi[MAX_L], nums[MAX_L];
int visited[MAX_K][1000001];
int N, K, L, ans = -1;

int max(int a, int b) {return a>b?a:b;}
int dfs(int n, int k) {
    if (k == K) {
        if (n > ans) ans = n;
        return n;
    }
    if (L < 2) return -1;
    if (visited[k][n] != -1) return visited[k][n];
    int i=L-1, ret=-1;
    for (int j=i-1; j>=0; --j) {
        if (nums[j] != 0) {
            int buf = nums[i];
            nums[i] = nums[j];
            nums[j] = buf;
            ret = max(ret, dfs(n + (nums[i] - nums[j])*multi[i] + (nums[j] - nums[i]) * multi[j], k+1));
            buf = nums[i];
            nums[i] = nums[j];
            nums[j] = buf;
        }
    }

    for (i=L-2; i>0; --i) {
        for (int j=i-1; j>=0; --j) {
            int buf = nums[i];
            nums[i] = nums[j];
            nums[j] = buf;
            ret = max(ret, dfs(n + (nums[i] - nums[j])*multi[i] + (nums[j] - nums[i]) * multi[j], k+1));
            buf = nums[i];
            nums[i] = nums[j];
            nums[j] = buf;
        }
    }
    visited[k][n] = ret;
    return ret;
}
int main() {
    scanf("%d %d", &N, &K);
    int tmp=N, i=0, j=1;
    for (tmp; tmp>0; tmp/=10, ++i, j*=10) {
        ++L;
        nums[i] = tmp % 10;
        multi[i] = j;
    }
    memset(visited, -1, sizeof(visited));
    dfs(N, 0);
    printf("%d\n", ans);
    return 0;
}