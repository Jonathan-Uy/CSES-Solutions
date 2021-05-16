#include <bits/stdc++.h>

using namespace std;

int T, N, p, xum;

int main(){
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        scanf("%d", &N);
        xum = 0;
        for(int i = 0; i < N; i++){
            scanf("%d", &p);
            if(i%2)
                xum ^= p;
        }
        printf(xum ? "first\n" : "second\n");
    }
}
