#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 501, maxM = 1001;
const int INF = 0x3f3f3f3f;

int N, M, p[maxN], cap[maxN][maxN];
bool vis[maxM];
vector<int> path, F[maxN];
vector<pii> G[maxN];

int bfs(int s = 1, int t = N){
    fill(p+1, p+N+1, -1);
    p[s] = -2;

    queue<pii> Q;
    Q.push({s, INF});
    while(!Q.empty()){
        int u = Q.front().first;
        int f = Q.front().second;
        Q.pop();

        for(int v : F[u]){
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
    path.push_back(u);
    if(u == N)  return;
    for(pii e : G[u]){
        int v = e.first;
        int id = e.second;
        if(cap[u][v] == 0 && !vis[id]){
            vis[id] = true;
            dfs(v);
            return;
        }
    }
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
        G[a].push_back({b, i});
        F[a].push_back(b);
        F[b].push_back(a);
        cap[a][b]++;
    }

    int K = maxflow();
    printf("%d\n", K);
    for(int k = 0; k < K; k++){
        path.clear();

        dfs();
        int sz = (int) path.size();
        printf("%d\n", sz);
        for(int i = 0; i < sz; i++)
            printf("%d%c", path[i], (" \n")[i==sz-1]);
    }
}