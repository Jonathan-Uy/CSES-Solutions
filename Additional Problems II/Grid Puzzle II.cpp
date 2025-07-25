#include <bits/stdc++.h>

using namespace std;
const int maxN = 105, maxM = 2605;
const int INF = 0x3f3f3f3f;

int N, K, rowtot, coltot, edgecnt, p[maxN], d[maxN];
bool inq[maxN], vis[maxM];
vector<int> path, G[maxN];

struct Edge {
    int u, v, r, c;
} edges[maxM], redges[maxM];

void read_input(){
    scanf("%d", &N);
    for(int v = 1, cap; v <= N; v++){
        scanf("%d", &cap);
        rowtot += cap;
        edgecnt++;
        G[0].push_back(edgecnt);
        G[v].push_back(-edgecnt);
        edges[edgecnt] = {0, v, cap, 0};
        redges[edgecnt] = {v, 0, 0, 0};
    }
    for(int u = N+1, cap; u <= 2*N; u++){
        scanf("%d", &cap);
        coltot += cap;
        edgecnt++;
        G[u].push_back(edgecnt);
        G[2*N+1].push_back(-edgecnt);
        edges[edgecnt] = {u, 2*N+1, cap, 0};
        redges[edgecnt] = {2*N+1, u, 0, 0};
    }
    for(int u = 1; u <= N; u++){
        for(int v = N+1, cost; v <= 2*N; v++){
            scanf("%d", &cost);
            edgecnt++;
            G[u].push_back(edgecnt);
            G[v].push_back(-edgecnt);
            edges[edgecnt] = {u, v, 1, -cost};
            redges[edgecnt] = {v, u, 0, cost};
        }
    }
}

void bellman_ford(int s = 0){
    fill(inq, inq+2*N+2, false);
    fill(d, d+2*N+2, INF);
    fill(p, p+2*N+2, 0);

    queue<int> Q;
    Q.push(s);
    d[s] = 0;
    inq[s] = true;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        inq[u] = false;

        for(int i : G[u]){
            Edge e = (i < 0 ? redges[-i] : edges[i]);
            if(e.r > 0 && d[e.v] > d[u] + e.c){
                d[e.v] = d[u] + e.c;
                p[e.v] = i;
                if(!inq[e.v]){
                    inq[e.v] = true;
                    Q.push(e.v);
                }
            }
        }
    }
}

int minimum_cost_flow(int s = 0, int t = 2*N+1){
    int flow = 0, cost = 0;
    while(flow < K){
        bellman_ford(s);
        if(d[t] == INF) break;

        int aug = K-flow;
        int u = t;
        while(u != s){
            Edge e = (p[u] < 0 ? redges[-p[u]] : edges[p[u]]);
            aug = min(aug, e.r);
            u = e.u;
        }

        flow += aug;
        cost += aug * d[t];
        u = t;
        while(u != s){
            if(p[u] < 0){
                redges[-p[u]].r -= aug;
                edges[-p[u]].r += aug;
            } else {
                redges[p[u]].r += aug;
                edges[p[u]].r -= aug;
            }
            u = (p[u] < 0 ? redges[-p[u]].u : edges[p[u]].u);
        }
    }
    return (flow < K ? INF : cost);
}

int main(){
    read_input();

    K = rowtot;
    int max_reward = -minimum_cost_flow();
    if(rowtot != coltot || max_reward == -INF){
        printf("-1\n");
        return 0;
    }

    printf("%d\n", max_reward);
    for(Edge e : edges){
        if(e.u != 0 && e.v != 2*N+1){
            printf("%c", (e.r == 0 ? 'X' : '.'));
            if(e.v == 2*N)  printf("\n");
        }
    }
}