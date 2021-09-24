#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5, SIZE = 4*maxN;
const int INF = 0x3f3f3f3f;

int N, Q, t, a, b, lo[SIZE], hi[SIZE], mn[SIZE];

void push(int i){

}

void pull(int i){
    mn[i] = min(mn[2*i], mn[2*i+1]);
}

void init(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r){
        scanf("%d", &mn[i]);
        return;
    }
    int m = l+(r-l)/2;
    init(2*i, l, m);
    init(2*i+1, m+1, r);
    pull(i);
}

void assign(int i, int l, int r, int v){
    if(l > hi[i] || r < lo[i])  return;
    if(l <= lo[i] && hi[i] <= r){
        mn[i] = v; return;
    }

    push(i);
    assign(2*i, l, r, v);
    assign(2*i+1, l, r, v);
    pull(i);
}

int minimum(int i, int l, int r){
    if(l > hi[i] || r < lo[i])      return INF;
    if(l <= lo[i] && hi[i] <= r)    return mn[i];

    push(i);
    int lmin = minimum(2*i, l, r);
    int rmin = minimum(2*i+1, l, r);
    pull(i);

    return min(lmin, rmin);
}

int main(){
    scanf("%d %d", &N, &Q);

    init(1, 1, N);
    for(int q = 0; q < Q; q++){
        scanf("%d %d %d", &t, &a, &b);
        if(t == 1)      assign(1, a, a, b);
        else if(t == 2) printf("%d\n", minimum(1, a, b));
    }
}
