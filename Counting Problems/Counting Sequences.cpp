#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e6+1;
const ll MOD = 1e9+7;

int N, K;
ll fac[maxN], inv[maxN];

ll fastpow(ll x, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        b >>= 1;
    }
    return res;
}

void init_choose(){
    fac[0] = inv[0] = 1;
    for(int i = 1; i < maxN; i++){
        fac[i] = (fac[i-1] * i) % MOD;
        inv[i] = fastpow(fac[i], MOD-2);
    }
}

ll choose(int n, int k){
    if(k < 0 || k > n)  return 0;
    return fac[n] * inv[k] % MOD * inv[n-k] % MOD;
}

ll T(int n, int k){
    ll sum = 0;
    for(int j = 0; j <= k; j++){
        ll a = (j&1 ? -1 : 1);
        ll b = choose(k, j);
        ll c = fastpow(k-j, n);
        ll term = (a * b % MOD * c % MOD + MOD) % MOD;
        sum = (sum + term) % MOD;
    }
    return sum;
}

int main(){
    init_choose();
    scanf("%d %d", &N, &K);
    printf("%lld\n", T(N, K));
}