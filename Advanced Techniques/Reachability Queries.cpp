#include <bits/stdc++.h>

using namespace std;
const int maxN = 5e4+5;

bool vis[maxN];
int N, M, Q, ds[maxN];
vector<int> order, component;
vector<int> G[maxN], H[maxN], SCC[maxN];
bitset<maxN> reachable[maxN];

int find(int u){
    if(ds[u] < 0)   return u;
    ds[u] = find(ds[u]);
    return ds[u];
}

bool merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v)  return false;
    if(ds[u] < ds[v]){
        ds[u] += ds[v];
        ds[v] = u;
    } else {
        ds[v] += ds[u];
        ds[u] = v;
    }
    return true;
}

void dfs1(int u){
    vis[u] = true;
    for(int v : G[u])
        if(!vis[v])
            dfs1(v);
    order.push_back(u);
}

void dfs2(int u){
    vis[u] = true;
    component.push_back(u);
    for(int v : H[u])
        if(!vis[v])
            dfs2(v);
}

void dfs3(int u){
    vis[u] = true;
    for(int v : SCC[u]){
        if(!vis[v])
            dfs3(v);
        reachable[u] |= reachable[v];
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &Q);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        H[b].push_back(a);
    }

    fill(vis+1, vis+N+1, false);
    for(int i = 1; i <= N; i++)
        if(!vis[i])
            dfs1(i);

    fill(ds+1, ds+N+1, -1);
    fill(vis+1, vis+N+1, false);
    for(int i = 1; i <= N; i++){
        int u = order[N-i];
        if(!vis[u]){
            dfs2(u);
            for(int j = 0; j+1 < (int) component.size(); j++)
                merge(component[j], component[j+1]);
            component.clear();
        }
    }

    for(int i = 1; i <= N; i++){
        int rep = find(i);
        reachable[rep].set(i);
        for(int v : G[i])
            SCC[rep].push_back(find(v));
    }

    fill(vis+1, vis+N+1, false);
    for(int i = 1; i <= N; i++)
        if(!vis[i])
            dfs3(i);

    for(int i = 0, a, b; i < Q; i++){
        scanf("%d %d", &a, &b);
        a = find(a); b = find(b);
        printf(reachable[a][b] ? "YES\n" : "NO\n");
    }
}
