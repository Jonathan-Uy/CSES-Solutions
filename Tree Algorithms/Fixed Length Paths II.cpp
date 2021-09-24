#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;

int N, A, B, deepest, sz[maxN];
bool vis[maxN];
ll ans, ds[maxN];
vector<int> G[maxN];

void update(int idx, ll val){
    for(int i = idx+1; i <= N; i += -i&i) ds[i] += val;
}

ll query(int idx){
    ll res = 0;
    for(int i = idx+1; i > 0; i -= -i&i)
        res += ds[i];
    return res;
}

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
    if(d > B)   return;

    deepest = max(deepest, d);
    if(t)   update(d, 1);
    else {
        ans += query(B-d);
        ans -= query(max(0, A-d)-1);
    }

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
    for(int i = 1; i <= deepest; i++)
        update(i, -query(i)+query(i-1));

    for(int v : G[c])
        if(!vis[v])
            solve(v);
}

int main(){
    scanf("%d %d %d", &N, &A, &B);
    for(int i = 0, a, b; i < N-1; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    update(0, 1);
    solve();
    printf("%lld\n", ans);
}