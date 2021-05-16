#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll> edge;
typedef tuple<ll,int,int> node;
const int maxN = 2e5+1;

int N, M, a, b;
ll c, dist[2][maxN];
vector<edge> G[maxN];
priority_queue<node, vector<node>, greater<node>> Q;

int main(){
    scanf("%d %d", &N, &M);
    memset(dist, 0x3f, sizeof(dist));
    for(int i = 0; i < M; i++){
        scanf("%d %d %lld", &a, &b, &c);
        G[a].push_back({b, c});
    }

    dist[0][1] = dist[1][1] = 0;
    Q.push({0, 1, 1});
    while(!Q.empty()){
        ll d = get<0>(Q.top());
        int u = get<1>(Q.top());
        int coupon = get<2>(Q.top());
        Q.pop();

        if(dist[!coupon][u] < d)    continue;

        for(edge e : G[u]){
            int v = e.first;
            ll w = e.second;

            if(coupon){
                if(dist[0][v] > d + w){
                    dist[0][v] = d + w;
                    Q.push({d+w, v, 1});
                }
                if(dist[1][v] > d + w/2){
                    dist[1][v] = d + w/2;
                    Q.push({d+w/2, v, 0});
                }
            } else {
                if(dist[1][v] > d + w){
                    dist[1][v] = d + w;
                    Q.push({d+w, v, 0});
                }
            }
        }
    }

    printf("%lld\n", min(dist[0][N], dist[1][N]));
}
