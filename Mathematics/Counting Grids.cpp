#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll N, A, B, C;

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
    scanf("%lld", &N);
    A = N * N;
    B = (A+3*(N&1))/4;
    C = (A+(N&1))/2;
    printf("%lld\n", ((fastpow(2, A)+2*fastpow(2, B)+fastpow(2, C))*fastpow(4,MOD-2))%MOD);
}
