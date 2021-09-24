#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(1, (int) 2e9);

struct Node {
    bool rev;
    char ch;
    int prior, sz;
    Node *l, *r;

    Node(){}
    Node(char c, int p){
        prior = p;
        ch = c;
        sz = 1;
        l = r = nullptr;
    }
};

int N, M, a, b;
char S[maxN];
Node *root;

int sz(Node *t){ return t ? t->sz : 0; }

void flip(Node *t){
    if(!t)  return;
    t->rev ^= true;
}

void pull(Node *t){
    if(!t)  return;
    t->sz = sz(t->l) + sz(t->r) + 1;
}

void push(Node *t){
    if(!t)  return;
    if(t->rev){
        swap(t->l, t->r);
        flip(t->l); flip(t->r);
        t->rev = false;
    }
}

Node* merge(Node *x, Node *y){
    if(!x || !y)    return x ? x : y;

    push(x); push(y);
    if(x->prior < y->prior){
        x->r = merge(x->r, y);
        pull(x);
        return x;
    } else {
        y->l = merge(x, y->l);
        pull(y);
        return y;
    }
}

pair<Node*,Node*> split(Node *x, int k){
    if(!x)  return {nullptr, nullptr};

    pair<Node*,Node*> y = {nullptr, nullptr};
    push(x);
    if(k <= sz(x->l)){
        y = split(x->l, k);
        x->l = y.second;
        pull(x);
        y.second = x;
    } else {
        y = split(x->r, k-sz(x->l)-1);
        x->r = y.first;
        pull(x);
        y.first = x;
    }
    return y;
}

void heapify(Node *t){
    if(!t)  return;

    Node *mx = t;
    if(t->l && t->l->prior > mx->prior) mx = t->l;
    if(t->r && t->r->prior > mx->prior) mx = t->r;
    if(mx != t){
        swap(t->prior, mx->prior);
        heapify(mx);
    }
}

Node* build(int x, int k){
    if(k == 0)  return nullptr;

    int mid = k/2;
    Node *t = new Node(S[x+mid], dist(rng));
    t->l = build(x, mid);
    t->r = build(x+mid+1, k-mid-1);
    heapify(t);
    pull(t);
    return t;
}

void reverse(int x, int k){
    pair<Node*,Node*> y, z;
    y = split(root, x-1);
    z = split(y.second, k);
    flip(z.first);
    y.second = merge(z.first, z.second);
    root = merge(y.first, y.second);
}

void print(Node *t){
    if(!t)  return;
    push(t);
    print(t->l);
    printf("%c", t->ch);
    print(t->r);
}

int main(){
    scanf("%d %d %s", &N, &M, S);
    root = build(0, N);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        int len = (b-a+1);
        reverse(a, len);
    }
    print(root);
}
