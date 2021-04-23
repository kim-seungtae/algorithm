#include <iostream>
#include <vector>
#include <algorithm>
//두 배열의 합 1. 각 배열의 누적합 구해서 부배열의합 모두 찾기
//            2. 부분합 구해서 aa + bb = T니까 bb에서 T-aa인 부분합 갯수 찾기
typedef long long ll;
using namespace std;
int T, n, m;
ll ans;
int A[1000], Asum[1001], B[1000], Bsum[1001];
int main() {
    scanf("%d", &T);
    
    //입력&누적합
    scanf("%d", &n);
    Asum[0] = 0;
    for (int i=0; i<n; ++i) {
        scanf("%d", &A[i]);
        Asum[i+1] = Asum[i] + A[i];
    } 
    scanf("%d", &m);
    Bsum[0] = 0;
    for (int i=0; i<m; ++i) {
        scanf("%d", &B[i]);
        Bsum[i+1] = Bsum[i] + B[i];
    }
    
    //부배열합
    vector<int> Asub;
    vector<int> Bsub;
    for (int i=0; i<=n; ++i) {
        for (int j=i+1; j<=n; ++j) {
            Asub.push_back(Asum[j] - Asum[i]);
        }
    }
    for (int i=0; i<=m; ++i) {
        for (int j=i+1; j<=m; ++j) {
            Bsub.push_back(Bsum[j] - Bsum[i]);
        }
    }

    //binarySearch
    int Alen = Asub.size(), Blen = Bsub.size();
    sort(Bsub.begin(), Bsub.end());
 
    for (int i=0; i<Alen; ++i) {
        int target = T - Asub[i];
        auto lb = lower_bound(Bsub.begin(), Bsub.end(), target);
        auto ub = upper_bound(Bsub.begin(), Bsub.end(), target);

        ans += (ub - lb);
    }
    printf("%lld", ans);
    
    //2-pointer로도 가능
    return 0;
}