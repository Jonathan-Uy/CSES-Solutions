#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll p[19];

void init(){
    p[0] = 1;
    for(int i = 1; i <= 18; i++)
        p[i] = p[i-1] * 10;
}

ll check(ll N){
    ll cnt = 0, l = N, r = 0;
    for(int i = 0; l; i++){
        int d = l % 10;
        l /= 10;
        cnt += (d == 1 ? l*p[i]+r+1 : (l+(d!=0))*p[i]);
        r += p[i] * d;
    }
    return cnt;
}

int main(){
    ll K;
    scanf("%lld", &K);
    ll lo = 1, hi = 1e18;
    init();
    while(hi-lo > 1){
        ll mid = lo+(hi-lo)/2;
        if(check(mid) <= K) lo = mid;
        else                hi = mid;
    }
    printf("%lld\n", lo);
}