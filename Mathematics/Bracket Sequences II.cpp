#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e6+5;
const ll MOD = 1e9+7;

char S[maxN];
int N, M, K;
ll tot, bad, fact[maxN], inv[maxN];

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

ll choose(int x, int y){
    return (fact[x] * inv[y] % MOD) * inv[x-y] % MOD;
}

void init(){
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= N; i++){
        fact[i] = (fact[i-1] * i) % MOD;
        inv[i] = (inv[i-1] * inverse(i)) % MOD;
    }
}

int main(){
    scanf("%d %s", &N, S);
    M = (int) strlen(S);
    init();

    int open = 0, closed = 0;
    for(int i = 0; i < M; i++){
        if(S[i] == '(')         open++;
        else if(S[i] == ')')    closed++;

        if(closed > open){
            printf("0\n");
            return 0;
        }
    }

    if(N&1 || open > N/2){
        printf("0\n");
        return 0;
    }

    tot = choose(N-open-closed, N/2-open);
    bad = choose(N-open-closed, N/2-open-1);
    printf("%lld\n", ((tot-bad)%MOD+MOD)%MOD);
}