#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;
const int MOD = 1e9+7;

int N, M, ans, ds[maxN];

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
    ans = 1;
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        if(!merge(a, b))
            ans = (2 * ans) % MOD;
    }
    printf("%d\n", ans);
}