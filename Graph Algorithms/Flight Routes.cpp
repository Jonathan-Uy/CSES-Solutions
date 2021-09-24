#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,ll> edge;
typedef pair<ll,int> node;
const int maxN = 2e5+1;

int N, M, K, cnt[maxN];
vector<edge> G[maxN];
priority_queue<node, vector<node>, greater<node>> Q;

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0, a, b, c; i < M; i++){
        scanf("%d %d %d", &a, &b, &c);
        G[a].push_back({b, c});
    }

    Q.push({0, 1});
    while(!Q.empty()){
        ll d = get<0>(Q.top());
        int u = get<1>(Q.top());
        Q.pop();

        cnt[u]++;
        if(u == N){
            printf("%lld%c", d, (" \n")[cnt[u]==K]);
            if(cnt[u] == K) return 0;
        }

        if(cnt[u] <= K){
            for(edge e : G[u]){
                int v = e.first;
                ll w = e.second;
                Q.push({d+w, v});
            }
        }
    }
}
