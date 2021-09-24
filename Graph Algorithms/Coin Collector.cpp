#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e5+1;

bool vis[maxN];
int N, M, K, rt[maxN];
ll k[maxN], ck[maxN], dp[maxN];
vector<int> ord, comp, G[maxN], GR[maxN], SCC[maxN];

void dfs1(int u){
    vis[u] = true;
    for(int v : G[u])
        if(!vis[v])
            dfs1(v);
    ord.push_back(u);
}

void dfs2(int u){
    vis[u] = true;
    comp.push_back(u);
    for(int v : GR[u])
        if(!vis[v])
            dfs2(v);
}

void dfs3(int u){
    vis[u] = true;
    dp[u] = ck[u];
    for(int v : SCC[u]){
        if(!vis[v])
            dfs3(v);
        dp[u] = max(dp[u], dp[v]+ck[u]);
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        scanf("%d", &k[i]);

    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        GR[b].push_back(a);
    }

    for(int i = 1; i <= N; i++)
        if(!vis[i])
            dfs1(i);

    fill(vis+1, vis+N+1, false);
    reverse(ord.begin(), ord.end());
    for(int u : ord){
        if(!vis[u]){
            dfs2(u);
            K++;
            for(int v : comp){
                ck[K] += k[v];
                rt[v] = K;
            }
            comp.clear();
        }
    }

    for(int u = 1; u <= N; u++)
        for(int v : G[u])
            if(rt[v] != rt[u])
                SCC[rt[u]].push_back(rt[v]);

    fill(vis+1, vis+K+1, false);
    for(int i = 1; i <= K; i++)
        if(!vis[i])
            dfs3(i);

    ll best = 0;
    for(int i = 1; i <= K; i++)
        best = max(best, dp[i]);
    printf("%lld\n", best);
}