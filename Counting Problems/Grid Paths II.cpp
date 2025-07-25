#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e6+1;
const int maxM = 1002;
const ll MOD = 1e9+7;

int N, M, x, y;
ll fact[maxN], inv[maxN], dp[maxM];
struct point {int x, y;} p[maxM];

ll inverse(ll a){
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

void init(){
    fact[0] = inv[0] = 1;
    for(int i = 1; i < maxN; i++){
        fact[i] = i * fact[i-1] % MOD;
        inv[i] = inverse(fact[i]);
    }
}

ll choose(int n, int k){
    return fact[n] * inv[n-k] % MOD * inv[k] % MOD;
}

int main(){
    init();
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &x, &y);
        p[i] = {x, y};
    }
    p[M] = {N, N};
    sort(p, p+M+1, [](point a, point b){
        return a.x == b.x ? a.y < b.y : a.x < b.x;
    });

    for(int i = 0; i <= M; i++){
        dp[i] = choose(p[i].x+p[i].y-2, p[i].x-1);
        ll subtract = 0;
        for(int j = 0; j < i; j++){
            if(p[i].x >= p[j].x && p[i].y >= p[j].y){
                int dx = p[i].x-p[j].x, dy = p[i].y-p[j].y;
                subtract += dp[j] * choose(dx+dy, dx);
                subtract %= MOD;
            }
        }
        dp[i] = (dp[i] - subtract + MOD) % MOD;
    }
    printf("%lld\n", dp[M]);
}
