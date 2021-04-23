#include <iostream>
#include <vector>
#include <algorithm>
//가장 긴 증가하는 부분 수열2
using namespace std;


int main() {
    int N, num, idx=0;
    vector<int> LIS;
    scanf("%d", &N);
    scanf("%d", &num);
    LIS.push_back(num);
    for (int i=1; i<N; ++i) {
        scanf("%d", &num);
        if (LIS[idx] < num) {
            LIS.push_back(num);
            ++idx;
        }
        else {
            auto lb = lower_bound(LIS.begin(), LIS.end(), num);
            LIS[lb-LIS.begin()] = num;
        }
    }
    printf("%d", idx+1);
    return 0;
}