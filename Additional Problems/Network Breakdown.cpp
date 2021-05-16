#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;
const int maxM = 2e5;
typedef pair<int,int> pii;

int N, M, K, a, b, cnt, ds[maxN], ans[maxM];
pii edges[maxM], queries[maxM];
set<pii> S;

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
    scanf("%d %d %d", &N, &M, &K);
    fill(ds+1, ds+N+1, -1);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        if(b > a)   swap(a, b);
        edges[i] = {a, b};
    }
    for(int i = 0; i < K; i++){
        scanf("%d %d", &a, &b);
        if(b > a)   swap(a, b);
        queries[i] = {a, b};
        S.insert({a, b});
    }

    cnt = N;
    for(int i = 0; i < M; i++)
        if(S.find(edges[i]) == S.end())
            if(merge(edges[i].first, edges[i].second))
                cnt--;

    for(int i = K-1; i >= 0; i--){
        ans[i] = cnt;
        if(merge(queries[i].first, queries[i].second))
            cnt--;
    }

    for(int i = 0; i < K; i++)
        printf("%d%c", ans[i], (" \n")[i==K-1]);
}
