#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5;

int N, M, a, b, idx, in[maxN], ans[maxN];
vector<int> G[maxN];
priority_queue<int> Q;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        G[b].push_back(a);
        in[a]++;
    }

    for(int i = 1; i <= N; i++)
        if(in[i] == 0)
            Q.push(i);

    idx = N;
    while(!Q.empty()){
        int u = Q.top(); Q.pop();
        ans[idx--] = u;
        for(int v : G[u]){
            in[v]--;
            if(in[v] == 0)
                Q.push(v);
        }
    }

    for(int i = 1; i <= N; i++)
        printf("%d%c", ans[i], (" \n")[i==N]);
}
