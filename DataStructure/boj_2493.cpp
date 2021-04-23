#include <iostream>
#include <stack>
using namespace std;
typedef pair<int, int> pii;
//탑
stack<pii> stk;

int main() {
    //높이 같으면 부딪힘
    int N;
    scanf("%d", &N);
    stk.push({100000001, 0});
    for (int i=1; i<=N; ++i) {
        int h;
        scanf("%d", &h);
        while (stk.top().first < h) stk.pop();
        printf("%d ", stk.top().second);
        stk.push({h, i});
    }
}
