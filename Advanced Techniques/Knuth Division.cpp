#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int maxN = 5005;

int N, split[maxN][maxN];
ll pre[maxN], dp[maxN][maxN];

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%lld", &pre[i]);
        pre[i] += pre[i-1];
    }

    for(int len = 0; len <= N; len++){
        for(int l = 0; l+len <= N; l++){
            int r = l+len;
            if(len < 2){
                dp[l][r] = 0;
                split[l][r] = l;
                continue;
            }

            dp[l][r] = INF;
            for(int m = split[l][r-1]; m <= split[l+1][r]; m++){
                ll possible = dp[l][m] + dp[m][r] + pre[r] - pre[l];
                if(possible < dp[l][r]){
                    dp[l][r] = possible;
                    split[l][r] = m;
                }
            }
        }
    }

    printf("%lld\n", dp[0][N]);
}