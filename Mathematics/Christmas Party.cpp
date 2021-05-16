#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e6;
const ll MOD = 1e9+7;

int N;
ll dp[maxN+1];

void init(){
    dp[2] = 1;
    for(int i = 3; i <= maxN; i++)
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]) % MOD;
}

int main(){
    init();
    scanf("%d", &N);
    printf("%lld\n", dp[N]);
}
