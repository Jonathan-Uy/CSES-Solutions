#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5;
const ll MOD = 1e9+7;

int N, x[maxN];
map<int,int> freq;

ll mod_inv(ll a){
    ll res = 1;
    ll b = MOD-2;
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
        scanf("%d", &x[i]);

    ll ans = 0;
    ll prod = 1;
    for(int i = 0; i < N; i++){
        ll seqs = (prod * mod_inv(freq[x[i]]+1)) % MOD;
        ans = (ans + seqs) % MOD;

        freq[x[i]]++;
        prod = (prod * (freq[x[i]]+1) ) % MOD;
        prod = (prod * mod_inv(freq[x[i]])) % MOD;
    }
    printf("%lld\n", ans);
}