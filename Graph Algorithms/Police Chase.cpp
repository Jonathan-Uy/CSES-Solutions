#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 501;
const int INF = 0x3f3f3f3f;

int N, M, p[maxN], cap[maxN][maxN];
bool vis[maxN];
vector<int> G[maxN];

int bfs(int s = 1, int t = N){
    fill(p+1, p+N+1, -1);
    p[s] = -2;

    queue<pii> Q;
    Q.push({s, INF});
    while(!Q.empty()){
        int u = Q.front().first;
        int f = Q.front().second;
        Q.pop();

        for(int v : G[u]){
            if(p[v] == -1 && cap[u][v]){
                p[v] = u;
                int aug = min(f, cap[u][v]);
                if(v == t)  return aug;
                Q.push({v, aug});
            }
        }
    }

    return 0;
}

void dfs(int u = 1){
    vis[u] = true;
    for(int v : G[u])
        if(!vis[v] && cap[u][v])
            dfs(v);
}

int maxflow(int s = 1, int t = N){
    int flow = 0, aug = 0;
    while(aug = bfs()){
        flow += aug;
        int u = t;
        while(u != s){
            int v = p[u];
            cap[v][u] -= aug;
            cap[u][v] += aug;
            u = v;
        }
    }
    return flow;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
        cap[a][b]++;
        cap[b][a]++;
    }
    printf("%d\n", maxflow());

    dfs();
    for(int u = 1; u <= N; u++){
        if(!vis[u]) continue;
        for(int v : G[u])
            if(!vis[v])
                printf("%d %d\n", u, v);
    }
}