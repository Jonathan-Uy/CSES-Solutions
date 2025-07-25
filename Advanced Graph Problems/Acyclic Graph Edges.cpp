#include <bits/stdc++.h>

using namespace std;
int N, M, a, b;

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        printf("%d %d\n", min(a, b), max(a, b));
    }
}
