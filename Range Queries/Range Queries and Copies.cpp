#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;

struct Node {
    Node *l, *r;
    int lo, hi;
    ll sum;
    Node(int low, int high, int val) : l(nullptr), r(nullptr), lo(low), hi(high), sum(val) {}
    Node(Node *left, Node *right) : l(left), r(right), sum(0) {
        if(left){
            sum += left->sum;
            lo = left->lo;
        }
        if(right){
            sum += right->sum;
            hi = right->hi;
        }
    }
};

int N, Q, type, k, a, b, x, cnt, t[maxN];
Node* seg[maxN];

Node* build(int l, int r){
    if(l == r)  return new Node(l, r, t[l]);
    int m = (l+r)/2;
    return new Node(build(l, m), build(m+1, r));
}

Node* update(Node* node, int idx, int val){
    if(node->lo == node->hi)    return new Node(idx, idx, val);
    int m = (node->lo+node->hi)/2;
    if(idx <= m)    return new Node(update(node->l, idx, val), node->r);
    else            return new Node(node->l, update(node->r, idx, val));
}

ll query(Node* node, int l, int r){
    if(l > node->hi || r < node->lo)    return 0;
    if(l <= node->lo && node->hi <= r)  return node->sum;
    return query(node->l, l, r) + query(node->r, l, r);
}

int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++)
        scanf("%d", &t[i]);

    cnt = 1;
    seg[cnt++] = build(1, N);
    for(int q = 0; q < Q; q++){
        scanf("%d %d", &type, &k);
        if(type == 1){
            scanf("%d %d", &a, &x);
            seg[k] = update(seg[k], a, x);
        } else if(type == 2){
            scanf("%d %d", &a, &b);
            printf("%lld\n", query(seg[k], a, b));
        } else if(type == 3){
            seg[cnt++] = new Node(seg[k]->l, seg[k]->r);
        }
    }
}
