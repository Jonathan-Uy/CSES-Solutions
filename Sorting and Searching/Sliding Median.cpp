#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;
const int maxN = 2e5;

int N, K, x[maxN];
tree<pii, null_type, less<pii>, rb_tree_tag,
tree_order_statistics_node_update> T;

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < K; i++){
        scanf("%d", &x[i]);
        T.insert({x[i], i});
    }

    printf("%d%c", (*T.find_by_order((K-1)/2)).first, (" \n")[N==K]);
    for(int i = K; i < N; i++){
        scanf("%d", &x[i]);
        T.insert({x[i], i});
        T.erase({x[i-K], i-K});
        printf("%d%c", (*T.find_by_order((K-1)/2)).first, (" \n")[i==N-1]);
    }
}
