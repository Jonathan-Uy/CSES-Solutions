#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;

struct Node {
    int len, link, cnt, firstpos;
    map<char,int> nxt;
} node[2*maxN];

char S[maxN], T[5*maxN];
int N, M, K, sz, last;

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

int query_cnt(){
    int u = 0;
    for(int i = 0; i < M; i++){
        char c = T[i];
        if(!node[u].nxt.count(c))   return 0;
        else                        u = node[u].nxt[c];
    }
    return node[u].cnt;
}

int query_idx(){
    int u = 0;
    for(int i = 0; i < M; i++){
        char c = T[i];
        if(!node[u].nxt.count(c))   return -1;
        else                        u = node[u].nxt[c];
    }
    return node[u].firstpos-M+2;
}

int main(){
    scanf(" %s %d", S, &K);
    N = (int) strlen(S);

    init();
    for(int i = 0; i < N; i++)
        extend(S[i]);
    update_cnts();

    for(int i =  0; i < K; i++){
        scanf(" %s", T);
        M = (int) strlen(T);
        printf("%d\n", query_idx());
    }
}