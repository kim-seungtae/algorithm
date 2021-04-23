#include <iostream>
#include <vector>
//단절점 dfs로 돌면서 번호매기면서 내번호 < 자식중에 가장 작은번호면 단절점
using namespace std;
int order[10001], cut[10001], cnt;
vector<int> adjList[10001];
int min(int a, int b) {return a>b?b:a;}

int num = 0;
int dfs(int here, bool isRoot) {
    order[here] = ++num;
    int ret = order[here];
    int root_child = 0;

    for (int next: adjList[here]) {
        if (!order[next]) {
            ++root_child; //이렇게 하면 자식 뭉텅이 구하짐. dfs니까 연결돼있으면 한번밖에 안걸림
            int m = dfs(next, 0);
            if (!isRoot && m >= order[here]) cut[here] = true;
            ret = min(ret, m);
        }
        else {
            ret = min(ret, order[next]);
        }
    }
    if (isRoot && root_child > 1) cut[here] = true;
    return ret;
}

int main() {
    int v, e, f, t;
    scanf("%d %d", &v, &e);
    for (int i=0; i<e; ++i) {
        scanf("%d %d", &f, &t);
        adjList[f].push_back(t);
        adjList[t].push_back(f);
    }

    for (int i=1; i<=v; ++i) {
        if (!order[i]) dfs(i, 1);
    }
    for (int i=1; i<=v; ++i) if (cut[i] == true) ++cnt;
    printf("%d\n", cnt);
    for (int i=1; i<=v; ++i) if (cut[i] == true) printf("%d ", i);
    return 0;
}

// 1)
// scanf("%d %d",&v,&e); //v 1만, e 10만
// for(int i=0;i<e;i++){
//     scanf("%d %d", &from, &to);
//     adjList[from].add(to);
//     adjList[to].add(from);
// }

// 2)
// int dfs(int here, bool isRoot){ 
//     order[here]=++num;//num=0;
//     int ret=order[here];

//     int child_count=0;//root인 경우만 사용할 변수

//     for(int next:adjList[here]){

//         if(order[next]){
//             ret=min(ret,order[next]);
//             continue;
//         }
//         child_count++;
//         int min=dfs(next,false);
//         if(!isRoot&&mini>=order[here]){
//             //여기는 단절점이다.
//         }
//         ret=min(ret,min);
//     }
//     if(isRoot) if(child_count>1) //여기는 단절점이다
//     return ret; 
// }