#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxX = 1e6+1;

ll ans;
int N, dp[maxX];
bool b[maxX];
vector<int> primes;

void init(){
    fill(b+2, b+maxX, true);
    for(int i = 2; i*i < maxX; i++)
        if(b[i])
            for(int j = i*i; j < maxX; j += i)
                b[j] = false;
    for(int i = 2; i < maxX; i++)
        if(b[i])
            primes.push_back(i);
}

void compute(int x){
    vector<int> pf;
    for(int p : primes){
        if(x == 1)  break;
        else if(b[x]){
            pf.push_back(x);
            break;
        }

        if(x % p)   continue;
        pf.push_back(p);
        while(x % p == 0)
            x /= p;
    }

    int K = (int) pf.size();
    for(int mask = 0; mask < (1<<K); mask++){
        int mu = 1;
        for(int i = 0; i < K; i++)
            if(mask&(1<<i))
                mu *= pf[i];

        int k = __builtin_popcount(mask);
        ans += (k&1 ? -dp[mu] : dp[mu]);
        dp[mu]++;
    }
}

int main(){
    init();
    scanf("%d", &N);
    for(int i = 0, x; i < N; i++){
        scanf("%d", &x);
        compute(x);
    }
    printf("%lld\n", ans);
}