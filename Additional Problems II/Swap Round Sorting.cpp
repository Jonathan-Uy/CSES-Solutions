#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 2e5+1;

bool vis[maxN];
int N, a[maxN];
vector<int> cycle;
vector<pii> ans;

bool zero_rounds(){
    for(int i = 1; i <= N; i++)
        if(a[i] != i)
            return false;

    printf("0\n");
    return true;
}

bool one_round(bool second = false){
    for(int i = 1; i <= N; i++){
        if(a[i] != i){
            if(i != a[a[i]])    { ans.clear(); return false; }
            else if(i < a[i])   ans.push_back({i, a[i]});
        }
    }

    if(!second) printf("1\n");
    printf("%d\n", (int) ans.size());
    for(pii p : ans){
        printf("%d %d\n", p.first, p.second);
        swap(a[p.first], a[p.second]);
    }
    return true;
}

void dfs(int u){
    vis[u] = true;
    cycle.push_back(u);
    if(!vis[a[u]])  dfs(a[u]);
}

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &a[i]);

    if(!zero_rounds() && !one_round()){
        printf("2\n");

        for(int i = 1; i <= N; i++){
            if(!vis[i]){
                dfs(i);
                int K = (int) cycle.size();
                for(int u = 0; u < K/2; u++){
                    ans.push_back({cycle[u], cycle[K-u-1]});
                    swap(a[cycle[u]], a[cycle[K-u-1]]);
                }
                cycle.clear();
            }
        }

        printf("%d\n", (int) ans.size());
        for(pii p : ans)
            printf("%d %d\n", p.first, p.second);

        ans.clear();
        one_round(true);
    }
}