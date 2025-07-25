#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;

int N, Q, a, b, t, s;
int timer, in[maxN], out[maxN];
ll x, v[maxN], ds[2*maxN];
vector<int> G[maxN];

void update(int idx, ll val){
    for(int i = idx; i <= timer; i += -i&i)
        ds[i] += val;
}

ll query(int idx){
    ll sum = 0;
    for(int i = idx; i > 0; i -= -i&i)
        sum += ds[i];
    return sum;
}

void dfs(int u = 1, int p = 0){
    in[u] = ++timer;
    for(int c : G[u])
        if(c != p)
            dfs(c, u);
    out[u] = ++timer;
}

int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++)
        scanf("%lld", &v[i]);
    for(int i = 0; i < N-1; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs();
    for(int i = 1; i <= N; i++){
        update(in[i], v[i]);
        update(out[i], -v[i]);
    }

    for(int q = 0; q < Q; q++){
        scanf("%d %d", &t, &s);
        if(t == 1){
            scanf("%lld", &x);
            update(in[s], -v[s]);
            update(out[s], v[s]);
            update(in[s], x);
            update(out[s], -x);
            v[s] = x;
        } else if(t == 2){
            printf("%lld\n", query(in[s]));
        }
    }
}
