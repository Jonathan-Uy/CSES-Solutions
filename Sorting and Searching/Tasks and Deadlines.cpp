#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5;

int N, a, d;
long long timer, reward;
struct task {int a, d;} tasks[maxN];

int main (){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &a, &d);
        tasks[i] = {a, d};
    }

    sort(tasks, tasks+N, [](task x, task y){
        return x.a == y.a ? x.d < y.d : x.a < y.a;
    });

    for(int i = 0; i < N; i++){
        timer += tasks[i].a;
        reward += (tasks[i].d - timer);
    }
    printf("%lld\n", reward);
}
