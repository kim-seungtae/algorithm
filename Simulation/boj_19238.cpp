#include <iostream>
#include <queue>
#define MAX_N       20
#define MAX_M       400
#define IMPOSSIBLE      999999
using namespace std;
typedef pair<int, int> pii;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int N, M, oil;
int map[MAX_N+1][MAX_N+1];
pii taxi, start[MAX_M], dest[MAX_M];
bool isFinish[MAX_M];
int remainCustomer;

struct cmp {
    bool operator() (pair<pii, pii> a, pair<pii, pii> b) {
        if (a.first.first > b.first.first) return true;
        else if (a.first.first == b.first.first) {
            if (a.second.first > b.second.first) return true;
            else if (a.second.first == b.second.first) {
                if (a.second.second > b.second.second) return true;
                else return false;
            }
            else return false;
        }
        else return false;
    }
};
void input() {
    cin >> N >> M >> oil;
    for (int i=1; i<=N; ++i) for (int j=1; j<=N; ++j) {
        cin >> map[i][j];
    }
    cin >> taxi.first >> taxi.second;
    for (int i=0; i<M; ++i) {
        cin >> start[i].first >> start[i].second >> dest[i].first >> dest[i].second;
    }
    for (int i=0; i<M; ++i) isFinish[i] = false;
    remainCustomer = M;
}
int getDistance(pii a, pii b) {
    if (a.first == b.first && a.second == b.second) return 0;

    queue<pair<pii, int>> q;
    bool visited[MAX_N+1][MAX_N+1] = {false, };
    q.push({a, 0});
    visited[a.first][a.second] = true;
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int t = q.front().second;
        q.pop();
        if (y == b.first && x == b.second) {
            return t;
        }
        for (int i=0; i<4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny<1||ny>N||nx<1||nx>N||map[ny][nx]||visited[ny][nx]) continue;
            visited[ny][nx] = true;
            q.push({{ny, nx}, t+1});
        }
    }
    return IMPOSSIBLE;
}
pair<pii, pii> find_shortest_customer() {
    priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, cmp> pq;
    for (int i=0; i<M; ++i) {
        if (!isFinish[i]) pq.push({{getDistance(start[i], taxi), i}, start[i]});
    }
    return pq.top();
}
void move_taxi(pii dest) {
    taxi.first = dest.first;
    taxi.second = dest.second;
}
int main() {
    ios::sync_with_stdio(false);
    input();
    while (remainCustomer > 0) {
        // {{distance, customerIdx}, {startingPoint y, x}}
        pair<pii, pii> customer = find_shortest_customer();
        if (customer.first.first == IMPOSSIBLE) {
            oil = -1;
            break;
        }
        oil -= customer.first.first;
        move_taxi(customer.second);
        if (oil <= 0) break;

        pii destination = dest[customer.first.second];
        int distance = getDistance(taxi, destination);
        oil -= distance;
        move_taxi(destination);
        if (oil < 0) break;

        isFinish[customer.first.second] = true;
        --remainCustomer;
        oil += distance*2;
    }
    if (oil < 0) oil = -1;
    cout << oil << endl;
    return 0;
}
