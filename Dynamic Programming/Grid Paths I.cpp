#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1000;
const ll MOD = 1e9+7;

int N;
char c[maxN+1][maxN+1];
ll dp[maxN+1][maxN+1];

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            scanf(" %c", &c[i][j]);

    dp[1][1] = (c[1][1] == '.');
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(c[i][j] == '.'){
                if(c[i-1][j] == '.')    dp[i][j] += dp[i-1][j];
                if(c[i][j-1] == '.')    dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }

    printf("%lld\n", dp[N][N]);
}
