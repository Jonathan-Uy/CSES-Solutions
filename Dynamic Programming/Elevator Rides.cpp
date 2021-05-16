#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxN = 20;
const int INF = maxN+1;

int N;
pii dp[1<<maxN];
ll X, w[maxN];

int main(){
    scanf("%d %lld", &N, &X);
    for(int i = 0; i < N; i++)
        scanf("%lld", &w[i]);

    dp[0] = {1, 0};
    for(int mask = 1; mask < (1<<N); mask++){
        dp[mask] = {INF, 0};
        for(int i = 0; i < N; i++){
            if(mask&(1<<i)){
                pii can = dp[mask^(1<<i)];
                if(can.second + w[i] <= X){
                    can.second += w[i];
                } else {
                    can.first++;
                    can.second = w[i];
                }
                dp[mask] = min(dp[mask], can);
            }
        }
    }

    printf("%d\n", dp[(1<<N)-1].first);
}
