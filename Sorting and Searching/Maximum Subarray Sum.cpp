#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int N;
ll maxSum, curSum, x[maxN];

int main(){
    scanf("%d", &N);
    maxSum = -INF;
    for(int i = 0; i < N; i++){
        scanf("%lld", &x[i]);
        maxSum = max(maxSum, x[i]);
    }

    for(int i = 0; i < N; i++){
        curSum += x[i];
        maxSum = max(maxSum, curSum);
        if(curSum < 0)  curSum = 0;
    }
    printf("%lld\n", maxSum);
}
