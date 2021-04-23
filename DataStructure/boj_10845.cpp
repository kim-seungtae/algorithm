#include <iostream>
//큐
struct Queue {
    int arr[10000];
    int f, b;

    void init() {
        f = 0;
        b = 0;
    }
    void push(int X) {
        arr[b++] = X;
    }
    void pop() {
        if (f == b) printf("-1\n");
        else {
            printf("%d\n", arr[f]);
            ++f;
        }
    }
    void size() {
        printf("%d\n", b-f);
    }
    void empty() {
        if (f == b) printf("1\n");
        else printf("0\n");
    }
    void front() {
        if (f == b) printf("-1\n");
        else printf("%d\n", arr[f]);
    }
    void back() {
        if (f == b) printf("-1\n");
        else printf("%d\n", arr[b-1]);
    }
};

int main() {
    int N;
    scanf("%d", &N);
    char inst[10];
    int num;
    Queue q;
    q.init();
    for (int i=0; i<N; ++i) {
        scanf("%s", inst);
        if (inst[1] == 'u') {
            scanf("%d", &num);
            q.push(num);
        }
        else if (inst[0] == 'p') q.pop();
        else if (inst[0] == 's') q.size();
        else if (inst[0] == 'e') q.empty();
        else if (inst[0] == 'f') q.front();
        else if (inst[0] == 'b') q.back();
    }
    return 0;
}