#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;

int N, a, b, sz[maxN];
ll down[maxN], up[maxN];
vector<int> G[maxN];

void dfs1(int u = 1, int p = 0){
    sz[u] = 1;
    for(int v : G[u]){
        if(v != p){
            dfs1(v, u);
            sz[u] += sz[v];
            down[u] += down[v] + sz[v];
        }
    }
}

void dfs2(int u = 1, int p = 0){
    if(p != 0)
        up[u] = (up[p]+down[p]) + N - (2*sz[u]+down[u]);
    for(int v : G[u])
        if(v != p)
            dfs2(v, u);
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs1();
    dfs2();

    for(int i = 1; i <= N; i++)
        printf("%lld%c", down[i]+up[i], (" \n")[i==N]);
}
