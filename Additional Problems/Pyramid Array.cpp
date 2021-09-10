#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 2e5+1;

int N, ds[maxN];
pii X[maxN];

void update(int idx){
    for(int i = idx; i <= N; i += -i&i) ds[i]++;
}

int query(int idx){
    int cnt = 0;
    for(int i = idx; i; i -= -i&i)
        cnt += ds[i];
    return cnt;
}

int main(){
    scanf("%d", &N);
    for(int i = 0, x; i < N; i++){
        scanf("%d", &x);
        X[i] = {x, i+1};
    }
    sort(X, X+N, [](pii a, pii b){
        return a.first > b.first;
    });

    long long ans = 0;
    for(int k = 0; k < N; k++){
        int idx = X[k].second;
        int l = query(idx);
        ans += min(l, k-l);
        update(idx);
    }
    printf("%lld\n", ans);
}