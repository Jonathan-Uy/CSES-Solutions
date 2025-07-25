#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int N;
ll l1, l2, l3, l4;

int main(){
    scanf("%d", &N);

    l1 = l4 = -INF;
    l2 = l3 = INF;

    for(int i = 0; i < N; i++){
        ll x, y;
        scanf("%lld %lld", &x, &y);

        l1 = max(l1, x+y);
        l2 = min(l2, x+y);
        l3 = min(l3, x-y);
        l4 = max(l4, x-y);

        printf("%lld\n", max(l1-l2, l4-l3));
    }
}