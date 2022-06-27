#include <bits/stdc++.h>

using namespace std;
const int maxN = 501, maxM = 1001;
const int INF = 0x3f3f3f3f;

int N, M, K, p[maxN], d[maxN];
bool inq[maxN], vis[maxM];
vector<int> path, G[maxN];

struct Edge {
    int u, v, r, c;
} edges[maxM], redges[maxM];

void bellman_ford(){
    fill(inq+1, inq+N+1, false);
    fill(d+1, d+N+1, INF);
    fill(p+1, p+N+1, 0);

    queue<int> Q;
    Q.push(1);
    d[1] = 0;
    inq[1] = true;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        inq[u] = false;

        for(int i : G[u]){
            Edge e = (i < 0 ? redges[-i] : edges[i]);
            if(e.r > 0 && d[e.v] > d[u] + e.c){
                d[e.v] = d[u] + e.c;
                p[e.v] = i;
                if(!inq[e.v]){
                    inq[e.v] = true;
                    Q.push(e.v);
                }
            }
        }
    }
}

int minimum_cost_flow(){
    int flow = 0, cost = 0;
    while(flow < K){
        bellman_ford();
        if(d[N] == INF) break;

        int aug = K-flow;
        int u = N;
        while(u != 1){
            Edge e = (p[u] < 0 ? redges[-p[u]] : edges[p[u]]);
            aug = min(aug, e.r);
            u = e.u;
        }

        flow += aug;
        cost += aug * d[N];
        u = N;
        while(u != 1){
            if(p[u] < 0){
                redges[-p[u]].r -= aug;
                edges[-p[u]].r += aug;
            } else {
                redges[p[u]].r += aug;
                edges[p[u]].r -= aug;
            }
            u = (p[u] < 0 ? redges[-p[u]].u : edges[p[u]].u);
        }
    }
    return (flow < K ? -1 : cost);
}

void dfs(int u = 1){
    path.push_back(u);
    if(u == N)  return;
    for(int i : G[u]){
        if(i > 0 && edges[i].r == 0 && !vis[i]){
            vis[i] = true;
            dfs(edges[i].v);
            return;
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 1, u, v; i <= M; i++){
        scanf("%d %d", &u, &v);
        G[u].push_back(i);
        G[v].push_back(-i);
        edges[i] = {u, v, 1, 1};
        redges[i] = {v, u, 0, -1};
    }

    int minCoins = minimum_cost_flow();
    if(minCoins == -1){
        printf("-1\n");
        return 0;
    }

    printf("%d\n", minCoins);
    for(int i = 0; i < K; i++){
        path.clear();
        dfs();

        int sz = (int) path.size();
        printf("%d\n", sz);
        for(int j = 0; j < sz; j++)
            printf("%d%c", path[j], (" \n")[j==sz-1]);
    }
}