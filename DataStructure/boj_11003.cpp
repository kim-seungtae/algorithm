#include <iostream>
#include <stack>
//최소값 찾기 //deque에 {값, 인덱스}로 넣어서 i-L보다 작으면 범위 벗어난거. 값이 지금 넣는거보다 크면 필요없는거
using namespace std;
typedef pair<int, int> pii;

deque<pii> dq;
int main() {
    int N, L, n;
    scanf("%d %d", &N, &L);\
    scanf("%d", &n);
    dq.push_back({n, 0});
    printf("%d ", dq.front().first);
    for (int i=1; i<N; ++i) {
        scanf("%d", &n);
        if (!dq.empty() && dq.front().second <= i-L) dq.pop_front();
        while (!dq.empty() && dq.back().first >= n) dq.pop_back();
        dq.push_back({n, i});
        printf("%d ", dq.front().first);
    }
}