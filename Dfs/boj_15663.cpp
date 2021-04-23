#include <iostream>
#include <vector>
#include <algorithm>
//N과 M (9)
using namespace std;
typedef pair<int, int> pii;

int num[10], ans[10];
//입력된 숫자, 몇번 등장했는지
vector<pii> nos;
int N, n, M;

void backtracking(int loc) {
    if (loc == M) {
        for (int i=0; i<M; ++i) printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    for (int i=0; i<nos.size(); ++i) {
        if (nos[i].second > 0) {
            ans[loc] = nos[i].first;
            --nos[i].second;
            backtracking(loc+1);
            ++nos[i].second;
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; ++i) {
        scanf("%d", &n);
        int j;
        for (j=0; j<nos.size(); ++j) {
            if (nos[j].first == n) {
                ++nos[j].second;
                break;
            }
        }
        if (j == nos.size()) nos.push_back({n, 1});
    }

    sort(nos.begin(), nos.end());

    backtracking(0);

    return 0;
}

// void backtracking(const int& loc) {
//     int i;
//     if (loc == M) {
//         printf("%d", ans[0]);
//         for (i=1; i<M; ++i) printf(" %d", ans[i]);
//         printf("\n");
//         return;
//     }

//     for (i=0; i<nos.size(); ++i) {
//         if (nos[i].second > 0) {
//             ans[loc] = nos[i].first;
//             --nos[i].second;
//             backtracking(loc+1);
//             ++nos[i].second;
//         }
//     }
// }
// int main() {
//     scanf("%d %d", &N, &M);
//     for (int i=0; i<N; ++i) {
//         scanf("%d", &n);
//         int j;
//         for (j=0; j<nos.size(); ++j) {
//             if (nos[j].first == n) {
//                 ++nos[j].second;
//                 break;
//             }
//         }
//         if (j == nos.size()) nos.push_back({n, 1});
//     }

//     sort(nos.begin(), nos.end());

//     backtracking(0);
    
//     return 0;
// }

