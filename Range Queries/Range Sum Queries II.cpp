#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5;

int N, Q, t, a, b;
ll x[maxN+1], ds[maxN+1];

void update(int idx, ll val){
    ll diff = val - x[idx];
    for(int i = idx; i <= N; i += -i&i)
        ds[i] += diff;
    x[idx] = val;
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
        scanf("%lld", &x[0]);
        update(i, x[0]);
    }
    for(int q = 0; q < Q; q++){
        scanf("%d %d %d", &t, &a, &b);
        if(t == 1)  update(a, b);
        else        printf("%lld\n", query(b)-query(a-1));
    }
}
