#include <bits/stdc++.h>

using namespace std;
typedef array<int,3> triple;
const int maxN = 2e5+1;
const int SIZE = 2*maxN;

int N, ans[2][maxN], ds[SIZE];
triple intervals[maxN];
set<int> unique_vals;
map<int,int> mp;

void update(int idx, int val){
    for(int i = idx; i < SIZE; i += -i&i)   ds[i] += val;
}

int query(int idx){
    int cnt = 0;
    for(int i = idx; i > 0; i -= -i&i)
        cnt += ds[i];
    return cnt;
}

int main(){
    scanf("%d", &N);
    for(int i = 0, x, y; i < N; i++){
        scanf("%d %d", &x, &y);
        intervals[i] = {x, y, i};
        unique_vals.insert(x);
        unique_vals.insert(y);
    }
    sort(intervals, intervals+N, [](triple A, triple B){
        return (A[0] == B[0] ? A[1] > B[1] : A[0] < B[0]);
    });

    int val_id = 1;
    for(int x : unique_vals)
        mp[x] = val_id++;

    for(int i = N-1; i >= 0; i--){
        int y = mp[intervals[i][1]];
        int id = intervals[i][2];

        ans[0][id] = query(y);
        update(y, 1);
    }

    fill(ds, ds+SIZE, 0);
    for(int i = 0; i < N; i++){
        int y = mp[intervals[i][1]];
        int id = intervals[i][2];

        ans[1][id] = i-query(y-1);
        update(y, 1);
    }

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < N; j++)
            printf("%d%c", (ans[i][j] ? 1 : 0), (" \n")[j==N-1]);
}