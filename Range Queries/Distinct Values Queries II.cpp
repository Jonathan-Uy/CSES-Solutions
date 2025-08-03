#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int maxN = 2e5, SIZE = 4*maxN;
const int INF = 0x3f3f3f3f;

int N, Q, a[maxN+1];
int lo[SIZE], hi[SIZE], mn[SIZE], mx[SIZE];

unordered_map<int,set<int,greater<int>>> prv;
unordered_map<int,set<int>> nxt;
unordered_map<int,int> segtree_idx;

void pull(int i){
    mn[i] = min(mn[2*i], mn[2*i+1]);
    mx[i] = max(mx[2*i], mx[2*i+1]);
}

void init(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r){
        int v = a[l];
        mn[i] = nxt[v].upper_bound(l) == nxt[v].end() ? INF : *nxt[v].upper_bound(l);
        mx[i] = prv[v].upper_bound(l) == prv[v].end() ? -INF : *prv[v].upper_bound(l);
        segtree_idx[l] = i;
        return;
    }

    int m = l+(r-l)/2;
    init(2*i, l, m);
    init(2*i+1, m+1, r);
    pull(i);
}

void assign(int i, int _mn, int _mx){
    i = segtree_idx[i];
    if(_mn != -1)   mn[i] = _mn;
    if(_mx != -1)   mx[i] = _mx;
    while(i > 1){
        i >>= 1;
        pull(i);
    }
}

pii query(int i, int l, int r){
    if(l > hi[i] || r < lo[i])      return {INF, -INF};
    if(l <= lo[i] && hi[i] <= r)    return {mn[i], mx[i]};

    pii lmin = query(2*i, l, r);
    pii rmin = query(2*i+1, l, r);

    return {min(lmin.first, rmin.first), max(lmin.second, rmin.second)};
}

void update(int pos, int val){
    int old_val = a[pos];
    int old_next = nxt[old_val].upper_bound(pos) == nxt[old_val].end() ? INF : *nxt[old_val].upper_bound(pos);
    int old_prev = prv[old_val].upper_bound(pos) == prv[old_val].end() ? -INF : *prv[old_val].upper_bound(pos);

    prv[old_val].erase(pos);
    nxt[old_val].erase(pos);
    if(old_next != INF)     assign(old_next, -1, old_prev);
    if(old_prev != -INF)    assign(old_prev, old_next, -1);

    a[pos] = val;
    int new_next = nxt[val].upper_bound(pos) == nxt[val].end() ? INF : *nxt[val].upper_bound(pos);
    int new_prev = prv[val].upper_bound(pos) == prv[val].end() ? -INF : *prv[val].upper_bound(pos);
    prv[val].insert(pos);
    nxt[val].insert(pos);

    assign(pos, new_next, new_prev);
    if(new_next != INF)     assign(new_next, -1, pos);
    if(new_prev != -INF)    assign(new_prev, pos, -1);
}

int main(){
    scanf("%d %d", &N, &Q);

    segtree_idx.reserve(N);
    prv.reserve(N + Q);
    nxt.reserve(N + Q);

    for(int i = 1; i <= N; i++){
        scanf("%d", &a[i]);
        prv[a[i]].insert(i);
        nxt[a[i]].insert(i);
    }

    init(1, 1, N);
    for(int q = 0, k, x, y; q < Q; q++){
        scanf("%d %d %d", &k, &x, &y);
        if(k == 1)  update(x, y);
        else {
            pii res = query(1, x, y);
            int mn_val = res.first, mx_val = res.second;
            printf("%s\n", (mn_val <= y || mx_val >= x) ? "NO" : "YES");
        }
    }
}
