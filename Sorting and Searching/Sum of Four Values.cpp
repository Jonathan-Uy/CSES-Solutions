#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxN = 1001;

int N;
ll X, a[maxN];
unordered_map<ll,vector<pii>> mp;

int main(){
    scanf("%d %lld", &N, &X);
    mp.reserve(maxN*maxN);
    for(int i = 1; i <= N; i++){
        scanf("%lld", &a[i]);
        for(int j = 1; j < i; j++){
            ll psum = a[i] + a[j];
            if(psum >= X)   continue;
            if(mp.find(X-psum) != mp.end()){
                for(pii P : mp[X-psum]){
                    if(P.first != j && P.second != j && P.first != i && P.second != i){
                        printf("%d %d %d %d\n", P.first, P.second, j, i);
                        return 0;
                    }
                }
            } else mp[psum].push_back({j, i});
        }
    }
    printf("IMPOSSIBLE\n");
}
