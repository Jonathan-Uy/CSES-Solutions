#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, K;
vector<int> leaves, G[maxN];

void dfs(int u = 1, int p = -1){
    if((int) G[u].size() == 1)  leaves.push_back(u);
    for(int v : G[u])
        if(v != p)
            dfs(v, u);
}

int main(){
    scanf("%d", &N);
    for(int i = 0, a, b; i < N-1; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfs();

    int K = (int) leaves.size();
    printf("%d\n", (K+1)/2);
    for(int i = 0; i < (K+1)/2; i++)
        printf("%d %d\n", leaves[i], leaves[i+K/2]);
}