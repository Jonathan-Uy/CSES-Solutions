#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const double EPS = 0.001;
const int maxK = 20;

int K;
ll N, cnt, a[maxK];

int main(){
    scanf("%lld %d", &N, &K);
    for(int i = 0; i < K; i++)
        scanf("%lld", &a[i]);

    cnt = N;
    double RHS = log(N) + EPS;
    for(int mask = 0; mask < (1<<K); mask++){
        bool odd = (__builtin_popcount(mask)&1);

        ll prod = 1;
        double LHS = 0.0;
        for(int i = 0; i < K; i++){
            if(mask&(1<<i)){
                LHS += log(a[i]);
                prod *= a[i];
            }
        }

        if(LHS < RHS)
            cnt += (odd ? 1 : -1) * (N/prod);
    }

    printf("%lld\n", cnt);
}