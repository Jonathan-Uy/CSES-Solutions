#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e5;
const int maxM = 100;
const ll MOD = 1e9+7;

int N, M, x[maxN+1];
ll ans, dp[maxN+1][maxM+1];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++)
        scanf("%d", &x[i]);

    if(x[1])
        dp[1][x[1]] = 1;
    else
        for(int i = 1; i <= M; i++)
            dp[1][i] = 1;

    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= M; j++){
            dp[i][j] = dp[i-1][j];
            if(j != 1)  dp[i][j] += dp[i-1][j-1];
            if(j != M)  dp[i][j] += dp[i-1][j+1];
            dp[i][j] %= MOD;
        }

        if(x[i])
            for(int j = 0; j <= M; j++)
                if(j != x[i])
                    dp[i][j] = 0;
    }

    for(int i= 1; i <= M; i++)
        ans = (ans + dp[N][i]) % MOD;
    printf("%lld\n", ans);
}
