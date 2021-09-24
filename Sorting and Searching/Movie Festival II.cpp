#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5, SIZE = 5e6;
const int INF = 0x3f3f3f3f;

int N, K, ans, A[maxN], B[maxN], lo[SIZE], hi[SIZE], d[SIZE], mx[SIZE];
struct Movie { int t, id, type; } movies[2*maxN];
map<int,int> mp;

void push(int i){
    if(d[i]){
        d[2*i] += d[i];
        d[2*i+1] += d[i];
        d[i] = 0;
    }
}

void pull(int i){
    mx[i] = max(mx[2*i]+d[2*i], mx[2*i+1]+d[2*i+1]);
}

void init(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r)  return;
    int m = l+(r-l)/2;
    init(2*i, l, m);
    init(2*i+1, m+1, r);
    pull(i);
}

void increment(int i, int l, int r){
    if(l > hi[i] || r < lo[i])  return;
    if(l <= lo[i] && hi[i] <= r){
        d[i]++; return;
    }
    push(i);
    increment(2*i, l, r);
    increment(2*i+1, l, r);
    pull(i);
}

int maximum(int i, int l, int r){
    if(l > hi[i] || r < lo[i])      return -INF;
    if(l <= lo[i] && hi[i] <= r)    return mx[i]+d[i];

    push(i);
    int lmax = maximum(2*i, l, r);
    int rmax = maximum(2*i+1, l, r);
    pull(i);

    return max(lmax, rmax);
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &A[i], &B[i]);
        movies[2*i] = {A[i], i, 0};
        movies[2*i+1] = {B[i], i, 1};
    }
    sort(movies, movies+2*N, [](Movie a, Movie b){
        return a.t == b.t ? A[a.id] > A[b.id] : a.t < b.t;
    });

    for(int i = 0; i < 2*N; i++)
        mp[movies[i].t] = i+1;

    init(1, 1, 2*N);
    for(int i = 0; i < 2*N; i++){
        if(movies[i].type == 1){
            int id = movies[i].id;
            int a = mp[A[id]];
            int b = mp[B[id]];

            if(maximum(1, a+1, b) < K){
                increment(1, a, b);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}