#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, M, a, b, p[maxN], ds[maxN];
vector<int> ans, G[maxN];

void dfs(int u){
    for(int v : G[u]){
        if(v != p[u]){
            p[v] = u;
            dfs(v);
        }
    }
}

int find(int u){
    if(ds[u] < 0)   return u;
    ds[u] = find(ds[u]);
    return ds[u];
}

bool merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v)  return false;
    if(ds[u] < ds[v])   swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}

int main(){
    scanf("%d %d", &N, &M);
    fill(ds+1, ds+N+1, -1);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        if(!merge(a, b)){
            dfs(a);

            int u = b;
            while(u != 0){
                ans.push_back(u);
                u = p[u];
            }

            int K = ans.size();
            printf("%d\n", K+1);
            for(int j = 0; j < K; j++)
                printf("%d ", ans[j]);
            printf("%d\n", b);

            return 0;
        } else {
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }
    printf("IMPOSSIBLE\n");
}
