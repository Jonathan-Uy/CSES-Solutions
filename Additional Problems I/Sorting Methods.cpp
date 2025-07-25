#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+5;

int N, x[maxN], ds[maxN];
ll bit[maxN], ans[4];
set<int> S;
set<int>::iterator it;

int find(int u){
    if(ds[u] < 0)   return u;
    ds[u] = find(ds[u]);
    return ds[u];
}

bool merge(int u, int v){
    u = find(u); v = find(v);
    if(u == v)  return false;
    if(ds[u] < ds[v])   swap(u, v);
    ds[v] += ds[u];
    ds[u] = v;
    return true;
}

void update(int idx, int val){
    for(int i = idx; i < maxN; i += -i&i)
        bit[i] += val;
}

ll query(int idx){
    int sum = 0;
    for(int i = idx; i > 0; i -= -i&i)
        sum += bit[i];
    return sum;
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &x[i]);

    int K = N;
    ans[3] = N;
    fill(ds+1, ds+N+1, -1);
    for(int i = 1; i <= N; i++){
        ans[0] += (i-query(x[i])-1);
        update(x[i], 1);

        if(!merge(i, x[i]))
            ans[1] += (-ds[find(i)]-1);

        S.insert(x[i]);
        it = S.lower_bound(x[i]);
        if(++it != S.end())
            S.erase(it);

        if(x[N-i+1] == K){
            K--;
            ans[3]--;
        }
    }
    ans[2] = N - (int) S.size();

    for(int i = 0; i < 4; i++)
        printf("%lld%c", ans[i], (" \n")[i==3]);
}