#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+5;
const ll MOD = 1e9+7;

int N;
ll ans, ds[maxN];
struct Operation { int x, idx; } ops[maxN];

void update(int idx, ll val){
    for(int i = idx; i < maxN; i += -i&i)
        ds[i] = (ds[i] + val) % MOD;
}

ll query(int idx){
    ll sum = 0;
    for(int i = idx; i > 0; i -= -i&i)
        sum = (sum + ds[i]) % MOD;
    return sum;
}

int main(){
    scanf("%d", &N);
    for(int i = 0, x; i < N; i++){
        scanf("%d", &x);
        ops[i] = {x, i+1};
    }
    sort(ops, ops+N, [](Operation A, Operation B){
        return A.x == B.x ? B.idx < A.idx : A.x < B.x;
    });

    for(int i = 0; i < N; i++){
        int idx = ops[i].idx;
        ll amnt = query(idx)+1;
        ans = (ans + amnt) % MOD;
        update(idx, amnt);
    }
    printf("%lld\n", ans);
}