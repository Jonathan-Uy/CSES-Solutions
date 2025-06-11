#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;

int N, r, x[maxN];
ll ans;
set<int> S;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &x[i]);
    }

    for(int l = 0; l < N; l++){
        while(r < N && S.find(x[r]) == S.end()){
            S.insert(x[r]);
            r++;
        }
        ans += r - l;
        S.erase(x[l]);
    }
    printf("%lld\n", ans);
}
