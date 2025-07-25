#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e7+1;

int N, K;
ll a, b, c, pre[maxN];

int main(){
    scanf("%d %d", &N, &K);
    scanf("%lld %lld %lld %lld", &pre[1], &a, &b, &c);

    for(int i = 2; i <= N; i++)
        pre[i] = (a * pre[i-1] + b) % c;

    for(int i = 2; i <= N; i++)
        pre[i] += pre[i-1];

    ll xum = 0;
    for(int i = K; i <= N; i++)\
        xum ^= (pre[i] - pre[i-K]);
    printf("%lld\n", xum);
}