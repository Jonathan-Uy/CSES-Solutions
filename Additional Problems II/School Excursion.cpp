#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, M, a, b, ds[maxN];
multiset<int> sizes;
bitset<maxN> dp;

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
        merge(a, b);
    }

    for(int i = 1; i <= N; i++)
        if(find(i) == i)
            sizes.insert(-ds[i]);

    dp[0] = 1;
    for(int sz : sizes)
        dp |= (dp<<sz);

    for(int i = 1; i <= N; i++)
        printf("%d", dp[i] ? 1 : 0);
    printf("\n");
}
