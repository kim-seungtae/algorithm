#include <iostream>
// 사탕 상자 indexed tree
#define MAX_L       1000000
#define SZ_TR       2100000

int tree[SZ_TR];
int OFFSET;

// void init(int N) {
//     for (OFFSET = 1; OFFSET < N; OFFSET*=2);
//     for (int i=0; i<N; ++i) tree[OFFSET+i] = nos[i];
//     for (int i=N; i<OFFSET; ++i) tree[OFFSET+i] = 0;
//     for (int i=OFFSET-1; i>0; --i) tree[i] = tree[i*2]+tree[i*2+1];
// }

void init(int N) {
    for (OFFSET = 1; OFFSET < N; OFFSET*=2);
}


int findKth(int k) {
    int idx = 1, left, right;
    while (idx < OFFSET) {
        left = idx * 2, right = left + 1;
        if (tree[left] < k) k -= tree[left], idx = right;
        else idx = left;
    }
    return idx - OFFSET;
}

void update(int taste, int val) {
    taste += OFFSET;
    tree[taste] += val;
    taste /= 2;
    while (taste > 0) {
        tree[taste] = tree[taste*2] + tree[taste*2+1];
        taste /= 2;
    }
}

int main() {
    int N, a, b, c;
    scanf("%d", &N);
    init(1000000);
    for (int i=0; i<N; ++i) {
        scanf("%d %d", &a, &b);
        if (a == 1) {
            //0자리에 맛1 들어가있으니까
            printf("%d\n", findKth(b)+1);
            update(findKth(b), -1);
        }
        else {
            scanf("%d", &c);
            update(b-1, c);
        }

    }

    return 0;
}