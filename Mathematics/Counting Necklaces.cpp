#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int N, M;
ll ans;

ll fastpow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b&1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int k = 0; k < N; k++)
        ans = (ans + fastpow(M, __gcd(k, N))) % MOD;
    ans = (ans * fastpow(N, MOD-2)) % MOD;
    printf("%lld\n", ans);
}