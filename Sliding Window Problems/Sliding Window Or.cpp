#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e7+5;

int N, K, val[maxN], pre[maxN], suf[maxN];;
ll x, a, b, c;

int main(){
    scanf("%d %d", &N, &K);
    scanf("%lld %lld %lld %lld", &x, &a, &b, &c);
    for(int i = 0; i < N; i++){
        val[i] = x;
        x = (a * x + b) % c;
    }

    for(int i = 0; i < N; i++)
        pre[i] = (i % K == 0) ? val[i] : (pre[i-1] | val[i]);
    for(int i = N-1; i >= 0; i--)
        suf[i] = (i % K == K-1) ? val[i] : (suf[i+1] | val[i]);

    int xor_sum = 0;
    for(int i = 0; i <= N-K; i++){
        int l = i, r = i + K - 1;
        int or_val = suf[l] | pre[r];
        xor_sum ^= or_val;
    }

    printf("%d\n", xor_sum);
}