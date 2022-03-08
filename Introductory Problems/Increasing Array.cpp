#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll x, mx, sum;

int main(){
    scanf("%d", &N);
    scanf("%lld", &mx);
    for(int i = 1; i < N-1; i++){
        scanf("%lld", &x);
        mx = max(mx, x);
        sum += (mx - x);
    }
    printf("%lld\n", sum);
}
