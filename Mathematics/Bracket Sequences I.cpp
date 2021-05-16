#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll N, numerator, denominator;

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

ll inverse(ll a){
    return fastpow(a, MOD-2);
}

int main(){
    scanf("%lld", &N);
    if(N&1) printf("0\n");
    else {
        numerator = 1;
        for(int i = 1; i <= N; i++)
            numerator = (numerator * i) % MOD;

        denominator = 1;
        for(int i = 1; i <= N/2; i++)
            denominator = (denominator * i) % MOD;
        denominator = (denominator * denominator) % MOD;
        denominator = (denominator * (N/2+1)) % MOD;

        printf("%lld\n", (numerator*inverse(denominator))%MOD);
    }
}
