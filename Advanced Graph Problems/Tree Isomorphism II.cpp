#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, treeID, sz[2][maxN], name[2][maxN];
vector<int> centroids[2], G[2][maxN];
map<vector<int>,int> mp;

void reset(){
    mp.clear();
    treeID = 0;
    for(int t = 0; t < 2; t++){
        centroids[t].clear();
        for(int i = 1; i <= N; i++){
            sz[t][i] = name[t][i] = 0;
            G[t][i].clear();
        }
    }
}

void dfs1(int t, int u, int p){
    sz[t][u] = 1;
    bool is_centroid = true;
    for(int v : G[t][u]){
        if(v != p){
            dfs1(t, v, u);
            sz[t][u] += sz[t][v];
            if(sz[t][v] > N/2)  is_centroid = false;
        }
    }
    if(N-sz[t][u] > N/2)    is_centroid = false;
    if(is_centroid)         centroids[t].push_back(u);
}

void dfs2(int t, int u, int p){
    vector<int> childNames;
    for(int v : G[t][u]){
        if(v != p){
            dfs2(t, v, u);
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
        dfs1(t, 1, -1);
    }

    for(int root1 : centroids[0]){
        for(int root2 : centroids[1]){
            dfs2(0, root1, -1);
            dfs2(1, root2, -1);
            if(name[0][root1] == name[1][root2]){
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        solve_case();
    }
}