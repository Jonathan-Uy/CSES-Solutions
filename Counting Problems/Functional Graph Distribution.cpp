#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 5001;
const ll MOD = 1e9+7;

int N;
ll pown[maxN], fac[maxN], inv[maxN], S[maxN][maxN];

ll inverse(ll x){
    ll res = 1;
    ll b = MOD-2;
    while(b){
        if(b&1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        b >>= 1;
    }
    return res;
}

void init_powers(){
    pown[0] = 1;
    for(int i = 1; i < maxN; i++)
        pown[i] = (pown[i-1] * N) % MOD;
}

void init_choose(){
    fac[0] = inv[0] = 1;
    for(int i = 1; i < maxN; i++){
        fac[i] = (fac[i-1] * i) % MOD;
        inv[i] = inverse(fac[i]);
    }
}

void init_stirling(){
    S[1][1] = 1;
    for(int n = 2; n < maxN; n++)
        for(int k = 1; k <= n; k++)
            S[n][k] = (S[n-1][k-1] - (n-1) * S[n-1][k]) % MOD;
}

ll choose(int n, int k){
    if(k < 0 || k > n)  return 0;
    return fac[n] * inv[k] % MOD * inv[n-k] % MOD;
}

ll stirling1(int n, int k){
    return abs(S[n][k]);
}

ll T(int n, int k){
    ll sum = 0;
    for(int j = 0; j <= n-1; j++){
        ll a = choose(n-1, j);
        ll b = pown[n-1-j];
        ll c = stirling1(j+1, k);
        sum += a * b % MOD * c % MOD;
        sum %= MOD;
    }
    return sum;
}

int main(){
    scanf("%d", &N);
    init_powers();
    init_choose();
    init_stirling();
    for(int k = 1; k <= N; k++)
        printf("%lld\n", T(N, k));
}