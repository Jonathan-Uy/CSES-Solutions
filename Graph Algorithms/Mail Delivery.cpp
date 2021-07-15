#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 1e5+1;
const int maxM = 2e5+1;

int N, M, deg[maxN];
bool tour_exists, used[maxM];
vector<pii> G[maxN];
vector<int> tour;
stack<int> S;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a, b; i < M; i++){
        scanf("%d %d", &a, &b);
        G[a].push_back({b, i});
        G[b].push_back({a, i});
        deg[a]++; deg[b]++;
    }

    tour_exists = true;
    for(int i = 1; i <= N; i++)
        if(deg[i]&1)
            tour_exists = false;

    if(!tour_exists){
        printf("IMPOSSIBLE\n");
        return 0;
    }

    S.push(1);
    while(!S.empty()){
        int u = S.top();
        if(deg[u]){
            while(!G[u].empty()){
                int v = G[u].back().first;
                int id = G[u].back().second;
                G[u].pop_back();

                if(!used[id]){
                    deg[u]--; deg[v]--;
                    used[id] = true;
                    S.push(v);
                    break;
                }
            }
        } else {
            tour.push_back(u);
            S.pop();
        }
    }

    // Should be M+1 nodes in the Euler tour
    // If not, it means the graph was not connected
    if((int) tour.size() != M+1)
        printf("IMPOSSIBLE\n");
    else
        for(int i = 0; i <= M; i++)
            printf("%d%c", tour[i], (" \n")[i==M]);
}
