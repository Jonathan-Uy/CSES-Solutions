#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef array<int,3> triple;
const int maxN = 1e5+1;
const int SIZE = 3e5+1;
const int INF = 0x3f3f3f3f;

int N, M, K, root, components, del_time[SIZE];
bool used[SIZE];
pii edges[SIZE];
triple ops[maxN];
map<pii,deque<int>> edge_id_map;

struct Node {
    bool rev = false;
    Node *c[2] = {nullptr, nullptr}, *p = nullptr;
    int mn, id;

    Node(int i){
        mn = id = i;
    }

    void push(){
        if(rev){
            swap(c[0], c[1]);
            if(c[0])    c[0]->rev ^= true;
            if(c[1])    c[1]->rev ^= true;
            rev = false;
        }
    }

    void pull(){
        mn = id;
        for(int i = 0; i < 2; i++)
            if(c[i] && del_time[c[i]->mn] < del_time[mn])
                mn = c[i]->mn;
    }
} *LCT[SIZE];

bool notRoot(Node *t){
    return t->p && (t->p->c[0] == t || t->p->c[1] == t);
}

void rotate(Node *t){
    Node *p = t->p;
    bool b = (p->c[0] == t);
    if((t->p = p->p) && notRoot(p)) t->p->c[(t->p->c[1] == p)] = t;
    if((p->c[!b]=t->c[b]))          p->c[!b]->p = p;
    t->c[b] = p;
    p->p = t;
    p->pull();
}


void splay(Node *t){
    while(notRoot(t)){
        Node *p = t->p;
        p->push();
        t->push();
        rotate(t);
    }
    t->push();
    t->pull();
}

Node* access(Node *t){
    Node *last = nullptr;
    for(Node *u = t; u; u = u->p){
        splay(u);
        u->c[1] = last;
        last = u;
    }
    splay(t);
    return last;
}

void evert(Node *t){
    access(t);
    t->rev = true;
}

void link(Node *u, Node *v){
    evert(u);
    u->p = v;
}

void cut(Node *u, Node *v){
    evert(u);
    access(v);
    if(v->c[0]) v->c[0]->p = 0;
    v->c[0] = 0;
    v->pull();
}

Node* path(Node *u, Node *v){
    evert(u);
    access(v);
    return v;
}

bool connected(Node *u, Node *v){
    path(u, v);
    while(v->c[0])
        v = v->c[0];
    return u == v;
}

void create_edge(int u, int v){
    int id = edge_id_map[{u, v}].front();
    if(!connected(LCT[u], LCT[v])){
        components--;
        link(LCT[id], LCT[u]);
        link(LCT[id], LCT[v]);
        used[id] = true;
    } else {
        int mn = path(LCT[u], LCT[v])->mn;
        if(del_time[mn] < del_time[id]){
            int cu = edges[mn].first;
            int cv = edges[mn].second;
            cut(LCT[mn], LCT[cu]);
            cut(LCT[mn], LCT[cv]);
            used[mn] = false;
            link(LCT[id], LCT[u]);
            link(LCT[id], LCT[v]);
            used[id] = true;
        }
    }
}

void destroy_edge(int u, int v){
    int id = edge_id_map[{u, v}].front();
    edge_id_map[{u, v}].pop_front();
    if(!used[id])   return;
    cut(LCT[id], LCT[u]);
    cut(LCT[id], LCT[v]);
    used[id] = false;
    components++;
}

int main(){
    scanf("%d %d %d", &N, &M, &K);

    root = 1;
    for(int i = 1; i <= N; i++){
        LCT[i] = new Node(i);
        del_time[i] = INF;
    }

    for(int i = 1, a, b; i <= M; i++){
        scanf("%d %d", &a, &b);
        if(a > b)   swap(a, b);
        edges[N+i] = {a, b};
        del_time[N+i] = INF;
        LCT[N+i] = new Node(N+i);
        edge_id_map[{a, b}].push_back(N+i);
    }

    for(int i = 1, t, a, b; i <= K; i++){
        scanf("%d %d %d", &t, &a, &b);
        if(a > b)   swap(a, b);
        ops[i] = {t, a, b};
        edges[N+M+i] = {a, b};

        if(t == 2){
            int id = edge_id_map[{a, b}].back();
            del_time[id] = i;
        } else {
            del_time[N+M+i] = INF;
            LCT[N+M+i] = new Node(N+M+i);
            edge_id_map[{a, b}].push_back(N+M+i);
        }
    }

    components = N;
    for(int i = N+1; i <= N+M; i++){
        int u = edges[i].first;
        int v = edges[i].second;
        create_edge(u, v);
    }
    printf("%d ", components);

    for(int i = 1; i <= K; i++){
        int t = ops[i][0];
        int u = ops[i][1];
        int v = ops[i][2];
        if(t == 1)  create_edge(u, v);
        else        destroy_edge(u, v);
        printf("%d%c", components, (" \n")[i==K]);
    }
}