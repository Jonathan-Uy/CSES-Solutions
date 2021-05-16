#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+1;

int N, M, a, b, cnt, in[maxN];
vector<int> ans, G[maxN];
queue<int> Q;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        in[b]++;
    }

    for(int i = 1; i <= N; i++)
        if(in[i] == 0)
            Q.push(i);

    cnt = N;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        ans.push_back(u);
        cnt--;

        for(int v : G[u]){
            in[v]--;
            if(in[v] == 0)
                Q.push(v);
        }
    }

    if(cnt)
        printf("IMPOSSIBLE\n");
    else
        for(int i = 0; i < N; i++)
            printf("%d%c", ans[i], (" \n")[i==N-1]);
}
