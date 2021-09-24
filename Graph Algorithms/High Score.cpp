#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2501;
const int maxM = 5001;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Edge {
    int a, b; ll c;
} edges[maxM];

int N, M;
ll dp[maxN];
bool vis[maxN], visR[maxN];
vector<int> G[maxN], GR[maxN];

void dfs(int u){
    vis[u] = true;
    for(int v : G[u])
        if(!vis[v])
            dfs(v);
}

void dfsR(int u){
    visR[u] = true;
    for(int v : GR[u])
        if(!visR[v])
            dfsR(v);
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        edges[i] = {a, b, -c};
        G[a].push_back(b);
        GR[b].push_back(a);
    }
    dfs(1); dfsR(N);

    fill(dp+2, dp+N+1, INF);
    bool improvement = true;
    for(int iter = 0; iter < N && improvement; iter++){
        improvement = false;
        for(int i = 0; i < M; i++){
            int u = edges[i].a;
            int v = edges[i].b;
            ll w = edges[i].c;

            if(dp[v] > dp[u]+w){
                dp[v] = dp[u]+w;
                improvement = true;

                if(iter == N-1 && vis[v] && visR[v]){
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }

    printf("%lld\n", -dp[N]);
}