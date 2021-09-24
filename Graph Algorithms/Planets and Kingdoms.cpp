#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

bool vis[maxN];
int N, M, rt[maxN];
vector<int> ord, comp, G[maxN], GR[maxN];

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

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        GR[b].push_back(a);
    }

    for(int i = 1; i <= N; i++)
        if(!vis[i])
            dfs1(i);

    int K = 0;
    fill(vis+1, vis+N+1, false);
    reverse(ord.begin(), ord.end());
    for(int u : ord){
        if(!vis[u]){
            dfs2(u);
            K++;
            for(int v : comp)
                rt[v] = K;
            comp.clear();
        }
    }

    printf("%d\n", K);
    for(int i = 1; i <= N; i++)
        printf("%d%c", rt[i], (" \n")[i==N]);
}