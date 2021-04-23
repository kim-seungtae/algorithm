#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
//단어 수학
using namespace std;


int main() { //a b c 각각 자리수 봐서 10, 1010 이렇게 값 주고 큰거에다가 9부터 할당
    int N, ans = 0, weight[26] = {0};
    string s;
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> s;
        int len = s.size();
        for (int j=0; j<len; j++) {
            weight[s[j]-'A'] += pow(10, len-j-1); 
        }
    }

    sort(weight, weight+26, greater<>());

    int num = 9;
    for (int i=0; i<10; ++i) {
        ans += weight[i] * num;
        --num;
    }
    printf("%d", ans);
    return 0;
}