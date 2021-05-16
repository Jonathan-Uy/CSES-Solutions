#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5;

int N;
ll T, cnt, k[maxN];

bool check(ll t){
    cnt = 0;
    for(int i = 0; i < N; i++){
        cnt += t/k[i];
        if(cnt >= T)
            return true;
    }
    return false;
}

int main(){
    scanf("%d %lld", &N, &T);
    for(int i = 0; i < N; i++)
        scanf("%lld", &k[i]);

    ll lo = 0, hi = 1e18;
    while(lo <= hi){
        ll mid = lo + (hi-lo)/2;
        if(check(mid))  hi = mid-1;
        else            lo = mid+1;
    }
    printf("%lld\n", lo);
}
