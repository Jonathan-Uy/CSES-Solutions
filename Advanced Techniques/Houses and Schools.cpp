#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 3001;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int N, K;
ll best, p[3][maxN], dp[maxN][maxN];

ll travel(int d, int a, int b){
    return (p[d][b] - p[d][a-1]) - (p[0][b] - p[0][a-1]) * (d == 1 ? a : N-b+1);
}

ll C(int a, int b){
    int m = (a+b)/2;
    return travel(1, a, m) + travel(2, m+1, b);
}

void solve(int k, int a = 1, int b = N, int optl = 1, int optr = N){
    if(a > b)   return;
    int m = (a+b)/2;
    int opt = -1;
    dp[k][m] = INF;
    for(int i = optl; i <= m; i++){
        if(dp[k-1][i] + C(i, m) < dp[k][m]){
            dp[k][m] = dp[k-1][i] + C(i, m);
            opt = i;
        }
    }
    solve(k, a, m-1, optl, opt);
    solve(k, m+1, b, opt, optr);
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++){
        ll x;
        scanf("%lld", &x);
        p[0][i] = p[0][i-1] + x;
        p[1][i] = p[1][i-1] + i * x;
        p[2][i] = p[2][i-1] + (N-i+1) * x;
    }

    for(int i = 1; i <= N; i++)
        dp[1][i] = travel(2, 1, i);
    for(int k = 2; k <= K; k++)
        solve(k);

    best = INF;
    for(int i = 1; i <= N; i++)
        best = min(best, dp[K][i] + travel(1, i, N));
    printf("%lld\n", best);
}