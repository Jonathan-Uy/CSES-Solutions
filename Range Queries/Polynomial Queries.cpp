#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int SIZE = 8e5;

int N, Q, t, a, b, lo[SIZE], hi[SIZE];
ll d1[SIZE], d2[SIZE], s1[SIZE], s2[SIZE];

int len(int i){
    return hi[i]-lo[i]+1;
}

ll sigma(int i){
    return ((ll) hi[i] * (hi[i]+1))/2 - ((ll) lo[i] * (lo[i]-1))/2;
}

void push(int i){
    if(d1[i]){
        d1[2*i] += d1[i];
        d1[2*i+1] += d1[i];
        d1[i] = 0;
    }
    if(d2[i]){
        d2[2*i] += d2[i];
        d2[2*i+1] += d2[i];
        d2[i] = 0;
    }
}

void pull(int i){
    ll l1 = s1[2*i] + (d1[2*i] * len(2*i));
    ll r1 = s1[2*i+1] + (d1[2*i+1] * len(2*i+1));
    s1[i] = l1 + r1;
    ll l2 = s2[2*i] + (d2[2*i] * sigma(2*i));
    ll r2 = s2[2*i+1] + (d2[2*i+1] * sigma(2*i+1));
    s2[i] = l2 + r2;
}

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r){
        scanf("%lld", &s1[i]);
        return;
    }
    int m = l+(r-l)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
    pull(i);
}

void increment(int type, int i, int l, int r, ll v){
    if(l > hi[i] || r < lo[i])  return;
    if(l <= lo[i] && hi[i] <= r){
        if(type == 1)   d1[i] += v;
        if(type == 2)   d2[i] += v;
        return;
    }

    push(i);
    increment(type, 2*i, l, r, v);
    increment(type, 2*i+1, l, r, v);
    pull(i);
}

ll sum(int type, int i, int l, int r){
    if(l > hi[i] || r < lo[i])  return 0;
    if(l <= lo[i] && hi[i] <= r){
        if(type == 1)   return s1[i] + (d1[i] * len(i));
        if(type == 2)   return s2[i] + (d2[i] * sigma(i));
        return 0;
    }

    push(i);
    ll lsum = sum(type, 2*i, l, r);
    ll rsum = sum(type, 2*i+1, l, r);
    pull(i);

    return lsum + rsum;
}

void update(int l, int r){
    increment(1, 1, l, r, -l+1);
    increment(2, 1, l, r, 1);
}

ll query(int l, int r){
    return sum(1, 1, l, r) + sum(2, 1, l, r);
}

int main(){
    scanf("%d %d", &N, &Q);

    build(1, 1, N);
    for(int q = 0; q < Q; q++){
        scanf("%d %d %d", &t, &a, &b);
        if(t == 1)      update(a, b);
        else if(t == 2) printf("%lld\n", query(a, b));
    }
}
