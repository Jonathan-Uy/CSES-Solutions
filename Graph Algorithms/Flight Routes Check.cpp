#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;

int N, M, a, b;
bool vis1[maxN], vis2[maxN];
vector<int> G1[maxN], G2[maxN];

void dfs1(int u = 1, int p = 0){
    vis1[u] = true;
    for(int v : G1[u])
        if(v != p && !vis1[v])
            dfs1(v, u);
}

void dfs2(int u = 1, int p = 0){
    vis2[u] = true;
    for(int v : G2[u])
        if(v != p && !vis2[v])
            dfs2(v, u);
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        G1[a].push_back(b);
        G2[b].push_back(a);
    }
    dfs1();
    dfs2();
    for(int i = 1; i <= N; i++){
        if(!vis1[i] || !vis2[i]){
            printf("NO\n");
            if(!vis1[i])    printf("1 %d\n", i);
            else            printf("%d 1\n", i);
            return 0;
        }
    }
    printf("YES\n");
}
