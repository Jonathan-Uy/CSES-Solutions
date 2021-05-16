#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
const int maxN = 100;
const ull INF = 1e19;

int N, M, K, a, b;
ull c, X[maxN][maxN], Y[maxN][maxN];

void combine(ull A[maxN][maxN], ull B[maxN][maxN]){
    ull C[maxN][maxN];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            C[i][j] = INF;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                if(A[i][k] != INF && B[k][j] != INF)
                    C[i][j] = min(C[i][j], A[i][k] + B[k][j]);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            A[i][j] = C[i][j];
}

int main(){
    scanf("%d %d %d", &N, &M, &K);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            X[i][j] = Y[i][j] = INF;
        Y[i][i] = 0;
    }

    for(int i = 0; i < M; i++){
        scanf("%d %d %llu", &a, &b, &c);
        X[a-1][b-1] = min(X[a-1][b-1], c);
    }

    while(K){
        if(K&1)
            combine(Y, X);
        combine(X, X);
        K >>= 1;
    }

    if(Y[0][N-1] == INF)    printf("-1\n");
    else                    printf("%llu\n", Y[0][N-1]);
}
