#include <cstdio>
#include <vector>
#include <string>
//가르침
using namespace std;

int n, k, ans;
int alphabet[26];
vector<string> words;
int max(int a, int b) {return a>b?a:b;}

bool check(string a) {
    for (int i=0; i<a.length(); ++i) {
        if (!alphabet[a[i] -'a']) return false;
    }
    return true;
}

void dfs(int idx, int cnt) {
    if (cnt == k - 5) {
        //몇개 가능한지
        int tmp = 0;
        for (int i=0; i<words.size(); ++i) {
            if (check(words[i])) ++tmp;
        }
        ans = max(ans, tmp);
        return;
    }
    if (idx == 25) return;

    for (int i=idx+1; i<26; ++i) {
        if (alphabet[i]) continue;
        alphabet[i] = 1;
        dfs(i, cnt+1);
        if (ans == words.size()) break;
        alphabet[i] = 0;
    }
}

int main() {
    scanf("%d %d", &n, &k);
    if (k < 5) {printf("0\n"); return 0;}
    alphabet[0] = 1, alphabet[2] = 1, alphabet[8] = 1, alphabet[13] = 1, alphabet[19] = 1;
    char s[16];
    for (int i=0; i<n; ++i) {
        scanf("%s", s);
        string str(s);
        words.push_back(s);
    }

    dfs(0, 0);

    printf("%d\n", ans);
    return 0;
}