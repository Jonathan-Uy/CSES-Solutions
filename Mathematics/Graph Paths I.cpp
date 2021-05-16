#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 100;
const ll MOD = 1e9+7;

int N, M, K, a, b;
ll X[maxN][maxN], Y[maxN][maxN];

void mult(ll A[maxN][maxN], ll B[maxN][maxN]){
    ll C[N][N];
    memset(C, 0, sizeof(C));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            A[i][j] = C[i][j];
}

int main(){
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0; i < M; i++){
        scanf("%d %d", &a, &b);
        X[a-1][b-1]++;
    }
    for(int i = 0; i < N; i++)
        Y[i][i] = 1;

    while(K){
        if(K&1)
            mult(Y, X);
        mult(X, X);
        K >>= 1;
    }

    printf("%lld\n", Y[0][N-1]);
}
