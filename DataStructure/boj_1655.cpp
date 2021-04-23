#include <iostream>
#include <queue>
#include <vector>
//가운데를 말해요 maxheap에 반절, minheap에 반절 넣기
using namespace std;

priority_queue<int> maxheap;
priority_queue<int,vector<int>, greater<int>> minheap;
vector<int> ans;

int main() {
    int N, h;
    scanf("%d", &N);
    scanf("%d", &h);
    maxheap.push(h);
    ans.push_back(h);

    for (int i=1; i<N; ++i) {
        scanf("%d", &h);
        if (maxheap.size() > minheap.size()) {
            minheap.push(h);
        }
        else maxheap.push(h);
        
        if (maxheap.top() > minheap.top()) {
            int Min = maxheap.top();
            int Max = minheap.top();
            maxheap.pop();
            maxheap.push(Max);
            minheap.pop();
            minheap.push(Min);
        }
        ans.push_back(maxheap.top());
    }
    for (int i:ans) printf("%d\n", i);
    return 0;
}
