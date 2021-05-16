#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5;

int N, p[maxN+1], sz[maxN+1];
vector<int> G[maxN+1];

void dfs(int u){
    sz[u] = 1;
    for(int v : G[u]){
        dfs(v);
        sz[u] += sz[v];
    }
}

int main(){
    scanf("%d", &N);
    for(int i = 2; i <= N; i++){
        scanf("%d", &p[i]);
        G[p[i]].push_back(i);
    }

    dfs(1);

    for(int i = 1; i <= N; i++)
        printf("%d%c", sz[i]-1, (" \n")[i==N]);
}
