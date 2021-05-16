#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll> edge;
typedef pair<ll,int> node;
const int maxN = 1e5+1;
const ll MOD = 1e9+7;
const ll INF = 0x3f3f3f3f3f3f;

int N, M, a, b, minR[maxN], maxR[maxN];
ll c, dist[maxN], ways[maxN];
vector<edge> G[maxN];

struct Comparator {
    bool operator() (int x, int y) const {
        return dist[x] == dist[y] ? x < y : dist[x] < dist[y];
    }
};
set<int, Comparator> PQ;

int main(){
    scanf("%d %d", &N, &M);
    memset(dist, 0x3f, sizeof(dist));
    for(int i = 0; i < M; i++){
        scanf("%d %d %lld", &a, &b, &c);
        G[a].push_back({b, c});
    }

    PQ.insert(1);
    ways[1] = 1;
    dist[1] = 0;
    while(!PQ.empty()){
        int u = *PQ.begin();
        ll d = dist[u];
        PQ.erase(PQ.begin());

        for(edge e : G[u]){
            int v = e.first;
            ll w = e.second;
            if(d + w <= dist[v]){
                if(dist[v] != INF)  PQ.erase(v);
                if(d + w == dist[v]){
                    ways[v] = (ways[u] + ways[v]) % MOD;
                    minR[v] = min(minR[v], minR[u]+1);
                    maxR[v] = max(maxR[v], maxR[u]+1);
                }
                if(d + w < dist[v]){
                    dist[v] = d+w;
                    ways[v] = ways[u];
                    minR[v] = minR[u]+1;
                    maxR[v] = maxR[u]+1;
                }
                PQ.insert(v);
            }
        }
    }

    printf("%lld %lld %d %d\n", dist[N], ways[N], minR[N], maxR[N]);
}
