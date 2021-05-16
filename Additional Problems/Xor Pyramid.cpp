#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;

int N, D, a, xum;

int two_divisibility(int x){
    int res = 0;
    while(x){
        x >>= 1;
        res += x;
    }
    return res;
}

int main(){
    scanf("%d", &N);
    D = two_divisibility(N-1);
    for(int i = 0; i < N; i++){
        scanf("%d", &a);
        int d1 = two_divisibility(i);
        int d2 = two_divisibility(N-i-1);
        if(D - d1 - d2 == 0)
            xum ^= a;
    }
    printf("%d\n", xum);
}
