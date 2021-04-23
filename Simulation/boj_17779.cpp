#include <iostream>
#define MAX_N       20
using namespace std;

int N, ans;
int A[MAX_N][MAX_N];
int area[MAX_N][MAX_N];
int y[4], x[4];
int min(int a, int b) {return a<b?a:b;}
void printarea() {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cout << area[i][j] << " ";
        }
        cout << endl;
    }
}
void input() {
    cin >> N;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        cin >> A[i][j];
        area[i][j] = 0;
    }
    ans = 9999999;
}
void divide() {
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        area[i][j] = 0;
    }
    int k;
    //area 1
    k = 0;
    for (int i=0; i<y[1]; ++i) {
        if (i >= y[0]) ++k;
        for (int j=0; j<=x[0]-k; ++j) area[i][j] = 1;
    }

    //area 2
    k = 1;
    for (int i=0; i<=y[2]; ++i) {
        if (i > y[0]) ++k;
        for (int j=x[0]+k; j<N; ++j) area[i][j] = 2;
    }

    //area 3
    k = -1;
    for (int i=y[1]; i<N; ++i) {
        if (i <= y[3]) ++k;
        for (int j=0; j<x[1]+k; ++j) area[i][j] = 3;
    }
    
    //area 4
    k = 0;
    for (int i=y[2]+1; i<N; ++i) {
        if (i <= y[3]+1) ++k;
        for (int j=N-1; j>x[2]-k; --j) area[i][j] = 4;
    }
}
int calculate() {
    int sum[5] = {0, };
    int M, m;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        sum[area[i][j]] += A[i][j];
    }
    M = sum[0], m = sum[0];
    for (int i=1; i<5; ++i) {
        if (M < sum[i]) M = sum[i];
        if (m > sum[i]) m = sum[i];
    }
    return M - m;
}
int main() {
    input();
    for (int i=0; i<N; ++i) for (int j=1; j<N; ++j) {
        for (int d1=1; j-d1>=0; ++d1) {
            for (int d2=1; j+d2<N; ++d2) {
                if (i+d1+d2 >= N) continue;
                y[0] = i, x[0] = j;
                y[1] = i+d1, x[1] = j-d1;
                y[2] = i+d2, x[2] = j+d2;
                y[3] = i+d1+d2, x[3] = j-d1+d2;
                divide();
                ans = min(ans, calculate());
            }
        } 
    }
    cout << ans << endl;
    return 0;
}