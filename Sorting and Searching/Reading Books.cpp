#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll t, mx, sum;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld", &t);
        mx = max(mx, t);
        sum += t;
    }
    printf("%lld\n", max(sum, 2*mx));
}
