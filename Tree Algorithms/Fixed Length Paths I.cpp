#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;

int N, K, deepest, sz[maxN], cnt[maxN];
bool vis[maxN];
ll ans;
vector<int> G[maxN];

int getSize(int u = 1, int p = -1){
    sz[u] = 1;
    for(int v : G[u])
        if(v != p && !vis[v])
            sz[u] += getSize(v, u);

    return sz[u];
}

int centroid(int u, int p, int n){
    for(int v : G[u])
        if(v != p && !vis[v] && sz[v] > n/2)
            return centroid(v, u, n);

    return u;
}

void dfs(int u, int p, bool t, int d = 1){
    if(d > K)   return;

    deepest = max(deepest, d);
    if(t)       cnt[d]++;
    else        ans += cnt[K-d];

    for(int v : G[u])
        if(v != p && !vis[v])
            dfs(v, u, t, d+1);
}

void solve(int u = 1){
    int c = centroid(u, -1, getSize(u));
    vis[c] = true;
    deepest = 0;

    for(int v : G[c]){
        if(!vis[v]){
            dfs(v, c, false);
            dfs(v, c, true);
        }
    }
    fill(cnt+1, cnt+deepest+1, 0);

    for(int v : G[c])
        if(!vis[v])
            solve(v);
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0, a, b; i < N-1; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    cnt[0] = 1;
    solve();
    printf("%lld\n", ans);
}