#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e5+5;

struct Node {
    ll dp;
    int len, link;
    map<char,int> nxt;
} node[2*maxN];

vector<char> ans;
char S[maxN];
int N, sz, last;
ll K;

void init(){
    node[0].len = 0;
    node[0].link = -1;
    sz = 1;
    last = 0;
}

void extend(char c){
    int cur = sz++;
    node[cur].len = node[last].len + 1;
    int p = last;
    while(p != -1 && !node[p].nxt.count(c)){
        node[p].nxt[c] = cur;
        p = node[p].link;
    }
    if(p == -1){
        node[cur].link = 0;
    } else {
        int q = node[p].nxt[c];
        if(node[p].len + 1 == node[q].len){
            node[cur].link = q;
        } else {
            int clone = sz++;
            node[clone].len = node[p].len + 1;
            node[clone].nxt = node[q].nxt;
            node[clone].link = node[q].link;
            while(p != -1 && node[p].nxt[c] == q){
                node[p].nxt[c] = clone;
                p = node[p].link;
            }
            node[q].link = node[cur].link = clone;
        }
    }
    last = cur;
}

void calc(int u = 0){
    node[u].dp = 1;
    for(const auto& [c, v] : node[u].nxt){
        if(!node[v].dp) calc(v);
        node[u].dp += node[v].dp;
    }
}

void dfs(int u, ll k){
    if(k < 0)   return;
    for(const auto& [c, v] : node[u].nxt){
        if(node[v].dp <= k) k -= node[v].dp;
        else {
            ans.push_back(c);
            dfs(v, k-1);
            return;
        }
    }
}

int main(){
    scanf(" %s %lld", S, &K);
    N = (int) strlen(S);

    init();
    for(int i = 0; i < N; i++)
        extend(S[i]);
    calc();

    dfs(0, K-1);
    int M = (int) ans.size();
    for(int i = 0; i < M; i++)
        printf("%c", ans[i]);
    printf("\n");
}