#include <bits/stdc++.h>

using namespace std;

int T, N, x, xum;

int main(){
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        scanf("%d", &N);
        xum = 0;
        for(int i = 0; i < N; i++){
            scanf("%d", &x);
            xum ^= x;
        }
        printf("%s\n", (xum ? "first" : "second"));
    }
}
