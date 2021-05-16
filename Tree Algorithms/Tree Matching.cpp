#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;

int N, a, b, cnt;
bool used[maxN];
vector<int> G[maxN];

void dfs(int u = 1, int par = 0){
    for(int v : G[u])
        if(v != par)
            dfs(v, u);

    if(!used[par] && !used[u] && par != 0){
        used[par] = used[u] = true;
        cnt++;
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
    printf("%d\n", cnt);
}
