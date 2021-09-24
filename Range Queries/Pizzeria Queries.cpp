#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1, SIZE = 4*maxN;
const int INF = 0x3f3f3f3f;

int N, Q, p[maxN], mp[maxN], lo[SIZE], hi[SIZE], mn[2][SIZE];

void pull(int i){
    mn[0][i] = min(mn[0][2*i], mn[0][2*i+1]);
    mn[1][i] = min(mn[1][2*i], mn[1][2*i+1]);
}

void init(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r){
        scanf("%d", &p[l]);
        mn[0][i] = l+p[l];
        mn[1][i] = (N-l+1)+p[l];
        mp[l] = i;
        return;
    }
    int m = (l+r)/2;
    init(2*i, l, m);
    init(2*i+1, m+1, r);
    pull(i);
}

void update(int idx, int val){
    int i = mp[idx];
    mn[0][i] = idx+val;
    mn[1][i] = (N-idx+1)+val;
    i >>= 1;
    while(i){
        pull(i);
        i >>= 1;
    }
}

int query(int i, int t, int l, int r){
    if(l > hi[i] || r < lo[i])      return INF;
    if(l <= lo[i] && hi[i] <= r)    return mn[t][i];

    int left = query(2*i, t, l, r);
    int right = query(2*i+1, t, l, r);
    return min(left, right);
}

int main(){
    scanf("%d %d", &N, &Q);
    init(1, 1, N);
    for(int q = 0, t, k, x; q < Q; q++){
        scanf("%d %d", &t, &k);
        if(t == 1){
            scanf("%d", &x);
            update(k, x);
        } else if(t == 2){
            int left = query(1, 1, 1, k);
            int right = query(1, 0, k, N);
            printf("%d\n", min(left-(N-k+1), right-k));
        }
    }
}
