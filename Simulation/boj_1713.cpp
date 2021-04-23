#include <iostream>
//후보 추천하기
using namespace std;

int N, M, curN, recommend[101], voteOrder[1000];
int main() {
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i=1; i<=M; ++i) {
        int vote;
        scanf("%d", &vote);
        //있던거에 더할 때
        if (recommend[vote]) recommend[vote]++;
        //비어있어서 새로 넣을때
        else if (curN < N) {
            recommend[vote]++;
            voteOrder[vote] = i;
            curN++;
        }
        else {
            //교체 해야될 때
            int min_recommend = 9999999;
            int min_idx = 9999;
            for (int j=1; j<=100; ++j) {
                if (recommend[j] && min_recommend > recommend[j]) {
                    min_recommend = recommend[j];
                    min_idx = j;
                }
            }

            for (int j=1; j<=100; ++j) {
                if (recommend[j] == min_recommend && voteOrder[j] < voteOrder[min_idx]) {
                    min_idx = j;
                }
            }
            recommend[min_idx] = 0;
            voteOrder[min_idx] = 0;
            recommend[vote]++;
            voteOrder[vote] = i;
        }
    }

    for (int i=1; i<101; ++i) {
        if (voteOrder[i]) printf("%d ", i);
    }

    return 0;
}