#include <iostream>
#include <vector>
#define MAX_N       50
#define MAX_M       2500
using namespace std;
class fireball {
public:
    fireball() {}
    fireball(int w, int s, int d) : weight(w), speed(s), direction(d) {}
    int weight;
    int speed;
    int direction;
};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int dx[8] = {0,1,1,1,0,-1,-1,-1};
int N, M, K;
vector<fireball> map[2][MAX_N][MAX_N];

void input() {
    cin >> N >> M >> K;
    int a, b, c, d, e;
    for (int i=0; i<M; ++i) {
        cin >> a >> b >> c >> d >> e;
        map[0][a-1][b-1].push_back(fireball(c, d, e));
    }
}
void moveFireball(int plain) {
    int next = (plain+1)%2;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        if (map[plain][i][j].empty()) continue;
        for (fireball f : map[plain][i][j]) {
            int y = (i + (f.speed%N) * dy[f.direction] + N) % N;
            int x = (j + (f.speed%N) * dx[f.direction] + N) % N;

            map[next][y][x].push_back(fireball(f.weight, f.speed, f.direction));
        }
    }

    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        map[plain][i][j].clear();
    }
    
}
void divideFireball(int plain) {
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        if (map[plain][i][j].size() > 1) {
            int sumW = 0, sumS = 0;
            bool oddSig = false, evenSig = false;
            for (fireball f : map[plain][i][j]) {
                sumW += f.weight;
                sumS += f.speed;
                if (f.direction % 2 == 0) evenSig = true;
                else oddSig = true;
            }
            int w = sumW / 5;
            int s = sumS / map[plain][i][j].size();
            int d = (oddSig && evenSig) ? 1 : 0;

            map[plain][i][j].clear();

            if (w == 0) continue;
            for (int k=0; k<4; ++k) {
                map[plain][i][j].push_back(fireball(w, s, d));
                d+=2;
            }
        }
    }
}
int sumOfFireballWeight(int plain) {
    int sum = 0;
    for (int i=0; i<N; ++i) for (int j=0; j<N; ++j) {
        if (map[plain][i][j].empty()) continue;
        for (fireball f : map[plain][i][j]) {
            sum += f.weight;
        }
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    input();
    int p = 0;
    for (int k=0; k<K; ++k) {
        moveFireball(p);
        p = (p+1)%2;
        divideFireball(p);
    }
    cout << sumOfFireballWeight(p) << endl;
    return 0;
}