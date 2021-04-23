//고스택
#include <iostream>
#include <string.h>
#include <vector>
#define SZ_STK  1000
using namespace std;
typedef long long ll;

struct Stk {
    ll arr[SZ_STK];
    int idx;

    void init(const ll& n) {
        arr[idx=0] = n;
    }

    bool num(const ll& n) {
        ++idx;
        arr[idx] = n;
        return true;
    }

    bool pop() {
        if (idx >= 0) {
            --idx;
            return true;
        }
        else {
            return false;
        }
    }

    bool inv() {
        if (idx < 0) return false;
        arr[idx] *= -1;
        return true;
    }

    bool dup() {
        if (idx < 0) return false;
        ++idx;
        arr[idx] = arr[idx-1];
        return true;
    }

    bool swp() {
        if (idx < 1) return false;
        ll t = arr[idx];
        arr[idx] = arr[idx-1];
        arr[idx-1] = t;
        return true;
    }

    bool add() {
        if (idx < 1) return false;
        arr[idx-1] += arr[idx];
        --idx;
        if (arr[idx] > 1000000000 || arr[idx] < -1000000000) return false;
        return true;
    }

    bool sub() {
        if (idx < 1) return false;
        arr[idx-1] -= arr[idx];
        --idx;
        if (arr[idx] > 1000000000 || arr[idx] < -1000000000) return false;
        return true;
    }

    bool mul() {
        if (idx < 1) return false;
        arr[idx-1] *= arr[idx];
        --idx;
        if (arr[idx] > 1000000000 || arr[idx] < -1000000000) return false;
        return true;
    }

    bool div() {
        if (idx < 1) return false;
        if (arr[idx] == 0) return false;
        arr[idx-1] /= arr[idx];
        --idx;
        if (arr[idx] > 1000000000 || arr[idx] < -1000000000) return false;
        return true;
    }

    bool mod() {
        if (idx < 1) return false;
        if (arr[idx] == 0) return false;
        arr[idx-1] %= arr[idx];
        --idx;
        if (arr[idx] > 1000000000 || arr[idx] < -1000000000) return false;
        return true;
    }
    int size() {
        return idx+1;
    }
};


int main() {
    int num[1000], numIdx; // NUM 명령 뒤에 오는 숫자 저장
    int orderList[100000], orderIdx; //명령어 저장
    char tmpOrder[5];
    int tmpNum;
    Stk stk;
    while(1) {
        numIdx = 0;
        orderIdx = 0;
        while (scanf("%s", tmpOrder)) {
            if (!strcmp(tmpOrder, "QUIT")) return 0;
            if (!strcmp(tmpOrder, "END")) break;
            if (!strcmp(tmpOrder, "NUM")) {
                orderList[orderIdx++] = 0;
                scanf("%d", &tmpNum);
                num[numIdx++] = tmpNum;
            }
            if (!strcmp(tmpOrder, "POP")) orderList[orderIdx++] = 1;
            if (!strcmp(tmpOrder, "INV")) orderList[orderIdx++] = 2;
            if (!strcmp(tmpOrder, "DUP")) orderList[orderIdx++] = 3;
            if (!strcmp(tmpOrder, "SWP")) orderList[orderIdx++] = 4;
            if (!strcmp(tmpOrder, "ADD")) orderList[orderIdx++] = 5;
            if (!strcmp(tmpOrder, "SUB")) orderList[orderIdx++] = 6;
            if (!strcmp(tmpOrder, "MUL")) orderList[orderIdx++] = 7;
            if (!strcmp(tmpOrder, "DIV")) orderList[orderIdx++] = 8;
            if (!strcmp(tmpOrder, "MOD")) orderList[orderIdx++] = 9;
        }
        int N;
        scanf("%d", &N);
        for (int n=0; n<N; ++n) {
            int initNum;
            numIdx = 0;
            scanf("%d", &initNum);
            stk.init(initNum);
            bool errorChk = true;
            for (int i=0; i<orderIdx; ++i) {
                if (orderList[i] == 0) stk.num(num[numIdx++]);
                else if (orderList[i] == 1) errorChk = stk.pop();
                else if (orderList[i] == 2) errorChk = stk.inv();
                else if (orderList[i] == 3) errorChk = stk.dup();
                else if (orderList[i] == 4) errorChk = stk.swp();
                else if (orderList[i] == 5) errorChk = stk.add();
                else if (orderList[i] == 6) errorChk = stk.sub();
                else if (orderList[i] == 7) errorChk = stk.mul();
                else if (orderList[i] == 8) errorChk = stk.div();
                else if (orderList[i] == 9) errorChk = stk.mod();

                if (errorChk == false) break;
            }
            if (errorChk == false || stk.size() != 1) {
                printf("ERROR\n");
            }
            else printf("%lld\n", stk.arr[stk.idx]);
        }
        printf("\n");
    }
    return 0;
}