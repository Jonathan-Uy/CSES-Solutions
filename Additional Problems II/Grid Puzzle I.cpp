#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 105, maxM = 2605;
const int INF = 0x3f3f3f3f;

int N, rowTot, colTot, edgeID, p[maxN], cap[maxN][maxN];
bool vis[maxM];
vector<int> path, F[maxN];
vector<pii> G[maxN];

int bfs(int s = 0, int t = 2*N+1){
    fill(p, p+2*N+2, -1);
    p[s] = -2;

    queue<pii> Q;
    Q.push({s, INF});
    while(!Q.empty()){
        int u = Q.front().first;
        int f = Q.front().second;
        Q.pop();

        for(int v : F[u]){
            if(p[v] == -1 && cap[u][v]){
                p[v] = u;
                int aug = min(f, cap[u][v]);
                if(v == t)  return aug;
                Q.push({v, aug});
            }
        }
    }

    return 0;
}

void dfs(int u = 0){
    path.push_back(u);
    if(u == N)  return;
    for(pii e : G[u]){
        int v = e.first;
        int id = e.second;
        if(cap[u][v] == 0 && !vis[id]){
            vis[id] = true;
            dfs(v);
            return;
        }
    }
}

int maxflow(int s = 0, int t = 2*N+1){
    int flow = 0, aug = 0;
    while(aug = bfs()){
        flow += aug;
        int u = t;
        while(u != s){
            int v = p[u];
            cap[v][u] -= aug;
            cap[u][v] += aug;
            u = v;
        }
    }
    return flow;
}

int main(){
    scanf("%d", &N);
    for(int i = 1, c; i <= N; i++){
        scanf("%d", &c);
        G[0].push_back({i, ++edgeID});
        F[0].push_back(i);
        F[i].push_back(0);
        cap[0][i] += c;
        rowTot += c;
    }
    for(int i = N+1, c; i <= 2*N; i++){
        scanf("%d", &c);
        G[i].push_back({2*N+1, ++edgeID});
        F[i].push_back(2*N+1);
        F[2*N+1].push_back(i);
        cap[i][2*N+1] += c;
        colTot += c;
    }
    for(int i = 1; i <= N; i++){
        for(int j = N+1; j <= 2*N; j++){
            G[i].push_back({j, ++edgeID});
            F[i].push_back(j);
            F[j].push_back(i);
            cap[i][j]++;
        }
    }

    int K = maxflow();
    if(rowTot != colTot || K != rowTot){
        printf("-1\n");
        return 0;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            printf("%c", (cap[i][j+N] ? '.' : 'X'));
        printf("\n");
    }
}