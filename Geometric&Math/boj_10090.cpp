#include <iostream>
//Counting Inversions 병합정렬하면 병합할때 작은수가 앞으로 가는데 앞으로 움직인 길이가 inversion개수
#define MAX_N 1000000

int nos[MAX_N], buf[MAX_N];
long long ans;

void merge(int from, int mid, int to) {
        //1번째    2번째     buf
    int i1 = from, i2 = mid, i = from;
    while (i1 < mid && i2 < to) {
        if (nos[i2] < nos[i1]) {
            buf[i++] = nos[i2++];
            ans += mid - i1;
        }
        else buf[i++] = nos[i1++];
    }
    while (i1 < mid) buf[i++] = nos[i1++];
    while (i2 < to) buf[i++] = nos[i2++];
    for (i=from; i<to; ++i) nos[i] = buf[i];
}
void mergeSort(int from, int to) {
    if (to - from <= 1) return;
    int mid = (from + to) / 2;

    mergeSort(from, mid);
    mergeSort(mid, to);
    merge(from, mid, to);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; ++i) scanf("%d", nos+i);
    mergeSort(0, N);
    // for (int i=0; i<N; ++i) printf("%d ", nos[i]);
    printf("%lld", ans);
    return 0;
}