#include <bits/stdc++.h>

/**
 * Link Cut Tree
 */

using namespace std;
const int maxN = 2e5+1;

int N, Q, k, x, y, root, idcounter;

struct Lazy {
    int a = 1, b = 0;
    bool empty(){
        return (a == 1 && b == 0);
    }
};

struct Node {
    Lazy tag;
    bool rev = false;
    Node *c[2] = {nullptr, nullptr}, *p = nullptr;
    int sz, val, sum, mn, mx, id = ++idcounter;

    Node(int v){
        sz = 1;
        val = sum = mn = mx = v;
    }

    void apply(Lazy other){
        mn = mn*other.a + other.b;
        mx = mx*other.a + other.b;
        val = val*other.a + other.b;
        sum = sum*other.a + sz*other.b;
        tag = {tag.a*other.a, tag.b*other.a+other.b};
    }

    void push(){
        if(rev){
            swap(c[0], c[1]);
            if(c[0])    c[0]->rev ^= true;
            if(c[1])    c[1]->rev ^= true;
            rev = false;
        }
        if(!tag.empty()){
            if(c[0])    c[0]->apply(tag);
            if(c[1])    c[1]->apply(tag);
            tag = Lazy();
        }
    }

    void pull(){
        sum = mn = mx = val;
        sz = 1;
        for(int i = 0; i < 2; i++){
            if(c[i]){
                mn = min(mn, c[i]->mn);
                mx = max(mx, c[i]->mx);
                sum += c[i]->sum;
                sz += c[i]->sz;
            }
        }
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
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++){
        scanf("%d", &x);
        LCT[i] = new Node(x);
    }
    for(int i = 0; i < N-1; i++){
        scanf("%d %d", &x, &y);
        link(LCT[x], LCT[y]);
    }

    root = 1;
    for(int i = 0; i < Q; i++){
        scanf("%d", &k);
        if(k == 1){
            scanf("%d %d", &x, &y);
            Node *p = path(LCT[x], LCT[x]);
            p->apply({0, y});
        } else if(k == 2){
            scanf("%d %d", &x, &y);
            Node *p = path(LCT[x], LCT[y]);
            printf("%d ", p->mx);
        }
    }
}
