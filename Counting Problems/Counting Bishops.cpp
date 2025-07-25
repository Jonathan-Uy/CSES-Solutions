#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 501;
const ll MOD = 1e9+7;

int N, K;
ll fac[maxN], inv[maxN];
ll T[maxN], B[2*maxN], W[2*maxN];

ll fastpow(ll x, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        b >>= 1;
    }
    return res;
}

ll choose(int n, int k){
    if(k < 0 || n < k)  return 0;
    return fac[n] * inv[k] % MOD * inv[n-k] % MOD;
}

ll stirling2(int n, int k){
    ll sum = 0;
    for(int i = 0; i <= k; i++){
        ll a = (i&1 ? -1 : 1);
        ll b = choose(k, i);
        ll c = fastpow(k-i, n);
        ll term = a * b % MOD * c % MOD;
        sum = (sum + term + MOD) % MOD;
    }
    return sum * inv[k] % MOD;
}

void compute_T(int n){
    for(int k = 0; k <= n; k++)
        T[k] = stirling2(n+1, n+1-k);
}

void init_choose(){
    fac[0] = inv[0] = 1;
    for(int i = 1; i < maxN; i++){
        fac[i] = (fac[i-1] * i) % MOD;
        inv[i] = fastpow(fac[i], MOD-2);
    }
}

ll calculate(int n, int k){
    if(n == 1)      return 1;
    if(k >= 2*n)    return 0;
    memset(B, 0, sizeof(B));
    memset(W, 0, sizeof(W));

    int m = n/2, odd = n&1;
    for(int k = 0; k <= m+odd; k++){
        compute_T(2*m-1-k+odd);
        ll a = choose(m+odd, k);
        ll b = choose(m, k);
        for(int i = 0; i+k < n; i++){
            B[i+k] += (a * T[i]) % MOD;
            B[i+k] %= MOD;
            W[i+k] += (b * T[i]) % MOD;
            W[i+k] %= MOD;
        }
    }

    ll sum = 0;
    for(int b = 0; b <= min(N-1, K); b++){
        int w = K-b;
        sum += (B[b] * W[w]) % MOD;
        sum %= MOD;
    }
    return sum;
}

int main(){
    init_choose();
    scanf("%d %d", &N, &K);
    printf("%lld\n", calculate(N, K));
}