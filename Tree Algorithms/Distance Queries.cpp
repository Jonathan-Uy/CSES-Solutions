#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;
const int logN = 20;

int N, Q, a, b, p[maxN][logN];
int timer, d[maxN], in[maxN], out[maxN];
vector<int> G[maxN];

void dfs(int u = 1, int par = 1){
    in[u] = ++timer;
    d[u] = d[par]+1;
    p[u][0] = par;
    for(int i = 1; i < logN; i++)
        p[u][i] = p[p[u][i-1]][i-1];
    for(int v : G[u])
        if(v != par)
            dfs(v, u);
    out[u] = ++timer;
}

bool ancestor(int u, int v){
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v){
    if(ancestor(u, v))  return u;
    if(ancestor(v, u))  return v;
    for(int i = logN-1; i >= 0; i--)
        if(!ancestor(p[u][i], v))
            u = p[u][i];
    return p[u][0];
}

int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 0; i < N-1; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs();

    for(int q = 0; q < Q; q++){
        scanf("%d %d", &a, &b);
        printf("%d\n", d[a] + d[b] - 2*d[lca(a, b)]);
    }
}
