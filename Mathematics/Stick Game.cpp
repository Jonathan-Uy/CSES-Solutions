#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6;
const int maxK = 100;

int N, K, p[maxK];
bool dp[maxN+1];

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < K; i++)
        scanf("%d", &p[i]);

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < K; j++)
            if(i-p[j] >= 0 && !dp[i-p[j]])
                dp[i] = true;
        printf("%c", ("LW")[dp[i]]);
    }
}
