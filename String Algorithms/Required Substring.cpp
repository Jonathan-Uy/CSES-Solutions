#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1005, maxM = 505;
const ll MOD = 1e9+7;

int N, M, best[26][maxM];
char S[maxN];
ll ans, dp[maxM][maxN];

ll pow26(ll b){
    ll a = 26;
    ll res = 1;
    while(b){
        if(b&1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

bool good(vector<char> pre, int k){
    int SZ = (int) pre.size();
    for(int i = 0; i < SZ-k; i++)
        if(pre[i+k] != S[i])
            return false;
    return true;
}

int main(){
    scanf("%d %s", &N, S);
    M = (int) strlen(S);
    if(M > N){
        printf("0\n");
        return 0;
    }

    for(int r = 0; r < M; r++){
        for(int c = 0; c < 26; c++){
            vector<char> pre;
            for(int i = 0; i < r; i++)
                pre.push_back(S[i]);
            pre.push_back((char) (c+'A'));

            for(int k = 0; k < r+1; k++){
                if(good(pre, k)){
                    best[c][r] = r-k+1;
                    break;
                }
            }
        }
    }

    dp[0][0] = 1;
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < M; j++)
            for(int c = 0; c < 26; c++)
                dp[best[c][j]][i] = (dp[best[c][j]][i] + dp[j][i-1]) % MOD;

    ans = pow26(N);
    for(int i = 0; i < M; i++)
        ans = (ans - dp[i][N] + MOD) % MOD;
    printf("%lld\n", ans);
}