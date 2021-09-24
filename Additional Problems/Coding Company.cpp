#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 101, maxX = 5e3+1;
const ll MOD = 1e9+7;

int N, X, t[maxN];
ll dp[maxN][maxN][maxX];

int main(){
    scanf("%d %d", &N, &X);
    for(int i = 1; i <= N; i++)
        scanf("%d", &t[i]);
    sort(t+1, t+N+1);
    t[0] = t[1];

    dp[0][0][0] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = N; j >= 0; j--){
            for(int k = X; k >= 0; k--){
                ll cnt = dp[i-1][j][k];
                int newk = k + j * (t[i]-t[i-1]);
                if(newk > X)    continue;

                dp[i][j][newk] = (dp[i][j][newk] + (j+1) * cnt) % MOD;
                if(j != N)  dp[i][j+1][newk] = (dp[i][j+1][newk] + cnt) % MOD;
                if(j != 0)  dp[i][j-1][newk] = (dp[i][j-1][newk] + j * cnt) % MOD;
            }
        }
    }

    ll tot = 0;
    for(int i = 0; i <= X; i++)
        tot = (tot + dp[N][0][i]) % MOD;
    printf("%lld\n", tot);
}