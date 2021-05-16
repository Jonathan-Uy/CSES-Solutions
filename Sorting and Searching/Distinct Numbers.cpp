#include <bits/stdc++.h>

using namespace std;

int N, x;
set<int> S;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        S.insert(x);
    }
    printf("%d\n", (int) S.size());
}
