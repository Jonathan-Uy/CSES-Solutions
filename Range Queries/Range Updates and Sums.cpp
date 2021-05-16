#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5;

int N, Q, t, a, b, lo[4*maxN], hi[4*maxN];
ll x, del[4*maxN], ass[4*maxN], sum[4*maxN];

int len(int i){
    return hi[i]-lo[i]+1;
}

void increment(int i, ll v){
    del[i] += v;
    sum[i] += len(i) * v;
}

void assign(int i, ll v){
    ass[i] = v;
    del[i] = 0;
    sum[i] = len(i) * v;
}

void push(int i){
    if(ass[i]){
        assign(2*i, ass[i]);
        assign(2*i+1, ass[i]);
        ass[i] = 0;
    }
    if(del[i]){
        increment(2*i, del[i]);
        increment(2*i+1, del[i]);
        del[i] = 0;
    }
}

void pull(int i){
    sum[i] = sum[2*i] + sum[2*i+1];
}

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r){
        scanf("%lld", &sum[i]);
        return;
    }
    int m = l+(r-l)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
    pull(i);
}

void increment(int i, int l, int r, ll v){
    if(l > hi[i] || r < lo[i])  return;
    if(l <= lo[i] && hi[i] <= r){
        increment(i, v); return;
    }

    push(i);
    increment(2*i, l, r, v);
    increment(2*i+1, l, r, v);
    pull(i);
}

void assign(int i, int l, int r, ll v){
    if(l > hi[i] || r < lo[i])  return;
    if(l <= lo[i] && hi[i] <= r){
        assign(i, v); return;
    }

    push(i);
    assign(2*i, l, r, v);
    assign(2*i+1, l, r, v);
    pull(i);
}

ll query(int i, int l, int r){
    if(l > hi[i] || r < lo[i])  return 0;
    if(l <= lo[i] && hi[i] <= r){
        return sum[i];
    }

    push(i);
    ll lsum = query(2*i, l, r);
    ll rsum = query(2*i+1, l, r);
    pull(i);

    return lsum + rsum;
}

int main(){
    scanf("%d %d", &N, &Q);

    build(1, 1, N);
    for(int q = 0; q < Q; q++){
        scanf("%d %d %d", &t, &a, &b);
        if(t == 1){
            scanf("%lld", &x);
            increment(1, a, b, x);
        } else if(t == 2){
            scanf("%lld", &x);
            assign(1, a, b, x);
        } else if(t == 3){
            printf("%lld\n", query(1, a, b));
        }
    }
}
