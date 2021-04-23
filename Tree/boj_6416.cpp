// #include <iostream>
// #include <map>
// #include <queue>
// //트리인가?
// using namespace std;
//              //각각 어디로 나가는지, 부모가 누구인지
// map<int, int> outs, edges;
// queue<int> que;
// int check() {
//     int res = 0, cur, par;

//     while (!que.empty()) que.pop();
//     //queue에 리프노드 다 넣기
//     for (auto i : outs) {
//         if (i.second == 0) que.push(i.first);
//     }

//     while (!que.empty()) {
//         cur = que.front(), que.pop();
//         par = edges[cur];
//         ++res;
//         --outs[par];
//         if (outs[par] == 0) que.push(par);
//     }
//     return res;
// }

// int main() {
//     int f, t, e;
//     int tn = 0;
//     bool end = false;

//     while (true) {
//         ++tn;
//         e = 0;
//         outs.clear(), edges.clear();

//         while (true) {
//             scanf("%d %d", &f, &t);
//             if (f < 0 && t < 0) {
//                 end = true;
//                 break;
//             }
//             if (f == 0 && t == 0) break;

//             ++e;
//             if (outs.find(f) == outs.end()) outs.insert({f, 1});
//             else ++outs[f];

//             if (outs.find(t) == outs.end()) outs.insert({t, 0});
//             if (edges.find(t) == edges.end()) edges.insert({t,f});

//         }
//         if (end) break;
//         if (e == 0 || e + 1 == check()) {
//             printf("Case %d is a tree.\n", tn);
//         }
//         else {
//             printf("Case %d is not a tree\n", tn);
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <map>
#include <queue>
//트리인가?
using namespace std;
//idx, 횟수
map<int, int> out, edges;
queue<int> que;

int check() {
    int res = 0;

    while (!que.empty()) que.pop();

    //나가는게 없는 노드들 다 que에 넣기
    for (auto i : out) {
        if (i.second == 0) que.push(i.first);
    }

    while (!que.empty()) {
        int cur, par;
        cur = que.front(), que.pop();
        par = edges[cur];
        --out[par];
        if (out[par] == 0) que.push(par);
        ++res;
    }

    return res;
}

int main() {
    int f, t, e, tn=0, flag=0;
    while (true) {
        ++tn;
        out.clear(), edges.clear();
        e = 0;

        while (true) {
            scanf("%d %d", &f, &t);
            if (f == 0 && t == 0) {
                break;
            }
            else if (f==-1 && t==-1) {
                flag = true;
                break;
            }
            ++e;
            if (out.find(f) == out.end()) out.insert({f, 1});
            else ++out[f];
            if (out.find(t) == out.end()) out.insert({t, 0});
            if (edges.find(t) == edges.end()) edges.insert({t, f});
            
        }
        if (flag) break;
        if (e == 0 || check() == e + 1) printf("Case %d is a tree.\n", tn);
        else printf("Case %d is not a tree.\n", tn);
    }

    return 0;
}