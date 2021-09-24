#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll> edge;
typedef pair<ll,int> node;
const int maxN = 1e5+1;
const ll INF = 0x3f3f3f3f3f3f3f3f;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> distrib((ll) 1e9, (ll) 2e9);
const ll MOD1 = distrib(rng);
const ll MOD2 = distrib(rng);

int N, M;
ll dist[2][maxN], ways[2][2][maxN];
vector<edge> G[2][maxN];
vector<int> ans;

void init(){
    for(int t = 0; t < 2; t++)
        for(int i = 1; i <= N; i++)
            dist[t][i] = INF;
}

void dijkstra(int type, int source){
    priority_queue<node, vector<node>, greater<node>> Q;
    dist[type][source] = 0;
    ways[type][0][source] = 1;
    ways[type][1][source] = 1;
    Q.push({0, source});
    while(!Q.empty()){
        int u = Q.top().second;
        ll d = Q.top().first;
        Q.pop();

        if(d > dist[type][u])   continue;
        for(edge e : G[type][u]){
            int v = e.first;
            ll w = e.second;
            if(dist[type][v] > d+w){
                ways[type][0][v] = ways[type][0][u];
                ways[type][1][v] = ways[type][1][u];
                dist[type][v] = d+w;
                Q.push({d+w, v});
            } else if(dist[type][v] == d+w){
                ways[type][0][v] += ways[type][0][u];
                ways[type][0][v] %= MOD1;
                ways[type][1][v] += ways[type][1][u];
                ways[type][1][v] %= MOD2;
            }
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b, c; i < M; i++){
        scanf("%d %d %d", &a, &b, &c);
        G[0][a].push_back({b, c});
        G[1][b].push_back({a, c});
    }
    init();
    dijkstra(0, 1);
    dijkstra(1, N);

    ll tot1 = ways[0][0][N], tot2 = ways[0][1][N];
    for(int u = 1; u <= N; u++){
        ll ways1 = ways[0][0][u] * ways[1][0][u] % MOD1;
        ll ways2 = ways[0][1][u] * ways[1][1][u] % MOD2;
        if(ways1 == tot1 && ways2 == tot2 && dist[0][u] + dist[1][u] == dist[0][N])
            ans.push_back(u);
    }

    int K = (int) ans.size();
    printf("%d\n", K);
    for(int i = 0; i < K; i++)
        printf("%d%c", ans[i], (" \n")[i==K-1]);
}