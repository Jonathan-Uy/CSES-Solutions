#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll N, x[6][6], y[6][6];

void init(){
    for(int i = 0; i < 6; i++)
        x[0][i] = 1;
    for(int i = 0; i < 5; i++)
        x[i+1][i] = 1;
    for(int i = 0; i < 6; i++)
        y[i][i] = 1;
}

void mult(ll A[6][6], ll B[6][6]){
    ll C[6][6];
    memset(C, 0, sizeof(C));
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 6; k++){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            A[i][j] = C[i][j];
}

int main(){
    init();

    scanf("%lld", &N);
    while(N){
        if(N&1)
            mult(y, x);
        mult(x, x);
        N >>= 1;
    }

    printf("%lld\n", y[0][0]);
}
