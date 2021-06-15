#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 1e5+1;

bool vis[maxN], is_artic[maxN];
int N, M, timer, tin[maxN], low[maxN];
vector<int> ans, G[maxN];

void dfs(int u = 1, int p = -1){
    vis[u] = true;
    tin[u] = low[u] = ++timer;

    int children = 0;
    for(int v : G[u]){
        if(v != p){
            if(vis[v])  low[u] = min(low[u], tin[v]);
            else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(low[v] >= tin[u] && p != -1){
                    if(!is_artic[u]){
                        ans.push_back(u);
                        is_artic[u] = true;
                    }
                }
                children++;
            }
        }
    }

    if(p == -1 && children > 1){
        if(!is_artic[u]){
            ans.push_back(u);
            is_artic[u] = true;
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs();

    int K = (int) ans.size();
    printf("%d\n", K);
    for(int i = 0; i < K; i++)
        printf("%d%c", ans[i], (" \n")[i==K-1]);
}