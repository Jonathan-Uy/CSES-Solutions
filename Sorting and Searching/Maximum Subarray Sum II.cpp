#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;

int N, A, B;
ll pre[maxN];
multiset<ll> S;

int main(){
    scanf("%d %d %d", &N, &A, &B);
    for(int i = 1; i <= N; i++){
        scanf("%lld", &pre[i]);
        pre[i] += pre[i-1];
    }

    for(int i = A; i <= B; i++)
        S.insert(pre[i]);

    ll best = *S.rbegin();
    for(int i = 1; i+A <= N; i++){
        S.erase(pre[i+A-1]);
        S.insert(pre[min(i+B, N)]);
        best = max(best, *S.rbegin()-pre[i]);
    }

    printf("%lld\n", best);
}