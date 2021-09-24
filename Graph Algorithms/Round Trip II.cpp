#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, M, start, finish, p[maxN], vis[maxN];
vector<int> ans, G[maxN];

void dfs(int u){
    vis[u] = 1;
    for(int v : G[u]){
        if(vis[v] == 0){
            p[v] = u;
            dfs(v);
            if(start)
                return;
        } else if(vis[v] == 1){
            finish = u;
            start = v;
            return;
        }
    }
    vis[u] = 2;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
    }

    for(int i = 1; i <= N && !start; i++)
        if(vis[i] == 0)
            dfs(i);

    if(!start){
        printf("IMPOSSIBLE\n");
        return 0;
    }

    ans.push_back(start);
    for(int u = finish; u != start; u = p[u])
        ans.push_back(u);
    ans.push_back(start);
    reverse(ans.begin(), ans.end());

    int K = (int) ans.size();
    printf("%d\n", K);
    for(int i = 0; i < K; i++)
        printf("%d%c", ans[i], (" \n")[i==K-1]);
}
