#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 5e5+5;
const ll MOD = 1e9+7;

int N;
ll tot, dp[26];
char S[maxN];

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);
    for(int i = 0; i < N; i++){
        int c = (int) (S[i] - 'a');
        dp[c]++;
        for(int j = 0; j < 26; j++)
            if(j != c)
                dp[c] = (dp[c] + dp[j]) % MOD;
    }

    for(int i = 0; i < 26; i++)
        tot = (tot + dp[i]) % MOD;
    printf("%lld\n", tot);
}