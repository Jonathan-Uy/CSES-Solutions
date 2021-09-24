#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;
const int SIZE = 4e6;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Line {
    ll m, b;
    ll operator()(const ll x) const {
        return m * x + b;
    }
} seg[SIZE];

int N, lo[SIZE], hi[SIZE];
ll X, s[maxN], f[maxN];

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    seg[i] = {0, INF};
    if(l == r)  return;
    int m = (l+r)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
}

void insert(int i, Line L){
    int l = lo[i], r = hi[i];
    if(l == r){
        if(L(l) < seg[i](l))
            seg[i] = L;
        return;
    }

    int m = (l+r)/2;
    if(seg[i].m < L.m)  swap(seg[i], L);
    if(seg[i](m) > L(m)){
        swap(seg[i], L);
        insert(2*i, L);
    } else insert(2*i+1, L);
}

ll query(int i, ll x){
    int l = lo[i], r = hi[i];
    if(l == r)  return seg[i](x);

    int m = (l+r)/2;
    if(x < m)   return min(seg[i](x), query(2*i, x));
    else        return min(seg[i](x), query(2*i+1, x));
}

int main(){
    scanf("%d %lld", &N, &X);
    for(int i = 0; i < N; i++)  scanf("%lld", &s[i]);
    for(int i = 0; i < N; i++)  scanf("%lld", &f[i]);

    build(1, 1, 1e6);
    insert(1, {X, 0});
    for(int i = 0; i < N-1; i++){
        ll best = query(1, s[i]);
        insert(1, {f[i], best});
    }
    printf("%lld\n", query(1, s[N-1]));
}