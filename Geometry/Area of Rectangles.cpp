#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<int,4> Operation;
const int maxN = 1e5;
const int SZ = 9e6;

int N, lo[SZ], hi[SZ];
ll area, delta[SZ], score[SZ];
Operation op[2*maxN];

int len(int i){
    return hi[i]-lo[i]+1;
}

void pull(int i){
    if(lo[i] == hi[i])  score[i] = (delta[i] > 0 ? 1 : 0);
    else                score[i] = (delta[i] > 0 ? len(i) : score[2*i] + score[2*i+1]);
}

void build(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r)  return;
    int m = l+(r-l)/2;
    build(2*i, l, m);
    build(2*i+1, m+1, r);
}

void increment(int i, int l, int r, ll val){
    if(l > hi[i] || r < lo[i])  return;
    if(l <= lo[i] && hi[i] <= r){
        delta[i] += val;
        pull(i);
        return;
    }
    increment(2*i, l, r, val);
    increment(2*i+1, l, r, val);
    pull(i);
}

ll query(){
    return score[1];
}

int main(){
    scanf("%d", &N);
    for(int i = 0, a, b, c, d; i < N; i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        op[2*i] = {1, b, a+1, c};
        op[2*i+1] = {-1, d, a+1, c};
    }
    sort(op, op+2*N, [](Operation A, Operation B){
       return (A[1] == B[1] ? A[0] < B[0] : A[1] < B[1]);
    });

    build(1, -1e6-5, 1e6+5);
    int lst = -1e6;
    for(int i = 0; i < 2*N; i++){
        int t = op[i][0], y = op[i][1], x1 = op[i][2], x2 = op[i][3];
        area += (y-lst) * query();
        increment(1, x1, x2, t);
        lst = y;
    }

    printf("%lld\n", area);
}