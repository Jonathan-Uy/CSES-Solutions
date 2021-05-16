#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

int N;

ll fastpow2(int x){
    ll res = 1;
    ll a = 2;
    while(x > 0){
        if(x&1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        x >>= 1;
    }
    return res;
}

int main(){
    scanf("%d", &N);
    printf("%lld\n", fastpow2(N));
}
