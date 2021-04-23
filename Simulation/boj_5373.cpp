#include <iostream>
using namespace std;

int N, M;
char tmp[2];
char cube[21][3][3];

void init() {
    for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) {
        cube['U'-65][i][j] = 'w';
        cube['D'-65][i][j] = 'y';
        cube['F'-65][i][j] = 'r';
        cube['B'-65][i][j] = 'o';
        cube['L'-65][i][j] = 'g';
        cube['R'-65][i][j] = 'b';

    }
}
void rotateMainPlain(int plain) {
    int tmp[3][3];
    for (int i=0; i<3; ++i) for (int j=0; j<3; ++j) tmp[i][j] = cube[plain][i][j];
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            cube[plain][j][3-i-1] = tmp[i][j];
        }
    }
}
void rotate(int plain) {
    rotateMainPlain(plain-65);
    int sidePlain[4][3];
    if (plain == 'U') {
        //B, R, F, L
        for (int i=0; i<3; ++i) sidePlain[1][i] = cube['B'-65][2][i];
        for (int i=0; i<3; ++i) sidePlain[2][i] = cube['R'-65][i][0];
        for (int i=0; i<3; ++i) sidePlain[3][i] = cube['F'-65][0][2-i];
        for (int i=0; i<3; ++i) sidePlain[0][i] = cube['L'-65][2-i][2];

        for (int i=0; i<3; ++i) cube['B'-65][2][i] = sidePlain[0][i];
        for (int i=0; i<3; ++i) cube['R'-65][i][0] = sidePlain[1][i];
        for (int i=0; i<3; ++i) cube['F'-65][0][2-i] = sidePlain[2][i];
        for (int i=0; i<3; ++i) cube['L'-65][2-i][2] = sidePlain[3][i];
    }
    else if (plain == 'D') {
        //F, R, B, L
        for (int i=0; i<3; ++i) sidePlain[1][i] = cube['F'-65][2][i];
        for (int i=0; i<3; ++i) sidePlain[2][i] = cube['R'-65][2-i][2];
        for (int i=0; i<3; ++i) sidePlain[3][i] = cube['B'-65][0][2-i];
        for (int i=0; i<3; ++i) sidePlain[0][i] = cube['L'-65][i][0];

        for (int i=0; i<3; ++i) cube['F'-65][2][i] = sidePlain[0][i];
        for (int i=0; i<3; ++i) cube['R'-65][2-i][2] = sidePlain[1][i];
        for (int i=0; i<3; ++i) cube['B'-65][0][2-i] = sidePlain[2][i];
        for (int i=0; i<3; ++i) cube['L'-65][i][0] = sidePlain[3][i];
    }
    else if (plain == 'F') {
        //U, R, D, L
        for (int i=0; i<3; ++i) sidePlain[1][i] = cube['U'-65][2][i];
        for (int i=0; i<3; ++i) sidePlain[2][i] = cube['R'-65][2][i];
        for (int i=0; i<3; ++i) sidePlain[3][i] = cube['D'-65][0][2-i];
        for (int i=0; i<3; ++i) sidePlain[0][i] = cube['L'-65][2][i];

        for (int i=0; i<3; ++i) cube['U'-65][2][i] = sidePlain[0][i];
        for (int i=0; i<3; ++i) cube['R'-65][2][i] = sidePlain[1][i];
        for (int i=0; i<3; ++i) cube['D'-65][0][2-i] = sidePlain[2][i];
        for (int i=0; i<3; ++i) cube['L'-65][2][i] = sidePlain[3][i];
    }
    else if (plain == 'B') {
        //D, R, U, L
        for (int i=0; i<3; ++i) sidePlain[1][i] = cube['D'-65][2][i];
        for (int i=0; i<3; ++i) sidePlain[2][i] = cube['R'-65][0][2-i];
        for (int i=0; i<3; ++i) sidePlain[3][i] = cube['U'-65][0][2-i];
        for (int i=0; i<3; ++i) sidePlain[0][i] = cube['L'-65][0][2-i];

        for (int i=0; i<3; ++i) cube['D'-65][2][i] = sidePlain[0][i];
        for (int i=0; i<3; ++i) cube['R'-65][0][2-i] = sidePlain[1][i];
        for (int i=0; i<3; ++i) cube['U'-65][0][2-i] = sidePlain[2][i];
        for (int i=0; i<3; ++i) cube['L'-65][0][2-i] = sidePlain[3][i];
    }
    else if (plain == 'L') {
        //B, U, F, D
        for (int i=0; i<3; ++i) sidePlain[1][i] = cube['B'-65][i][0];
        for (int i=0; i<3; ++i) sidePlain[2][i] = cube['U'-65][i][0];
        for (int i=0; i<3; ++i) sidePlain[3][i] = cube['F'-65][i][0];
        for (int i=0; i<3; ++i) sidePlain[0][i] = cube['D'-65][i][0];

        for (int i=0; i<3; ++i) cube['B'-65][i][0] = sidePlain[0][i];
        for (int i=0; i<3; ++i) cube['U'-65][i][0] = sidePlain[1][i];
        for (int i=0; i<3; ++i) cube['F'-65][i][0] = sidePlain[2][i];
        for (int i=0; i<3; ++i) cube['D'-65][i][0] = sidePlain[3][i];
    }
    else if (plain == 'R') {
        //B, D, F, U
        for (int i=0; i<3; ++i) sidePlain[1][i] = cube['B'-65][2-i][2];
        for (int i=0; i<3; ++i) sidePlain[2][i] = cube['D'-65][2-i][2];
        for (int i=0; i<3; ++i) sidePlain[3][i] = cube['F'-65][2-i][2];
        for (int i=0; i<3; ++i) sidePlain[0][i] = cube['U'-65][2-i][2];

        for (int i=0; i<3; ++i) cube['B'-65][2-i][2] = sidePlain[0][i];
        for (int i=0; i<3; ++i) cube['D'-65][2-i][2] = sidePlain[1][i];
        for (int i=0; i<3; ++i) cube['F'-65][2-i][2] = sidePlain[2][i];
        for (int i=0; i<3; ++i) cube['U'-65][2-i][2] = sidePlain[3][i];
    }
}

int main() {
    cin >> N;
    for (int n=0; n<N; ++n) {
        init();
        cin >> M;
        for (int m=0; m<M; ++m) {
            cin >> tmp;
            rotate(tmp[0]);
            if (tmp[1] == '-') {
                rotate(tmp[0]);
                rotate(tmp[0]);
            }
        }
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j)
                cout << cube['U'-65][i][j];
            cout << endl;
        }
    }
    return 0;
}