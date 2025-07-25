#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1, SIZE = 4*maxN;
const int INF = 0x3f3f3f3f;

int N, lo[SIZE], hi[SIZE], delta[SIZE], mx[SIZE], mn[SIZE];

void push(int i){
    if(delta[i] != 0){
        delta[2*i] += delta[i];
        delta[2*i+1] += delta[i];
        delta[i] = 0;
    }
}

void pull(int i){
    mn[i] = min(mn[2*i]+delta[2*i], mn[2*i+1]+delta[2*i+1]);
    mx[i] = max(mx[2*i]+delta[2*i], mx[2*i+1]+delta[2*i+1]);
}

void init(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r)  return;
    int m = l+(r-l)/2;
    init(2*i, l, m);
    init(2*i+1, m+1, r);
    pull(i);
}

void increment(int i, int l, int r, int v){
    if(l > hi[i] || r < lo[i])  return;
    if(l <= lo[i] && hi[i] <= r){
        delta[i] += v; return;
    }

    push(i);
    increment(2*i, l, r, v);
    increment(2*i+1, l, r, v);
    pull(i);
}

int minimum(int i, int l, int r){
    if(l > hi[i] || r < lo[i])      return INF;
    if(l <= lo[i] && hi[i] <= r)    return mn[i]+delta[i];

    push(i);
    int lmin = minimum(2*i, l, r);
    int rmin = minimum(2*i+1, l, r);
    pull(i);

    return min(lmin, rmin);
}

int maximum(int i, int l, int r){
    if(l > hi[i] || r < lo[i])      return -INF;
    if(l <= lo[i] && hi[i] <= r)    return mx[i]+delta[i];

    push(i);
    int lmax = maximum(2*i, l, r);
    int rmax = maximum(2*i+1, l, r);
    pull(i);

    return max(lmax, rmax);
}

void place_coin(int c, int s){
    int v = (s == 1 ? -1 : 1);
    increment(1, 1, c, v);
}

char query_stacks(){
    int totmin = minimum(1, 1, N);
    int totmax = maximum(1, 1, N);
    if(totmin >= 0 && totmax <= 0)  return '?';
    else if(totmin >= 0)            return '<';
    else if(totmax <= 0)            return '>';
    else                            return '?';
}

int main(){
    scanf("%d", &N);
    init(1, 1, N);
    for(int i = 0, c, s; i < N; i++){
        scanf("%d %d", &c, &s);
        place_coin(c, s);
        printf("%c\n", query_stacks());
    }
}