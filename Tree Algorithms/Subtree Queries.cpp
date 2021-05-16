#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;

int N, Q, a, b, t, s, timer;
int in[maxN], out[maxN];
ll k[maxN], ds[2*maxN];
vector<int> G[maxN];

void update(int idx, ll val){
    for(int i = idx; i < 2*maxN; i += i&-i)
        ds[i] += val;
}

ll query(int idx){
    ll sum = 0;
    for(int i = idx; i > 0; i -= i&-i)
        sum += ds[i];
    return sum;
}

void dfs(int u, int p = 0){
    in[u] = ++timer;
    for(int v : G[u])
        if(v != p)
            dfs(v, u);
    out[u] = ++timer;
}

int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++)
        scanf("%lld", &k[i]);

    for(int i = 0; i < N-1; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    timer = 0;
    dfs(1);

    for(int i = 1; i <= N; i++)
        update(out[i], k[i]);

    for(int q = 0; q < Q; q++){
        scanf("%d %d", &t, &s);
        if(t == 1){
            update(out[s], -k[s]);
            scanf("%lld", &k[s]);
            update(out[s], k[s]);
        } else if(t == 2){
            printf("%lld\n", query(out[s])-query(in[s]));
        }
    }
}
