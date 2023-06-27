#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;

int N, M, cnt, x[maxN], pos[maxN];

void update(int a, int b){
    if(pos[x[a]-1] <= pos[x[a]] && b < pos[x[a]-1]) cnt++;
    if(pos[x[a]-1] > pos[x[a]] && b >= pos[x[a]-1]) cnt--;
    if(pos[x[a]+1] >= pos[x[a]] && b > pos[x[a]+1]) cnt++;
    if(pos[x[a]+1] < pos[x[a]] && b <= pos[x[a]+1]) cnt--;
    pos[x[a]] = b;

    if(pos[x[b]-1] <= pos[x[b]] && a < pos[x[b]-1]) cnt++;
    if(pos[x[b]-1] > pos[x[b]] && a >= pos[x[b]-1]) cnt--;
    if(pos[x[b]+1] >= pos[x[b]] && a > pos[x[b]+1]) cnt++;
    if(pos[x[b]+1] < pos[x[b]] && a <= pos[x[b]+1]) cnt--;
    pos[x[b]] = a;

    swap(x[a], x[b]);
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        scanf("%d", &x[i]);
        pos[x[i]] = i;
    }
    pos[N+1] = N+1;

    cnt = 1;
    for(int i = 1, ptr = 0; i <= N; i++){
        if(ptr > pos[i])
            cnt++;
        ptr = pos[i];
    }

    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        update(a, b);
        printf("%d\n", cnt);
    }
}
