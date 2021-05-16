#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, M, K, a, b, p[maxN], dist[maxN];
bool vis[maxN];
vector<int> G[maxN];
queue<int> Q;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    Q.push(1);
    vis[1] = true;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int v : G[u]){
            if(!vis[v]){
                dist[v] = dist[u]+1;
                vis[v] = true;
                p[v] = u;
                Q.push(v);
            }
        }
    }

    if(!vis[N]){
        printf("IMPOSSIBLE\n");
        return 0;
    }

    int u = N;
    K = dist[N];
    vector<int> ans(K+1);
    for(int i = K; i >= 0; i--){
        ans[i] = u;
        u = p[u];
    }

    printf("%d\n", K+1);
    for(int i = 0; i <= K; i++)
        printf("%d%c", ans[i], (" \n")[i==K]);
}
