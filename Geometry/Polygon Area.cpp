#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1001;

int N;
ll x[maxN], y[maxN], ans;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%lld %lld", &x[i], &y[i]);
    x[N] = x[0]; y[N] = y[0];

    for(int i = 0; i < N; i++){
        ans += x[i] * y[i+1];
        ans -= y[i] * x[i+1];
    }
    printf("%lld\n", abs(ans));
}
