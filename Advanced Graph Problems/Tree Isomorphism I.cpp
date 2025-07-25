#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, treeID, name[2][maxN];
vector<int> G[2][maxN];
map<vector<int>,int> mp;

void reset(){
    for(int t = 0; t < 2; t++)
        for(int i = 1; i <= N; i++)
            G[t][i].clear();
}

void dfs(int t, int u, int p){
    vector<int> childNames;
    for(int v : G[t][u]){
        if(v != p){
            dfs(t, v, u);
            childNames.push_back(name[t][v]);
        }
    }
    sort(childNames.begin(), childNames.end());
    if(!mp[childNames]) mp[childNames] = ++treeID;
    name[t][u] = mp[childNames];
}

void solve_case(){
    scanf("%d", &N);
    reset();
    for(int t = 0; t < 2; t++){
        for(int i = 0, a, b; i < N-1; i++){
            scanf("%d %d", &a, &b);
            G[t][a].push_back(b);
            G[t][b].push_back(a);
        }
        dfs(t, 1, -1);
    }
    printf("%s\n", name[0][1] == name[1][1] ? "YES" : "NO");
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        solve_case();
    }
}