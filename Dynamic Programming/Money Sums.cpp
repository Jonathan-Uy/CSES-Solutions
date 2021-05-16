#include <bits/stdc++.h>

using namespace std;
const int maxX = 1e5;

int N, x, cnt, largest;
bool dp[maxX+1];

int main(){
    scanf("%d", &N);

    dp[0] = true;
    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        for(int j = maxX-x; j >= 0; j--)
            if(dp[j])
                dp[j+x] = true;
    }

    for(int i = 1; i <= maxX; i++){
        if(dp[i]){
            largest = i;
            cnt++;
        }
    }

    printf("%d\n", cnt++);
    for(int i = 1; i <= maxX; i++)
        if(dp[i])
            printf("%d%c", i, (" \n")[i==largest]);
}
