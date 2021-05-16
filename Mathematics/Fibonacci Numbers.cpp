#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;

ll N, x[2][2], y[2][2];

void mult(ll A[2][2], ll B[2][2]){
    ll C[2][2];
    memset(C, 0, sizeof(C));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            A[i][j] = C[i][j];
}

int main(){
    x[0][1] = x[1][0] = x[1][1] = y[0][0] = y[1][1] = 1;

    scanf("%lld", &N);
    while(N){
        if(N&1)
            mult(y, x);
        mult(x, x);
        N >>= 1;
    }

    printf("%lld\n", y[0][1]);
}
