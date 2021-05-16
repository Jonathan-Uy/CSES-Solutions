#include <bits/stdc++.h>

using namespace std;

int N, k;
multiset<int> S;
multiset<int>::iterator it;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &k);
        it = S.upper_bound(k);
        if(it != S.end())
            S.erase(it);
        S.insert(k);
    }
    printf("%d\n", (int) S.size());
}
