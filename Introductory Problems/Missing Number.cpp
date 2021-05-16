#include <bits/stdc++.h>

using namespace std;

int N, x, xum;

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        xum ^= i;
    for(int i = 0; i < N-1; i++){
        scanf("%d", &x);
        xum ^= x;
    }
    printf("%d\n", xum);
}
