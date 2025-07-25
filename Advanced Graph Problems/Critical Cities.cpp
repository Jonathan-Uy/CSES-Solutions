#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, M, p[maxN], sdom[maxN], idom[maxN], label[maxN];
int timer, tin[maxN], inv[maxN], dsu[maxN];
vector<int> ans, G[maxN], GR[maxN], DT[maxN], bucket[maxN];

void dfs(int u = 1){
    tin[u] = ++timer;
    inv[timer] = u;
    label[timer] = sdom[timer] = dsu[timer] = timer;
    for(int v : G[u]){
        if(!tin[v]){
            dfs(v);
            p[tin[v]] = tin[u];
        }
        GR[tin[v]].push_back(tin[u]);
    }
}

int find(int u, bool x = false){
    if(u == dsu[u]) return x ? -1 : u;
    int v = find(dsu[u], true);
    if(v < 0)   return u;

    if(sdom[label[dsu[u]]] < sdom[label[u]])
        label[u] = label[dsu[u]];

    dsu[u] = v;
    return x ? v : label[u];
}

void build_dominator_tree(){
    dfs();

    for(int u = N; u > 0; u--){
        for(int v : GR[u])
            sdom[u] = min(sdom[u], sdom[find(v)]);
        if(u > 1)   bucket[sdom[u]].push_back(u);
        for(int v : bucket[u])
            idom[v] = (sdom[find(v)] == sdom[v] ? sdom[v] : find(v));
        if(u > 1)   dsu[u] = p[u];
    }

    for(int u = 2; u <= N; u++){
        if(idom[u] != sdom[u])
            idom[u] = idom[idom[u]];
        DT[inv[u]].push_back(inv[idom[u]]);
        DT[inv[idom[u]]].push_back(inv[u]);
    }
}

bool dfs_dominator_tree(int u = 1, int p = -1){
    bool good = (u == N);
    for(int v : DT[u])
        if(v != p)
            good |= dfs_dominator_tree(v, u);
    if(good)    ans.push_back(u);
    return good;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
    }

    build_dominator_tree();
    dfs_dominator_tree();

    sort(ans.begin(), ans.end());
    int K = (int) ans.size();
    printf("%d\n", K);
    for(int i = 0; i < K; i++)
        printf("%d%c", ans[i], (" \n")[i==K-1]);
}