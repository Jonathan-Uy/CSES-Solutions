#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int Q;
map<pii,int> f;

int solve(int N, int K){
    if(f[{N, K}])   return f[{N, K}];

    if(N == 1)      return f[{N, K}] = 1;
    if(2*K <= N)    return f[{N, K}] = 2*K;

    int newN = (N/2)+(N&1);
    int newK = K-N/2;

    if(N&1){
        int ans = solve(newN, newK);
        return f[{N, K}] = ((2*ans-3)+(N+1)) % (N+1);
    } else {
        return f[{N, K}] = 2*solve(newN, newK)-1;
    }
}

int main(){
    scanf("%d", &Q);
    for(int q = 0, N, K; q < Q; q++){
        scanf("%d %d", &N, &K);
        printf("%d\n", solve(N, K));
    }
}