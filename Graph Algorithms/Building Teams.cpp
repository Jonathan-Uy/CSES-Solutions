#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, M, a, b;
bool possible, vis[maxN], team[maxN];
vector<int> G[maxN];

void dfs(int u, int p = 0){
    for(int v : G[u]){
        if(v != p){
            if(!vis[v]){
                team[v] = !team[u];
                vis[v] = true;
                dfs(v, u);
            } else
                if(team[v] == team[u])
                    possible = false;
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    possible = true;
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            vis[i] = true;
            dfs(i);
        }
    }

    if(!possible)
        printf("IMPOSSIBLE\n");
    else
        for(int i = 1; i <= N; i++)
            printf("%d%c", (team[i] ? 1 : 2), (" \n")[i==N]);
}
