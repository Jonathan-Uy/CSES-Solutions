#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int,3> edge;
const int maxN = 2e5+1;

int N, ds[maxN];
ll ans;
vector<edge> edges;

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
    scanf("%d", &N);
    for(int i = 0, a, b, x; i < N-1; i++){
        scanf("%d %d %d", &a, &b, &x);
        edges.push_back({a, b, x});
    }

    sort(edges.begin(), edges.end(), [](const edge& e1, const edge& e2){
        return e1[2] > e2[2];
    });

    fill(ds, ds+N, -1);
    for(const edge& e: edges){
        int a = find(e[0]), b = find(e[1]);
        int sza = -ds[a], szb = -ds[b];

        ll x = e[2];
        ans += x * sza * szb;
        merge(a, b);
    }
    printf("%lld\n", ans);
}