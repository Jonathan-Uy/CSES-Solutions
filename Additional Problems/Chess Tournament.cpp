#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;

int N, K;
vector<pii> added, ans;
tree<pii, null_type, less<pii>, rb_tree_tag,
tree_order_statistics_node_update> T;

int main(){
    scanf("%d", &N);
    for(int i = 1, x; i <= N; i++){
        scanf("%d", &x);
        T.insert({x, i});
    }

    for(int i = N-1; i >= 0; i--){
        pii P = *T.find_by_order(i);
        T.erase(T.find_by_order(i));
        int degu = P.first;
        int u = P.second;

        added.clear();
        for(int j = 1; j <= degu; j++){
            if(i-j < 0 || (*T.find_by_order(i-j)).first == 0){
                printf("IMPOSSIBLE\n");
                return 0;
            }

            pii Q = *T.find_by_order(i-j);
            T.erase(T.find_by_order(i-j));
            int degv = Q.first;
            int v = Q.second;

            ans.push_back({min(u, v), max(u, v)});
            added.push_back({degv-1, v});
        }

        for(pii Q : added)
            T.insert({Q.first, Q.second});
    }

    sort(ans.begin(), ans.end());
    K = (int) ans.size();
    printf("%d\n", K);
    for(int i = 0; i < K; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);
}