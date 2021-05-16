#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 11;
const int maxM = 1001;
const ll MOD = 1e9+7;

int N, M;
ll dp[maxN][maxM][1<<maxN];

int main(){
    scanf("%d %d", &N, &M);
    dp[N][0][0] = 1;
    for(int i = 1; i <= M; i++){
        for(int j = 0; j < (1<<N); j++)
            dp[0][i][j<<1] = dp[N][i-1][j];

        for(int j = 1; j <= N; j++){
            int x = 1<<(j-1);
            int y = 1<<j;
            for(int mask = 0; mask < (1<<(N+1)); mask++){
                dp[j-1][i][mask] %= MOD;
                if((mask&x) && (mask&y))    continue;
                if(mask&x)                  dp[j][i][mask^x] += dp[j-1][i][mask];
                else if(mask&y)             dp[j][i][mask^y] += dp[j-1][i][mask];
                else {
                    dp[j][i][mask^x] += dp[j-1][i][mask];
                    dp[j][i][mask^y] += dp[j-1][i][mask];
                }
            }
        }
    }
    printf("%lld\n", dp[N][M][0] % MOD);
}
