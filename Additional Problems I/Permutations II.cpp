#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1000;
const ll MOD = 1e9+7;

int N;
ll dp[maxN+1];

void init(){
    dp[0] = dp[1] = 1;
    dp[2] = dp[3] = 0;
    for(int i = 4; i <= maxN; i++){
        ll a = (i+1) * dp[i-1] % MOD;
        ll b = (i-2) * dp[i-2] % MOD;
        ll c = (i-5) * dp[i-3] % MOD;
        ll d = (i-3) * dp[i-4] % MOD;

        dp[i] = (a-b-c+d);
        while(dp[i] < 0)
            dp[i] += MOD;
        dp[i] %= MOD;
    }
}

int main(){
    init();
    scanf("%d", &N);
    printf("%lld\n", dp[N]);
}
