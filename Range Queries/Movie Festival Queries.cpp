#include <bits/stdc++.h>

using namespace std;
const int logN = 17, maxT = 1e6;

int N, Q, dp[maxT+1][logN+1];
vector<int> movies[maxT+1];

int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 0, a, b; i < N; i++){
        scanf("%d %d", &a, &b);
        movies[a].push_back(b);
    }

    priority_queue<int, vector<int>, greater<int>> ends;
    for(int t = maxT; t >= 0; t--){
        for(int b : movies[t])
            ends.push(b);

        dp[t][0] = ends.empty() ? maxT+1 : ends.top();
    }
    for(int k = 1; k <= logN; k++)
        for(int t = 0; t <= maxT; t++)
            dp[t][k] = dp[t][k-1] > maxT ? maxT+1 : dp[dp[t][k-1]][k-1];

    for(int q = 0, a, b; q < Q; q++){
        scanf("%d %d", &a, &b);
        int ans = 0;
        for(int k = logN; k >= 0; k--){
            if(dp[a][k] <= b){
                a = dp[a][k];
                ans += (1<<k);
            }
        }
        printf("%d\n", ans);
    }
}