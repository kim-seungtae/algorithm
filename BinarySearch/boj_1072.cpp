#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll X, Y, Z;
//게임
int main() {
    scanf("%lld %lld", &X, &Y);
    Z = Y * 100 / X;
    if (Z >= 99) {printf("-1"); return 0;}

    int l = 0, r = 1000000000;
    while (l <= r) {
        int mid = (l + r) / 2;
        if ((mid+Y)*100/(X+mid) > Z) {
            r = mid-1;
        }
        else l = mid+1;
    }
    printf("%d", l);
    return 0;
}