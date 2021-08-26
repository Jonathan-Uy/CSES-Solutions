#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e5+1;
const ll MOD = 1e9+7;

int N, M, cnt, ds[maxN];

ll pow2(int x){
    ll res = 1, a = 2;
    while(x){
        if(x&1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        x >>= 1;
    }
    return res;
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
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        if(!merge(a, b))    cnt++;
    }
    printf("%lld\n", pow2(cnt));
}