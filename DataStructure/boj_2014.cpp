#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
//소수의 곱
using namespace std;
typedef long long ll;

priority_queue<ll> pq;
vector<int> primes;
vector<int> ans;
int main() {
    int K, N, h;
    scanf("%d %d", &K, &N);
    for (int i=0; i<K; ++i) {
        scanf("%d", &h);
        primes.push_back(h);
    }
    pq.push(-1);
    while (1) { //현재 가장 작은 값이 pq.top이니까 거기에다가 주어진 소수를 계속 곱해서 pq에 넣는다.
        ll cur = pq.top();
        if (ans.size() >= N) break;
        while (!pq.empty() && pq.top() == cur) pq.pop();
        for (int i=0; i<primes.size(); ++i) {
            pq.push(cur * primes[i]);
            if (cur % primes[i] == 0) break; //이게 있어야 메모리 초과가 안남
        }
        ans.push_back((int)pq.top());
    }
    printf("%d", -ans[N-1]);
    return 0;
}