#include <iostream>
#include <queue>
#define MAX_F       1000000
#define MAX_U       1000000
#define INF         1000001
using namespace std;

typedef pair<int, int> pii;
bool visited[MAX_F];

int main() {
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    --F, --S, --G;
    
    int ans = INF;
    queue<pii> q;
    q.push({S, 0});
    visited[S] = true;

    while(!q.empty()) {
        int f = q.front().first;
        int t = q.front().second;
        q.pop();

        if (G == f) {
            cout << t << endl;
            return 0;
        }
        if (f + U <= F && !visited[f+U]) {
            visited[f+U] = true;
            q.push({f+U, t+1});
        }
        if (f - D >= 0 && !visited[f-D]) {
            visited[f-D] = true;
            q.push({f-D, t+1});
        }
    }
    cout << "use the stairs" << endl;
    return 0;
}