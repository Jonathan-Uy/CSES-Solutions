#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;

int N, a, b, p[maxN], sz[maxN];
vector<int> G[maxN];

void dfs(int u = 1){
    sz[u] = 1;
    for(int v : G[u]){
        if(v != p[u]){
            p[v] = u;
            dfs(v);
            sz[u] += sz[v];
        }
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N-1; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs();

    for(int i = 1; i <= N; i++){
        bool centroid = true;

        if(p[i] != 0 && N-sz[i] > N/2)
            centroid = false;

        for(int v : G[i])
            if(v != p[i] && sz[v] > N/2)
                centroid = false;

        if(centroid){
            printf("%d\n", i);
            return 0;
        }
    }
}
