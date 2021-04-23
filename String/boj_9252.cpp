#include <cstdio>
#include <cstring>
//LCS 2. longest common subsequence
using namespace std;

#define MAX_L       1000

int max(int a, int b) {return a>b?a:b;}
int min(int a, int b) {return a>b?b:a;}

char a[MAX_L+1];
char b[MAX_L+1];
int map[MAX_L+1][MAX_L+1];
char output[MAX_L+1];

int main() {
    scanf("%s", a+1);
    scanf("%s", b+1);
    a[0] = 'a'; b[0] = 'b';
    for (int i=1; i<strlen(a); ++i) {
        for (int j=1; j<strlen(b); ++j) {
            if (a[i] == b[j]) {
                map[i][j] = map[i-1][j-1] + 1;
            }
            else {
                map[i][j] = max(map[i-1][j], map[i][j-1]);
            }
        }
    } 
    
    int size = map[strlen(a)-1][strlen(b)-1];
    printf("%d\n", size);
    int i = strlen(a) - 1, j = strlen(b) - 1;
    while (size > 0) {
        //방향이 대각선이면
        if (max(map[i-1][j], map[i][j-1]) < map[i][j] && map[i][j] -1 == map[i-1][j-1]) {
            output[size--] = b[j];
            --i, --j;
        }//위, 왼쪽중에 위가 크거나 같으면 위로.
        else if (map[i-1][j] > map[i][j-1]) {
            --i;
        }//왼쪽이 더 크면 왼쪽으로
        else {
            --j;
        }
    }
    for (int i=1; i<=map[strlen(a)-1][strlen(b)-1]; ++i) {
        printf("%c", output[i]);
    }
    
    return 0;
}