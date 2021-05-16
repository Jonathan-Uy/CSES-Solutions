#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;

int N, M, h[maxN], k, ans;
int lo[4*maxN], hi[4*maxN], mx[4*maxN], mp[maxN];

void pull(int i){
    mx[i] = (h[mx[2*i]] >= h[mx[2*i+1]] ? mx[2*i] : mx[2*i+1]);
}

void init(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r){
        mp[l] = i;
        mx[i] = l;
        return;
    }
    int m = l+(r-l)/2;
    init(2*i, l, m);
    init(2*i+1, m+1, r);
    pull(i);
}

void update(int i, int v){
    h[i] -= v;
    i = mp[i];
    i >>= 1;
    while(i > 0){
        pull(i);
        i >>= 1;
    }
}

int find(int i, int v){
    if(lo[i] == hi[i])  return lo[i];
    return (h[mx[2*i]] >= v ? find(2*i, v) : find(2*i+1, v));
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        scanf("%d", &h[i]);
    init(1, 1, N);

    for(int i = 0; i < M; i++){
        scanf("%d", &k);
        ans = h[mx[1]] < k ? 0 : find(1, k);
        if(ans) update(ans, k);
        printf("%d%c", ans, (" \n")[i==M-1]);
    }
}
