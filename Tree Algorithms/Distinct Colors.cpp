#include <bits/stdc++.h>

using namespace std;
typedef array<int,3> triple;
const int maxN = 2e5+1;

int N, a, b, c[maxN], x[2*maxN], ptr[2*maxN], ds[2*maxN], ans[maxN];
int timer, in[maxN], out[maxN];
triple queries[maxN];
vector<int> G[maxN];
map<int,int> mp;
set<int> S;

void dfs(int u = 1, int p = 0){
    in[u] = ++ timer;
    for(int v : G[u])
        if(v != p)
            dfs(v, u);
    out[u] = ++timer;
}

void update(int idx, int val){
    for(int i = idx; i <= 2*N; i += -i&i)
        ds[i] += val;
}

int query(int idx){
    int sum = 0;
    for(int i = idx; i > 0; i -= -i&i)
        sum += ds[i];
    return sum;
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &c[i]);

    for(int i = 0; i < N-1; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs();

    for(int i = 1; i <= N; i++)
        x[in[i]] = x[out[i]] = c[i];

    for(int i = 2*N; i > 0; i--){
        if(mp[x[i]])
            ptr[i] = mp[x[i]];
        mp[x[i]] = i;
    }

    for(int i = 1; i <= 2*N; i++){
        if(S.count(x[i]) == 0)
            update(i, 1);
        S.insert(x[i]);
    }

    for(int i = 1; i <= N; i++)
        queries[i-1] = {in[i], out[i], i-1};
    sort(queries, queries+N);

    int l = 1;
    for(int i = 0; i < N; i++){
        while(l < queries[i][0]){
            if(ptr[l])
                update(ptr[l], 1);
            l++;
        }
        ans[queries[i][2]] = query(queries[i][1]) - query(queries[i][0]-1);
    }

    for(int i = 0; i < N; i++)
        printf("%d%c", ans[i], (" \n")[i==N-1]);
}
