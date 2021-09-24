#include <bits/stdc++.h>

using namespace std;

int N, K;

void solve(){
    scanf("%d %d", &N, &K);
    if(K*K < N){
        printf("IMPOSSIBLE\n");
        return;
    }

    vector<int> ans;
    int l = 1, r = K;
    while(true){
        for(int i = r; i >= l; i--)
            ans.push_back(i);
        if(r == N)  break;
        l = r+1;
        r = min(r+K, N);
    }

    for(int i = 0; i < N; i++)
        printf("%d%c", ans[i], (" \n")[i==N-1]);
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        solve();
    }
}