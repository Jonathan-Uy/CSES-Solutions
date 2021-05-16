#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int maxN = 2e5;

int N, p, x[maxN+1];
tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> T;

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &x[i]);
        T.insert(i);
    }

    for(int i = 0; i < N; i++){
        scanf("%d", &p);
        printf("%d%c", x[*T.find_by_order(p-1)], (" \n")[i==N-1]);
        T.erase(T.find_by_order(p-1));
    }
}
