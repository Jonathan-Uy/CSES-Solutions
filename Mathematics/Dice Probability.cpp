#include <bits/stdc++.h>

using namespace std;
const int maxN = 100;

int N, a, b;
double sum, dp[maxN+1][6*maxN+1];

int main(){
    scanf("%d %d %d", &N, &a, &b);
    dp[0][0] = 1;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= 6*maxN; j++)
            for(int k = 1; k <= 6; k++)
                if(j-k >= 0)
                    dp[i][j] += dp[i-1][j-k]/6;
    for(int i = a; i <= b; i++)
        sum += dp[N][i];
    printf("%.6f\n", sum);
}
