#include <bits/stdc++.h>

using namespace std;
const int maxN = 5e4+1;

int N, M, a, b, in[maxN];
bitset<maxN> ans[maxN];
vector<int> G[maxN];
queue<int> Q;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        G[b].push_back(a);
        in[a]++;
    }

    for(int i = 1; i <= N; i++){
        if(in[i] == 0){
            ans[i].set(i);
            Q.push(i);
        }
    }

    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int v : G[u]){
            ans[v] |= ans[u];
            in[v]--;
            if(in[v] == 0){
                ans[v].set(v);
                Q.push(v);
            }
        }
    }

    for(int i = 1; i <= N; i++)
        printf("%d%c", (int) ans[i].count(), (" \n")[i==N]);
}
