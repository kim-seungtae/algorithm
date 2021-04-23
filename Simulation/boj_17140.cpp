#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N       200
#define vi          vector<int>
#define pii         pair<int, int>
#define vvi         vector<vector<int>>
using namespace std;

int matrix[MAX_N+1][MAX_N+1];
int r, c, k, rSize, cSize, t, ans;
int max(int a, int b) {return a>b?a:b;}
bool compare(const pii& a, const pii& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
void matToVec(vvi& v, int op) {
    if (op == 0) {
        for (int i=0; i<rSize; ++i) {
            vi tmp;
            for (int j=0; j<cSize; ++j) {
                if (matrix[i][j] == 0) continue;
                tmp.push_back(matrix[i][j]);
            }
            v.push_back(tmp);
        }
    }
    else {
        for (int j=0; j<cSize; ++j) {
            vi tmp;
            for (int i=0; i<rSize; ++i) {
                if (matrix[i][j] == 0) continue;
                tmp.push_back(matrix[i][j]);
            }
            v.push_back(tmp);
        }
    }
}
void vecToMat(vvi& v, int op) {
    int i, j;
    cSize = -1, rSize = -1;
    if (op == 0) {
        rSize = v.size();
        for (i=0; i<rSize; ++i) {
            cSize = max(cSize, v[i].size());
            for (j=0; j<v[i].size(); ++j) {
                matrix[i][j] = v[i][j];
            }
        }
        //cSize를 일단 구해야 나머지를 0으로 채울수있다.
        for (i=0; i<rSize; ++i) {
            for (j=v[i].size(); j<cSize; ++j) {
                matrix[i][j] = 0;
            }
        }
    }
    else {
        cSize = v.size();
        for (i=0; i<cSize; ++i) {
            rSize = max(rSize, v[i].size());
            for (j=0; j<v[i].size(); ++j) {
                matrix[j][i] = v[i][j];
            }
        }
        for (j=0; j<cSize; ++j) {
            for (i=v[j].size(); i<rSize; ++i) {
                matrix[i][j] = 0;
            }
        }
    }
}
void input() {
    cin >> r >> c >> k;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            cin >> matrix[i][j];
        }
    }
    rSize = 3, cSize = 3;
    ans = -1;
    t = 0;
}

int main() {
    ios::sync_with_stdio(false);
    input();
    while (true) {
        if (matrix[r-1][c-1] == k) {
            ans = t;
            break;
        }
        if (t > 100) break;
        vvi v, next_v;
        matToVec(v, rSize>=cSize?0:1);
        for (int i=0; i<v.size(); ++i) {
            int counting[101] = {0, };
            for (int j=0; j<v[i].size(); ++j) {
                counting[v[i][j]] += 1;
            }
            vector<pii> tmp;
            for (int j=1; j<=100; ++j) {
                if (counting[j] == 0) continue;
                tmp.push_back({counting[j], j});
            }
            sort(tmp.begin(), tmp.end(), compare);
            vi tmp_r;
            for (int i=0; i<tmp.size(); ++i) {
                tmp_r.push_back(tmp[i].second);
                tmp_r.push_back(tmp[i].first);
            }
            next_v.push_back(tmp_r);
        }
        vecToMat(next_v, rSize>=cSize?0:1);
        ++t;
    }
    cout << ans << endl;
    return 0;
}