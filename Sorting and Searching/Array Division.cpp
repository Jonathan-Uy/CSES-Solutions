#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5;

int N, K, a[maxN];
ll lo = 0, hi = 1e18;

bool check(ll X){
    int k = 1;
    ll sum = 0;
    for(int i = 0; i < N; i++){
        sum += a[i];
        if(sum > X){
            k++;
            sum = a[i];
        }
    }
    return k <= K;
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
        lo = max(lo, (ll) a[i]);
    }

    while(lo <= hi){
        ll mid = lo + (hi-lo)/2;
        if(check(mid))  hi = mid-1;
        else            lo = mid+1;
    }
    printf("%lld\n", lo);
}
