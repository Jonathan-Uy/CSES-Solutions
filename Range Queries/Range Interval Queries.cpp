#include <bits/stdc++.h>

using namespace std;
typedef array<int,5> operation;
const int maxN = 2e5+5;

int N, Q, ds[maxN], ans[maxN];
vector<operation> ops;

void update(int idx, int val){
    for(int i = idx; i <= N; i += -i&i)
        ds[i] += val;
}

int query(int idx){
    int sum = 0;
    for(int i = idx; i > 0; i -= -i&i)
        sum += ds[i];
    return sum;
}

int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 1, x; i <= N; i++){
        scanf("%d", &x);
        ops.push_back({x, 0, i, i, -1});
    }
    for(int q = 1, a, b, c, d; q <= Q; q++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        ops.push_back({c, -1, a, b, q});
        ops.push_back({d, 1, a, b, q});
    }

    sort(ops.begin(), ops.end());
    for(operation op : ops){
        int type = op[1];
        if(type == 0)   update(op[2], 1);
        else {
            int a = op[2], b = op[3], qid = op[4];
            int cnt = query(b) - query(a-1);
            ans[qid] += type * cnt;
        }
    }

    for(int q = 1; q <= Q; q++)
        printf("%d\n", ans[q]);
}