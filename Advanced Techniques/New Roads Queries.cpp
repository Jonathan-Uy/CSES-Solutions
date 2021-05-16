#include <bits/stdc++.h>

using namespace std;
const int maxN = 4e5+1;

int N, M, Q, x, y, root, idcounter;

struct Node {
    bool rev = false;
    Node *c[2] = {nullptr, nullptr}, *p = nullptr;
    int val, mx, id = ++idcounter;

    Node(int v){
        val = mx = v;
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
        mx = val;
        for(int i = 0; i < 2; i++)
            if(c[i])
                mx = max(mx, c[i]->mx);
    }
} *LCT[maxN];

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

Node* LCA(Node *u, Node *v){
    evert(LCT[root]);
    access(u);
    return access(v);
}

bool connected(Node *u, Node *v){
    path(u, v);
    while(v->c[0])
        v = v->c[0];
    return u == v;
}

int main(){
    scanf("%d %d %d", &N, &M, &Q);
    for(int i = 1; i <= N; i++)
        LCT[i] = new Node(0);
    for(int i = 1; i <= M; i++){
        scanf("%d %d", &x, &y);
        LCT[N+i] = new Node(i);
        if(!connected(LCT[x], LCT[y])){
            link(LCT[x], LCT[N+i]);
            link(LCT[y], LCT[N+i]);
        }
    }

    root = 1;
    for(int q = 0; q < Q; q++){
        scanf("%d %d", &x, &y);
        if(connected(LCT[x], LCT[y])){
            Node *p = path(LCT[x], LCT[y]);
            printf("%d\n", p->mx);
        } else printf("-1\n");
    }
}
