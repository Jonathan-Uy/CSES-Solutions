#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;

int N, A[maxN];

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)  scanf("%d", &A[i]);
    for(int i = 1, b; i <= N; i++){
        scanf("%d", &b);
        A[i] += (A[i-1] - b);
    }
    sort(A+1, A+N+1);

    ll ans = 0;
    for(int i = 1; i <= N; i++)
        ans += abs(A[i] - A[(N+1)/2]);
    printf("%lld\n", ans);
}