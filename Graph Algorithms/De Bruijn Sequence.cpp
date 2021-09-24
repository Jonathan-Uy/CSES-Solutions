#include <bits/stdc++.h>

using namespace std;
const int maxN = 15;
const int SIZE = (1<<maxN)+maxN;

char ans[SIZE];
int N, ansptr;
vector<int> G[SIZE];
stack<int> S;

void init(){
    for(int u = 0; u < 1<<(N-1); u++){
        int v = (u<<1)%(1<<(N-1));
        G[u].push_back(v);
        G[u].push_back(v|1);
    }
}

void solve(){
    S.push(0);
    while(!S.empty()){
        int u = S.top();
        if(!G[u].empty()){
            int v = G[u].back();
            G[u].pop_back();
            S.push(v);
        } else {
            ans[ansptr++] = (char) (u&1) + '0';
            S.pop();
        }
    }
    for(int i = 0; i < N-2; i++)
        ans[ansptr++] = '0';
}

int main(){
    scanf("%d", &N);
    if(N == 1){
        printf("01");
        return 0;
    }

    init();
    solve();
    for(int i = 0; i < ansptr; i++)
        printf("%c", ans[i]);
}