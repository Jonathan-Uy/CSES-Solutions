#include <bits/stdc++.h>

using namespace std;

long long N;

int main(){
    scanf("%lld", &N);
    while(N > 1){
        printf("%lld ", N);
        if(N&1) N = 3*N+1;
        else    N >>= 1;
    }
    printf("1\n");
}
