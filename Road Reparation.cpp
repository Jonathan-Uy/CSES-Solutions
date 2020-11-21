#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
typedef pair<int,int> pii;
typedef pair<int,pii> edge;

int N, M, a, b, c, ds[100001];
long long sum;
edge edges[200000];

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
    for(int i = 1; i <= N; i++) ds[i] = -1;
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &a, &b, &c);
        edges[i] = {c, {a, b}};
    }
    sort(edges, edges+M);
    
    for(int i = 0; i < M; i++){
        edge e = edges[i];
        if(merge(e.s.f, e.s.s)){
            sum += e.f;
            N--;
        }
    }
    
    if(N == 1)  printf("%lld\n", sum);
    else        printf("IMPOSSIBLE\n");
}
