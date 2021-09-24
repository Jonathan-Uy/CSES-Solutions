#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;

struct Node {
    int len, link, cnt, firstpos;
    map<char,int> nxt;
} node[2*maxN];

char S[maxN];
bool vis[2*maxN];
int N, sz, last, bestidx, bestlen;

void extend(char c){
    int cur = sz++;
    node[cur].cnt = 1;
    node[cur].firstpos = node[last].len;
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
            node[clone].firstpos = node[q].firstpos;
            while(p != -1 && node[p].nxt[c] == q){
                node[p].nxt[c] = clone;
                p = node[p].link;
            }
            node[q].link = node[cur].link = clone;
        }
    }
    last = cur;
}

void init(){
    node[0].len = 0;
    node[0].link = -1;
    sz = 1;
    last = 0;
}

void update_cnts(){
    vector<int> states_by_len[sz];
    for(int i = 0; i < sz; i++)
        states_by_len[node[i].len].push_back(i);
    for(int i = sz-1; i >= 0; i--)
        for(int u : states_by_len[i])
            if(node[u].link != -1)
                node[node[u].link].cnt += node[u].cnt;
}

void dfs(int u = 0){
    vis[u] = true;
    if(node[u].len > bestlen && node[u].cnt > 1 && u != 0){
        bestidx = node[u].firstpos - node[u].len + 1;
        bestlen = node[u].len;
    }
    for(const auto& [c, v] : node[u].nxt)
        if(!vis[v])
            dfs(v);
}

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);

    init();
    for(int i = 0; i < N; i++)
        extend(S[i]);
    update_cnts();

    bestlen = -1;
    dfs();

    if(bestlen == -1)   printf("-1\n");
    else {
        for(int i = 0; i < bestlen; i++)
            printf("%c", S[bestidx+i]);
    }
}