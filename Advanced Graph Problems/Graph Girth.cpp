#include <bits/stdc++.h>

using namespace std;
const int maxN = 2501;

bool vis[maxN];
int N, M, best, p[maxN], dist[maxN];
vector<int> G[maxN];

void reset(){
    fill(vis+1, vis+N+1, false);
    fill(dist+1, dist+N+1, 0);
    fill(p+1, p+N+1, 0);
}

void bfs(int start){
    queue<int> Q;
    Q.push(start);
    vis[start] = true;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int v : G[u]){
            if(!vis[v]){
                dist[v] = dist[u]+1;
                vis[v] = true;
                p[v] = u;
                Q.push(v);
            } else if(v != u[p]){
                best = min(best, dist[u]+dist[v]+1);
            }
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

    best = N+1;
    for(int start = 1; start <= N; start++){
        reset();
        bfs(start);
    }

    printf("%d\n", best == N+1 ? -1 : best);
}