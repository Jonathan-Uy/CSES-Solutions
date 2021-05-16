#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll N, sum;

ll sigma(ll x){
    return ((x%MOD)*((x+1)%MOD)/2)%MOD;
}

int main(){
    scanf("%lld", &N);
    for(ll l = 1; l <= N; l++){
        ll r = N/(N/l);
        sum += (N/l)%MOD*(sigma(r)-sigma(l-1)+MOD)%MOD;
        sum = (sum+MOD)%MOD;
        l = r;
    }
    printf("%lld\n", sum);
}
