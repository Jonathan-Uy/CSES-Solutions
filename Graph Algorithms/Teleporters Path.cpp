#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

bool vis[maxN];
int N, M, in[maxN];
vector<int> tour, G[maxN];
stack<int> S;

void dfs(int u = 1, int p = -1){
    vis[u] = true;
    for(int v : G[u])
        if(v != p && !vis[v])
            dfs(v, u);
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        in[b]++;
    }

    dfs();
    bool exists = vis[N];
    exists &= (in[1]+1 == (int) G[1].size());
    exists &= (in[N]-1 == (int) G[N].size());
    for(int i = 2; i < N; i++){
        exists &= (in[i] == (int) G[i].size());
        if(!vis[i]) exists &= (in[i] == 0 && G[i].size() == 0);
    }

    if(!exists){
        printf("IMPOSSIBLE\n");
        return 0;
    }

    S.push(1);
    while(!S.empty()){
        int u = S.top();
        if(!G[u].empty()){
            int v = G[u].back();
            G[u].pop_back();
            S.push(v);
        } else {
            tour.push_back(u);
            S.pop();
        }
    }

    reverse(tour.begin(), tour.end());
    for(int i = 0; i < M+1; i++)
        printf("%d%c", tour[i], (" \n")[i==M]);
}