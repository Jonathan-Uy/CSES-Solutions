#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;

int N, a[maxN], deg[maxN];
priority_queue<int, vector<int>, greater<int>> Q;

int main(){
    scanf("%d", &N);
    fill(deg+1, deg+N+1, 1);
    for(int i = 0; i < N-2; i++){
        scanf("%d", &a[i]);
        deg[a[i]]++;
    }

    for(int i = 1; i <= N; i++)
        if(deg[i] == 1)
            Q.push(i);

    for(int i = 0; i < N-2; i++){
        int u = a[i];
        int v = Q.top(); Q.pop();

        deg[u]--; deg[v]--;
        if(deg[u] == 1)
            Q.push(u);

        printf("%d %d\n", u, v);
    }

    for(int i = 1; i <= N; i++)
        if(deg[i])
            printf("%d ", i);
}