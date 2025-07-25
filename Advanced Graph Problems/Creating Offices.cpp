#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1, logN = 20;
const int INF = 0x3f3f3f3f;

int N, D, ct[maxN], sz[maxN], best[maxN];
int timer, p[maxN][logN], d[maxN], in[maxN], out[maxN];
bool vis[maxN];
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

int dist(int u, int v){
    return d[u] + d[v] - 2*d[lca(u, v)];
}

int find_size(int u, int p = -1){
    if(vis[u])  return 0;

    sz[u] = 1;
    for(int v : G[u])
        if(v != p)
            sz[u] += find_size(v, u);

    return sz[u];
}

int find_centroid(int u, int p, int n){
    for(int v : G[u])
        if(v != p)
            if(!vis[v] && sz[v] > n/2)
                return find_centroid(v, u, n);

    return u;
}

void build_centroid_tree(int u = 1, int p = -1){
    find_size(u);

    int c = find_centroid(u, -1, sz[u]);
    vis[c] = true;
    ct[c] = p;

    for(int v : G[c])
        if(!vis[v])
            build_centroid_tree(v, c);
}

void update(int u){
    best[u] = 0;
    int v = u;
    while(ct[v] != -1){
        v = ct[v];
        best[v] = min(best[v], dist(u, v));
    }
}

int query(int u){
    int ans = best[u];
    int v = u;
    while(ct[v] != -1){
        v = ct[v];
        ans = min(ans, best[v] + dist(u, v));
    }
    return ans;
}

int main(){
    scanf("%d %d", &N, &D);
    for(int i = 0, a, b; i < N-1; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs();
    build_centroid_tree();
    fill(best+1, best+N+1, INF);

    vector<int> order(N);
    for(int i = 0; i < N; i++)
        order[i] = i+1;
    sort(order.begin(), order.end(), [](int a, int b){
        return d[a] == d[b] ? a < b : d[a] > d[b];
    });

    vector<int> ans;
    for(int u : order){
        int dist_to_office = query(u);
        if(dist_to_office >= D){
            ans.push_back(u);
            update(u);
        }
    }

    sort(ans.begin(), ans.end());
    int K = (int) ans.size();
    printf("%d\n", K);
    for(int i = 0; i < K; i++)
        printf("%d%c", ans[i], (" \n")[i==K-1]);
}