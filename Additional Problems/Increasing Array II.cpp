#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, x;
priority_queue<int> Q;

int main(){
    scanf("%d", &N);
    ll ans = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        Q.push(x);
        ans += Q.top() - x;
        Q.pop();
        Q.push(x);
    }
    printf("%lld\n", ans);
}