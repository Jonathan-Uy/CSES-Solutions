#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 1e5+1;
const int maxM = 2e5+1;

int N, M, timer, tin[maxN], low[maxN];
bool bridge_exists, vis[maxN], used[maxM];
vector<pii> G[maxN];
pii edges[maxM];

void dfs(int u = 1, int p = 0){
    vis[u] = true;
    tin[u] = low[u] = ++timer;
    for(pii P : G[u]){
        int v = P.first;
        int id = P.second;
        if(used[id])    continue;

        used[id] = true;
        edges[id] = {u, v};

        if(vis[v]){
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u])
                bridge_exists = true;
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }

    dfs();
    if(timer == N && !bridge_exists){
        for(int i  = 0; i < M; i++)
            printf("%d %d\n", edges[i].first, edges[i].second);
    } else printf("IMPOSSIBLE\n");
}
