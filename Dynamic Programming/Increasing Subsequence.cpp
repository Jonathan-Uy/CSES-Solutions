#include <bits/stdc++.h>

using namespace std;

int N, a;
multiset<int> S;
multiset<int>::iterator it;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &a);
        S.insert(a);
        it = S.lower_bound(a);
        it++;
        if(it != S.end())
            S.erase(it);
    }
    printf("%d\n", (int) S.size());
}
