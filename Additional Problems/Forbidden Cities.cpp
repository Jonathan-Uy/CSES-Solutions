#include <bits/stdc++.h>
#define Task                    "A"
#define up(i,a,b)               for (int i = (a); i <= (b); i++)
using namespace std;

const int maxn = 100001;
vector<int> a[maxn];
vector<int> under[maxn];
int Tin[maxn], Tout[maxn], low[maxn], idx[maxn], par[maxn];
bool isJoint[maxn];
int tdfs, step;

void DFS(int u){
    low[u] = idx[u] = ++tdfs;
    Tin[u] = ++step;
    int child = bool(u != 1);
    for (int v : a[u]){
        if (par[u] == v) continue;
        if (!idx[v]){
            par[v] = u;
            DFS(v);

            low[u] = min(low[u], low[v]);
            under[u].emplace_back(v);
            if (low[v] >= idx[u]) child++;
        }
        else low[u] = min(low[u], idx[v]);
    }
    isJoint[u] = bool(child >= 2);
    Tout[u] = ++step;
}

bool inDfs(int u, int v){
    return (Tin[u] <= Tin[v] && Tout[v] <= Tout[u]);
}

bool comp(int x, int y){
    return (Tin[x] < Tin[y]);
}

int get_parent(int u, int v){
    if (!inDfs(u, v)) return -1;
    // if 'v' is outside 'u' in DFS tree, return "outside"
    int x = under[u][upper_bound(under[u].begin(), under[u].end(), v, comp) - under[u].begin() - 1];
    if (low[x] < idx[u]) return -1;
    // if 'x' still can go outside 'u', return "outside"
    return x;
}

bool Reachable(int A, int B, int C){
    if (A == C || B == C) return 0;
    if (!isJoint[C]) return 1;
    // if C is not a Cut-Vertex, there always have a path to come from A to B
    return (get_parent(C, A) == get_parent(C, B));
}

signed main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if (fopen(Task".inp", "r")){
        freopen (Task".inp", "r", stdin);
        freopen (Task".out", "w", stdout);
    }

    int n,m;
    int tt;
    cin >> n >> m >> tt;
    up(i, 1, m){
        int u,v;
        cin >> u >> v;
        a[u].emplace_back(v);
        a[v].emplace_back(u);
    }
    DFS(1);

    int A, B, C;
    while (tt--){
        cin >> A >> B >> C;
        cout << (Reachable(A, B, C) ? "YES" : "NO") << "\n";
    }
    return 0;
}
