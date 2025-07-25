#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node *c[2];
};

int N, xum, best;
Node *root;

void update(int x){
    Node *cur = root;
    for(int i = 30; i >= 0; i--){
        if(x&(1<<i)){
            if(!cur->c[1])  cur->c[1] = new Node();
            cur = cur->c[1];
        } else {
            if(!cur->c[0])  cur->c[0] = new Node();
            cur = cur->c[0];
        }
    }
}

int query(int x){
    int res = 0;
    Node *cur = root;
    for(int i = 30; i >= 0; i--){
        if(x&(1<<i)){
            if(cur->c[0]){
                res += (1<<i);
                cur = cur->c[0];
            } else cur = cur->c[1];
        } else {
            if(cur->c[1]){
                res += (1<<i);
                cur = cur->c[1];
            } else cur = cur->c[0];
        }
    }
    return res;
}

int main(){
    scanf("%d", &N);
    root = new Node();
    update(0);
    for(int i = 0, x; i < N; i++){
        scanf("%d", &x);
        xum ^= x;
        update(xum);
        best = max(best, query(xum));
    }
    printf("%d\n", best);
}
