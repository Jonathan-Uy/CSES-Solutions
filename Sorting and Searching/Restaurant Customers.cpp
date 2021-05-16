#include <bits/stdc++.h>

using namespace std;
const int maxN = 4e5;

int N, a, b, cur, ans;
struct event {int time, type;} events[maxN];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &a, &b);
        events[2*i] = {a, 1};
        events[2*i+1] = {b, -1};
    }
    sort(events, events+2*N, [](event A, event B){
        return A.time == B.time ? A.type < B.type : A.time < B.time;
    });

    for(int i = 0; i < 2*N; i++){
        cur += events[i].type;
        ans = max(ans, cur);
    }
    printf("%d\n", ans);
}
