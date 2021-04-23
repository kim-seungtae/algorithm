#include <iostream>
using namespace std;
int map[10][10], ans;
void drop(int t, int _y, int _x) {
    int y = _y;
    int x = _x;

    if (t == 1) {
        while (y < 10 && map[y][x] == 0) {
            ++y;
        }
        --y;
        map[y][x] = 1;

        y = _y;
        while (x < 10 && map[y][x] == 0) {
            ++x;
        }
        --x;
        map[y][x] = 1;
    }
    else if (t == 2) {
        while (y < 10 && map[y][x] == 0 && map[y][x+1] == 0) {
            ++y;
        } 
        --y;
        map[y][x] = 1, map[y][x+1] = 1;

        y = _y;
        x = _x+1;
        while (x < 10 && map[y][x] == 0) {
            ++x;
        }
        --x;
        map[y][x] = 1, map[y][x-1] = 1;
    }
    else if (t == 3) {
        y = _y+1;
        while (y < 10 && map[y][x] == 0) {
            ++y;
        }
        --y;
        map[y][x] = 1, map[y-1][x] = 1;

        y = _y;
        while (x < 10 && map[y][x] == 0 && map[y+1][x] == 0) {
            ++x;
        }
        --x;
        map[y][x] = 1, map[y+1][x] = 1;
    }
}
void deleteGreenLine(int num, int idx) {
    for (int i=idx; i>=4; --i) {
        for (int j=0; j<4; ++j) {
            map[i][j] = map[i-num][j];
        }
    }
}
void deleteBlueLine(int num, int idx) {
    for (int j=idx; j>=4; --j) {
        for (int i=0; i<4; ++i) {
            map[i][j] = map[i][j-num];
        }
    }
}
void deleteFullLine() {
    int numOfFullLine = 0;
    int idx;
    for (int i=6; i<10; ++i) {
        bool deleteFlag = true;
        for (int j=0; j<4; ++j) {
            if (map[i][j] == 0) deleteFlag = false;
        }
        if (deleteFlag) {
            idx = i;
            ++numOfFullLine;
        }
    }

    if (numOfFullLine) deleteGreenLine(numOfFullLine, idx);
    ans += numOfFullLine;

    numOfFullLine = 0;
    for (int j=6; j<10; ++j) {
        bool deleteFlag = true;
        for (int i=0; i<4; ++i) {
            if (map[i][j] == 0) deleteFlag = false;
        }
        if (deleteFlag) {
            idx = j;
            ++numOfFullLine;
        }
    }
    if (numOfFullLine) deleteBlueLine(numOfFullLine, idx);
    ans += numOfFullLine;
}
void deleteLightLine() {
    int numOfLightLine = 0;
    //green
    for (int i=4; i<6; ++i) {
        for (int j=0; j<4; ++j) {
            if (map[i][j] == 1) {
                ++numOfLightLine;
                break;
            }
        }
    }
    if (numOfLightLine) deleteGreenLine(numOfLightLine, 9);

    //blue
    numOfLightLine = 0;
    for (int j=4; j<6; ++j) {
        for (int i=0; i<4; ++i) {
            if (map[i][j] == 1) {
                ++numOfLightLine;
                break;
            }
        }
    }
    if (numOfLightLine) deleteBlueLine(numOfLightLine, 9);
}

int getRemainBlock() {
    int ret = 0;
    for (int i=6; i<10; ++i) {
        for (int j=0; j<4; ++j) {
            if (map[i][j] == 1) ++ret;
        }
    }
    for (int j=6; j<10; ++j) {
        for (int i=0; i<4; ++i) {
            if (map[i][j] == 1) ++ret;
        }
    }
    return ret;
}
int main() {
    int N;
    cin >> N;
    int t, x, y;
    for (int n=0; n<N; ++n) {
        cin >> t >> x >> y;
        drop(t, x, y);
        deleteFullLine();
        deleteLightLine();
    }
    int blocks = getRemainBlock();
    cout << ans << "\n" << blocks << endl;
    return 0;
}