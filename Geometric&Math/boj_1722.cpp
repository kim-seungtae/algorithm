#include <cstdio>
#include <vector>
//순열의 순서
using namespace std;

typedef long long ll;

int N, T, ans[21];
int num[21];
ll fact[21];
bool visit[21];

//K번째 수를 찾을거면
//1로 시작하는게 몇개인지 센다. (fact[N-1])
//2로 시작하는게 몇개인지 센다. (fact[N-1])
//... 마지막으로 시작하는게 ... 이거를 다 K에서 빼.
// K에서 빼는데 음수가 되면. 답은 거기에 있는거네
void findKth(ll k) {
    for (int i=0; i<N; ++i) {
        for (int j=1; j<=N; ++j) {
            if (visit[j]) continue;
            if (fact[N-i-1] < k) {
                k -= fact[N-i-1];
            }
            else {
                visit[j] = true;
                printf("%d ", j);
                break;
            }
        }
    }
}

//입력 배열을 돌면서 입력된 값(ans[i])보다 작은 수들(1~ans[i]-1)로 시작하는 수열의 개수 더하기
//1로 시작하는거 ans[i]-1!개, 2로 시작하는거 N\ans[i]-1!개 ...
//그리고 ans[i]는 첫번쨰 숫자로 썼으니까 방문처리.
//그 다음도 똑같이 
//마지막 자리수는 안들어가니까 + 1
ll searchOrder() {
    ll k = 0;
    for (int i=0; i<N; i++) {
        for (int j=1; j<ans[i]; ++j) {
            if (!visit[j]) k += fact[N-i-1];
        }
        visit[ans[i]] = true;
    }
    return k + 1;
}

int main() {
    scanf("%d", &N);
    scanf("%d", &T);

    fact[0] = fact[1] = 1;
    for (int i=2; i<20; ++i) fact[i] = fact[i-1]*i;

    if (T == 1) {
        ll k;
        scanf("%lld", &k);
        findKth(k);
    }
    else {
        for (int i=0; i<N; ++i) scanf("%d", ans+i);
        printf("%lld", searchOrder());
    }
    return 0;
}