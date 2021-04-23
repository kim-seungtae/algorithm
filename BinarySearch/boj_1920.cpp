#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//수 찾기
int A[100000], B[100000];

void binarySearch(int t, int left, int right) {
    if (left > right) {
        return;
    }
    int mid = (left + right) / 2;
    if (A[mid] > t) {
        binarySearch(t, left, mid-1);
    }
    else if (A[mid] < t) {
        binarySearch(t, mid+1, right);
    }
    else if (A[mid] == t) {
        ret = 1;
        return;
    }
}

int main() {
    int N,M;
    scanf("%d", &N);
    for (int i=0; i<N; ++i) scanf("%d", &A[i]);
    scanf("%d", &M);
    for (int i=0; i<M; ++i) scanf("%d", &B[i]);
    sort(A, A+N);

    for (int i=0; i<M; ++i) {
        ret = 0;
        binarySearch(B[i], 0, N-1);
        printf("%d\n", ret);
    }
}