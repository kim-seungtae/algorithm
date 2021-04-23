#include <iostream>
//스택
struct Stk {
    int arr[10000];
    int idx;

    void init() {
        idx = -1;
    }
    void push(int X) {
        ++idx;
        arr[idx] = X;
    }
    void pop() {
        if (idx == -1) printf("-1\n");
        else {
            top();
            --idx;
        }
    }
    void size() {
        printf("%d\n", idx+1);
    }
    void empty() {
        if (idx == -1) printf("1\n");
        else printf("0\n");
    }
    void top() {
        if (idx == -1) printf("-1\n");
        else printf("%d\n", arr[idx]);
    }
};

int main() {
    int N;
    scanf("%d", &N);
    char inst[10];
    int num;
    Stk s;
    s.init();
    for (int i=0; i<N; ++i) {
        scanf("%s", inst);
        if (inst[1] == 'u') {
            scanf("%d", &num);
            s.push(num);
        }
        else if (inst[0] == 'p') s.pop();
        else if (inst[0] == 's') s.size();
        else if (inst[0] == 'e') s.empty();
        else if (inst[0] == 't') s.top();
    }
    return 0;
}