#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 1e5+5, maxM = 2e5+5;

int N, M, timer, in[maxN];
bool even[maxN];
vector<pii> G[maxN];
pii ans[maxM];

void dfs(int u, int p = -1){
    in[u] = ++timer;
    for(pii e : G[u]){
        int v = e.first, id = e.second;
        if(v != p){
            if(!in[v]){
                dfs(v, u);
                if(even[v]){
                    ans[id] = {u, v};
                    even[u] ^= true;
                } else {
                    ans[id] = {v, u};
                    even[v] ^= true;
                }
            } else if(in[v] < in[u]){
                even[u] ^= true;
                ans[id] = {u, v};
            }
        }
    }
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }

    fill(even+1, even+N+1, true);
    for(int i = 1; i <= N; i++)
        if(!in[i])
            dfs(i);

    bool good = true;
    for(int i = 1; i <= N; i++)
        good &= even[i];

    if(good){
        for(int i = 0; i < M; i++)
            printf("%d %d\n", ans[i].first, ans[i].second);
    } else printf("IMPOSSIBLE\n");
}