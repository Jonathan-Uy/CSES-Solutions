#include <bits/stdc++.h>

using namespace std;
const int maxX = 1e6;

int N, X, c, dp[maxX+1];

int main(){
    scanf("%d %d", &N, &X);
    fill(dp+1, dp+X+1, INT_MAX);
    for(int i = 0; i < N; i++){
        scanf("%d", &c);
        for(int j = 0; j <= X-c; j++)
            if(dp[j] != INT_MAX)
                dp[j+c] = min(dp[j+c], dp[j]+1);
    }
    printf("%d\n", dp[X] == INT_MAX ? -1 : dp[X]);
}
