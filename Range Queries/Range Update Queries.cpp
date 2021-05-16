#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;

int N, Q, t, a, b, k;
ll x, ds[maxN];

void update(int idx, ll val){
    for(int i = idx; i <= N; i += -i&i)
        ds[i] += val;
}

ll query(int idx){
    ll sum = 0;
    for(int i = idx; i > 0; i -= -i&i)
        sum += ds[i];
    return sum;
}

int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++){
        scanf("%lld", &x);
        update(i, x);
        update(i+1, -x);
    }
    for(int q = 0; q < Q; q++){
        scanf("%d", &t);
        if(t == 1){
            scanf("%d %d %lld", &a, &b, &x);
            update(b+1, -x);
            update(a, x);
        } else if(t == 2){
            scanf("%d", &k);
            printf("%lld\n", query(k));
        }
    }
}
