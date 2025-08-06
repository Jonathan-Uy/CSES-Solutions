#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

struct Line {
    ll a, b;

    Line() : a(0), b(-INF) {}
    Line(ll a, ll b) : a(a), b(b) {}

    ll get(ll x){
        return a * x + b;
    }
};

struct Node {
    Line line = Line();
    Node* lc = nullptr;
    Node* rc = nullptr;
};

struct LiChaoTree {
    Node* root;
    ll size;
    LiChaoTree(ll size) : root(nullptr), size(size) {}

  private:
    void contained_insert(Node* &node, ll tl, ll tr, Line line){
        if(node == nullptr)     node = new Node();
        if(node->line.get(tl) < line.get(tl))   swap(node->line, line);
        if(node->line.get(tr) >= line.get(tr))  return;
        if(tl == tr)    return;

        ll tm = (tl + tr) / 2;
        if(node->line.get(tm) > line.get(tm)) {
            contained_insert(node->rc, tm+1, tr, line);
        } else {
            swap(node->line, line);
            contained_insert(node->lc, tl, tm, line);
        }
    }

    void insert(Node* &node, ll tl, ll tr, ll l, ll r, Line line){
        if(tr < l || r < tl || tl > tr || l > r) return;
        if(node == nullptr)     node = new Node();
        if(l <= tl && tr <= r)  return contained_insert(node, tl, tr, line);

        ll tm = (tl + tr) / 2;
        insert(node->lc, tl, tm, l, r, line);
        insert(node->rc, tm+1, tr, l, r, line);
    }

    ll query(Node* &node, ll tl, ll tr, ll x) {
        if(node == nullptr) return -INF;
        if(tl == tr)        return node->line.get(x);

        ll res = node->line.get(x);
        ll tm = (tl + tr) / 2;
        if(x <= tm) res = max(res, query(node->lc, tl, tm, x));
        else        res = max(res, query(node->rc, tm+1, tr, x));

        return res;
    }

  public:
    void insert(ll l, ll r, Line line) {
        insert(root, 0, size-1, l, r, line);
    }

    ll query(ll x) {
        return query(root, 0, size-1, x);
    }
};


int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    LiChaoTree tree(M+1);

    for(int i = 0, y1, y2; i < N; i++){
        scanf("%d %d", &y1, &y2);

        ll m = (y2 - y1) / M;
        tree.insert(0, M, Line(m, y1));
    }

    for(int x = 0; x <= M; x++){
        ll res = tree.query(x);
        printf("%lld%c", (res == -INF ? -1 : res), (" \n")[x==M]);
    }
}