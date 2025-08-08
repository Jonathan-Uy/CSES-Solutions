#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int logX = 32;

int N, basis[logX];

bool insert_vector(int mask){
    for(int i = logX-1; i >= 0; i--){
        if((mask&(1<<i)) == 0)  continue;
        if(!basis[i]){
            basis[i] = mask;
            return true;
        }
        mask ^= basis[i];
    }
    return false;
}

int main(){
    scanf("%d", &N);

    ll ans = 1;
    for(int i = 0, x; i < N; i++){
        scanf("%d", &x);
        if(insert_vector(x))
            ans *= 2;
    }
    printf("%lld\n", ans);
}