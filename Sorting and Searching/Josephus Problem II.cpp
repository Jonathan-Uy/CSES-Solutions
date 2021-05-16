#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

int N, K, idx;
tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> T;

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++)
        T.insert(i);

    idx = K;
    while(T.size()){
        idx %= T.size();
        int x = *T.find_by_order(idx);
        T.erase(x);
        printf("%d%c", x, (" \n")[T.size() == 0]);
        idx += K;
    }
}
