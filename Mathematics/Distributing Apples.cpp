#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e6;
const ll MOD = 1e9+7;

int N, M;
ll fact[maxN], inv[maxN];

ll inverse(ll x){
    ll res = 1;
    ll expo = MOD-2;
    while(expo > 0){
        if(expo&1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        expo >>= 1;
    }
    return res;
}

void init(){
    fact[0] = inv[0] = 1;
    for(int i = 1; i < maxN; i++){
        fact[i] = i * fact[i-1] % MOD;
        inv[i] = inverse(fact[i]);
    }
}

ll choose(int n, int k){
    return fact[n] * inv[k] % MOD * inv[n-k] % MOD;
}

int main(){
    init();
    scanf("%d %d", &N, &M);
    printf("%lld\n", choose(N+M-1, M));
}
