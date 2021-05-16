#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e5;
const ll MOD = 1e9+7;

int N;
ll x[maxN], k[maxN];
ll tau, sigma, pi, mu;

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
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%lld %lld", &x[i], &k[i]);

    tau = 1;
    for(int i = 0; i < N; i++)
        tau = (tau * (k[i]+1)) % MOD;

    sigma = 1;
    for(int i = 0; i < N; i++){
        ll numerator = (fastpow(x[i], k[i]+1)-1+MOD) % MOD;
        ll denominator = fastpow(x[i]-1, MOD-2);
        ll geoSum = numerator * denominator % MOD;
        sigma = (sigma * geoSum) % MOD;
    }

    pi = 1;
    mu = 1;
    for(int i = 0; i < N; i++){
        ll p = fastpow(x[i], k[i]*(k[i]+1)/2);
        mu = fastpow(mu, k[i]+1) * fastpow(p, pi) % MOD;
        pi = (pi * (k[i]+1)) % (MOD-1);
    }

    printf("%lld %lld %lld\n", tau, sigma, mu);
}
