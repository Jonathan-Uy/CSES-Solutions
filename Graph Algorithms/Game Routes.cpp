#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e5+1;
const ll MOD = 1e9+7;

int N, M, a, b, cnt, in[maxN];
ll dp[maxN];
vector<int> G[maxN];
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

    dp[1] = 1;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int v : G[u]){
            dp[v] = (dp[v] + dp[u]) % MOD;
            in[v]--;
            if(in[v] == 0)
                Q.push(v);
        }
    }

    printf("%lld\n", dp[N]);
}
