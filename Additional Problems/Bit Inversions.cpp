#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
const int SIZE = 4*maxN;

int N, M, mp[maxN], lo[SIZE], hi[SIZE], dp[3][SIZE];
char S[maxN];

int len(int i){
    return hi[i]-lo[i]+1;
}

int combine(int a, int b){
    return ((a<0)^(b<0)) ? a : a+b;
}

bool allsame(int i){
    return abs(dp[2][i]) == len(i);
}

void pull(int i){
    dp[0][i] = (allsame(2*i) ? combine(dp[0][2*i], dp[0][2*i+1]) : dp[0][2*i]);
    dp[1][i] = (allsame(2*i+1) ? combine(dp[1][2*i+1], dp[1][2*i]) : dp[1][2*i+1]);
    dp[2][i] = max(abs(combine(dp[1][2*i], dp[0][2*i+1])), max(dp[2][2*i], dp[2][2*i+1]));
}

void init(int i, int l, int r){
    lo[i] = l; hi[i] = r;
    if(l == r){
        mp[l] = i;
        dp[0][i] = dp[1][i] = (S[l-1] == '0' ? -1 : 1);
        dp[2][i] = abs(dp[0][i]);
        return;
    }
    int m = (l+r)/2;
    init(2*i, l, m);
    init(2*i+1, m+1, r);
    pull(i);
}

void update(int idx){
    int i = mp[idx];
    dp[0][i] *= -1;
    dp[1][i] = dp[0][i];

    i >>= 1;
    while(i){
        pull(i);
        i >>= 1;
    }
}

int query(){
    return dp[2][1];
}

int main(){
    scanf("%s %d", S, &M);
    N = (int) strlen(S);
    init(1, 1, N);
    for(int i = 0, x; i < M; i++){
        scanf("%d", &x);
        update(x);
        printf("%d%c", query(), (" \n")[i==M-1]);
    }
}
