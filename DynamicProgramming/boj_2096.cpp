#include <iostream>
#include <algorithm>
//내려가기
using namespace std;
int map[100000][3];
int dpMax[3], dpMin[3];
int main() {
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; ++i) {
        for (int j=0; j<3; ++j) {
            scanf("%d", &map[i][j]);
        }
    }
    dpMax[0] = map[0][0]; dpMax[1] = map[0][1]; dpMax[2] = map[0][2];
    dpMin[0] = map[0][0]; dpMin[1] = map[0][1]; dpMin[2] = map[0][2];
    for (int i=1; i<N; ++i) {
        int tmp1 = dpMax[0], tmp2 = dpMax[1], tmp3 = dpMax[2], tmp4 = dpMin[0], tmp5 = dpMin[1], tmp6 = dpMin[2];
        dpMax[0] = max(tmp1, tmp2) + map[i][0];
        dpMax[1] = max(max(tmp1, tmp2), tmp3) + map[i][1];
        dpMax[2] = max(tmp2, tmp3) + map[i][2];
        dpMin[0] = min(tmp4, tmp5) + map[i][0];
        dpMin[1] = min(min(tmp4, tmp5), tmp6) + map[i][1];
        dpMin[2] = min(tmp5, tmp6) + map[i][2];
    }
    printf("%d %d", max(max(dpMax[0], dpMax[1]), dpMax[2]), min(min(dpMin[0], dpMin[1]), dpMin[2]));
    return 0;
}