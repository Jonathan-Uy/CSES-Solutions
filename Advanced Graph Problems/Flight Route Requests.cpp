#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, M, ds[maxN], vis[maxN];
vector<int> G[maxN], CC[maxN];

int find(int u){
    if(ds[u] < 0)   return u;
    ds[u] = find(ds[u]);
    return ds[u];
}

bool merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v)  return false;
    if(ds[u] < ds[v])   swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}

bool dfs(int u){
    vis[u] = -1;
    bool hascycle = false;
    for(int v : G[u]){
        if(vis[v] == -1)        return true;
        else if(vis[v] == 0)    hascycle |= dfs(v);
    }
    vis[u] = 1;
    return hascycle;
}

int main(){
    scanf("%d %d", &N, &M);

    fill(ds+1, ds+N+1, -1);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        merge(a, b);
    }

    int K = 0;
    unordered_map<int,int> getID;
    for(int u = 1; u <= N; u++){
        int rep = find(u);
        if(!getID[rep])
            getID[rep] = ++K;
        CC[getID[rep]].push_back(u);
    }

    int ans = 0;
    for(int k = 1; k <= K; k++){
        int sz = (int) CC[k].size();
        bool hascycle = false;
        for(int u : CC[k])
            if(!hascycle && vis[u] == 0)
                hascycle |= dfs(u);
        ans += (hascycle ? sz : sz-1);
    }
    printf("%d\n", ans);
}