#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 501;
const int maxK = maxN*(maxN-1)/2;
const ll MOD = 1e9+7;

int N, K;
ll dp[maxN][maxK];

void init(){
    for(int i = 1; i < maxN; i++){
        int r = i*(i-1)/2;
        dp[i][0] = dp[i][r] = 1;
        for(int j = 1; j <= r/2; j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            if(j-i >= 0)
                dp[i][j] = (dp[i][j] - dp[i-1][j-i] + MOD) % MOD;
        }
        for(int j = r/2+1; j < r; j++)
            dp[i][j] = dp[i][r-j];
    }
}

int main(){
    init();
    scanf("%d %d", &N, &K);
    printf("%lld\n", dp[N][K]);
}