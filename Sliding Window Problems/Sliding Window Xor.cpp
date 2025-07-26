#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e7+1;

int N, K;
ll x, a, b, c;

int main(){
    scanf("%d %d", &N, &K);
    scanf("%lld %lld %lld %lld", &x, &a, &b, &c);

    ll xum = 0;
    for(int i = 1; i <= N; i++){
        int l = max(1, i-K+1);
        int r = min(i, N-K+1);
        if((r - l) % 2 == 0)
            xum ^= x;

        x = (a * x + b) % c;
    }
    printf("%lld\n", xum);
}