#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 100, maxK = 1000, maxX = 1e5+1;

int N, X, h[maxN], s[maxN], k[maxN];
ll dp[maxX];

int main(){
    scanf("%d %d", &N, &X);
    for(int i = 0; i < N; i++)  scanf("%d", &h[i]);
    for(int i = 0; i < N; i++)  scanf("%d", &s[i]);
    for(int i = 0; i < N; i++)  scanf("%d", &k[i]);

    fill(dp+1, dp+X+1, -1);
    for(int i = 0; i < N; i++){
        for(int b = 1; k[i] > 0; b++){
            int amnt = min(b, k[i]);
            k[i] -= b;
            int price = amnt * h[i];
            int pages = amnt * s[i];
            for(int j = X; j >= price; j--)
                if(dp[j-price] != -1)
                    dp[j] = max(dp[j], dp[j-price] + pages);
        }
    }

    for(int i = 1; i <= X; i++)
        dp[i] = max(dp[i], dp[i-1]);
    printf("%lld\n", dp[X]);
}