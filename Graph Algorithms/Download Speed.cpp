#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll> pil;
const int maxN = 501;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int N, M, p[maxN];
ll cap[maxN][maxN];
vector<int> G[maxN];

ll bfs(int s = 1, int t = N){
    fill(p+1, p+N+1, -1);
    p[s] = -2;

    queue<pil> Q;
    Q.push({s, INF});
    while(!Q.empty()){
        int u = Q.front().first;
        ll f = Q.front().second;
        Q.pop();

        for(int v : G[u]){
            if(p[v] == -1 && cap[u][v]){
                p[v] = u;
                ll aug = min(f, cap[u][v]);
                if(v == t)  return aug;
                Q.push({v, aug});
            }
        }
    }

    return 0;
}

ll maxflow(int s = 1, int t = N){
    ll flow = 0, aug = 0;
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
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        G[a].push_back(b);
        G[b].push_back(a);
        cap[a][b] += c;
    }
    printf("%lld\n", maxflow());
}