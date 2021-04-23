#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
//보석도둑
using namespace std;
typedef pair<int,int> pii;

pii jems[300000];
int bags[300000];
priority_queue<int> pq;

int main() {
    int N, K, i, j;
    long long ans = 0;
    scanf("%d %d", &N, &K);

    for (i=0; i<N; ++i) scanf("%d %d", &jems[i].first, &jems[i].second);
    for (i=0; i<K; ++i) scanf("%d", bags+i);
    //가방, 보석 정렬
    sort(jems, jems+N);
    sort(bags, bags+K);

    j=0;
    for (i=0; i<K; ++i) {
        while (j < N && jems[j].first <= bags[i]) pq.push(jems[j++].second);
        if (!pq.empty()) ans += pq.top(), pq.pop();
    }
    printf("%lld\n", ans);
    return 0;
}