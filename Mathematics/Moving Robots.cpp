#include <bits/stdc++.h>

using namespace std;
const int maxK = 101;
const int N = 8, SZ = N*N;

int K;
double expected, ans[SZ], dp[maxK][SZ];

int main(){
    scanf("%d", &K);
    for(int i = 0; i < SZ; i++)
        ans[i] = 1.0;

    for(int start = 0; start < SZ; start++){
        memset(dp, 0, sizeof(dp));
        dp[0][start] = 1.0;

        for(int k = 0; k < K; k++){
            for(int u = 0; u < SZ; u++){
                vector<int> V;
                if(N <= u)          V.push_back(u-N);
                if(u < N*(N-1))     V.push_back(u+N);
                if(u % N != 0)      V.push_back(u-1);
                if(u % N != N-1)    V.push_back(u+1);

                for(int v : V)
                    dp[k+1][v] += (dp[k][u] / V.size());
            }
        }

        for(int u = 0; u < SZ; u++)
            ans[u] *= (1 - dp[K][u]);
    }

    for(int i = 0; i < SZ; i++)
        expected += ans[i];
    printf("%.6f\n", expected);
}