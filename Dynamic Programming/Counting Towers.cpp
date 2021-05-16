#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e6;
const ll MOD = 1e9+7;

int T, N;
ll dp[maxN+1];

int main(){
    dp[1] = 2;
    dp[2] = 8;
    for(int i = 3; i <= maxN; i++)
        dp[i] = ((6*dp[i-1] - 7*dp[i-2]) % MOD + MOD) % MOD;

    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        scanf("%d", &N);
        printf("%lld\n", dp[N]);
    }
}
