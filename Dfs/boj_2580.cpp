#include <iostream>
#include <vector>

using namespace std;
//스도쿠
int r, c; //스도쿠 가로, 세로, 박스 각각 남은 숫자가 뭔지 알아야한다
bool HSels[9][10], VSels[9][10], BSels[9][10]; //[x][i] x번째 행, 열, 박스에 i가 포함되어있으면 true.
int sudoku[9][9];

bool backtracking(int y, int x) {
    if (x==9) ++y, x=0;
    if (y==9) return true;
    if (sudoku[y][x] != 0) return backtracking(y, x+1);

    bool res = false;
    int box = (y/3)*3 + x/3; //box number
    for (int i=1; i<=9; ++i) {
        if (!HSels[y][i] && !VSels[x][i] && !BSels[box][i]) {
            sudoku[y][x] = i;
            HSels[y][i] = VSels[x][i] = BSels[box][i] = true;
            if (backtracking(y, x+1)) {
                res = true;
                break;
            }
            HSels[y][i] = VSels[x][i] = BSels[box][i] = false;
            sudoku[y][x] = 0;
        }
    }
    return res;
}
int main() {
    int n;
    for (int y=0; y<9; y++) {
        for (int x=0; x<9; x++) {
            scanf("%d", &sudoku[y][x]);
            if (sudoku[y][x] != 0) {
                HSels[y][sudoku[y][x]] = true;
                VSels[x][sudoku[y][x]] = true;
                BSels[(y/3)*3+x/3][sudoku[y][x]] = true;
            }
        }
    }

    if (backtracking(0,0)) {
        for (int y=0; y<9; y++) {
            for (int x=0; x<9; x++) {
                printf("%d ", sudoku[y][x]);
            }
            printf("\n");
        }
    }
    return 0;
}