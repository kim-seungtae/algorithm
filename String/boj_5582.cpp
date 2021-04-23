#include <cstdio>
#include <cstring>
//공통부분문자열. longest common substring
using namespace std;

#define MAX_L       4000

char a[MAX_L+2];
char b[MAX_L+2];
int map[MAX_L+1][MAX_L+1];

int max(int a, int b) {return a>b?a:b;}

int main() {

    
    scanf("%s", a+1);
    scanf("%s", b+1);
    a[0] = 'a'; b[0] = 'b';
    int ans = 0;
    for (int i=1; i<strlen(a); ++i) {
        for (int j=1; j<strlen(b); ++j) {
            if (a[i] == b[j]) {
                map[i][j] = map[i-1][j-1] + 1;
                ans = max(ans, map[i][j]);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}