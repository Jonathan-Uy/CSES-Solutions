#include <bits/stdc++.h>

using namespace std;
const int maxN = 5e3+5;

int N, M, dp[maxN][maxN];
char a[maxN], b[maxN];

int main(){
    scanf("%s %s", a, b);
    N = (int) strlen(a);
    M = (int) strlen(b);

    memset(dp, 0x3f, sizeof(dp));
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(i == 0)      dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(a[i-1] == b[j-1])   dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }

    printf("%d\n", dp[N][M]);
}
