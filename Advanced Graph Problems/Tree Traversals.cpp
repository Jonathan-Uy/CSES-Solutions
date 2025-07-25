#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5+5;

int N, timer, A[maxN], B[maxN], C[maxN], idx[maxN];
int L[maxN], R[maxN];

int solve(int l1 = 0, int r1 = N-1, int l2 = 0, int r2 = N-1){
    if(l1 > r1 || l2 > r2)  return 0;
    int root = A[l1];
    int m2 = idx[root];
    int len = m2-l2;
    L[root] = solve(l1+1, l1+len, l2, m2-1);
    R[root] = solve(l1+len+1, r1, m2+1, r2);
    return root;
}

void dfs(int u){
    if(L[u])    dfs(L[u]);
    if(R[u])    dfs(R[u]);
    C[timer++] = u;
}

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)  scanf("%d", &A[i]);
    for(int i = 0; i < N; i++){
        scanf("%d", &B[i]);
        idx[B[i]] = i;
    }

    int root = solve();
    dfs(root);
    for(int i = 0; i < N; i++)
        printf("%d%c", C[i], (" \n")[i==N-1]);
}