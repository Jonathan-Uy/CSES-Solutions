#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e6+5, numP = 3;
const ll MOD = 1e9+7;
const ll prime[numP] = {31, 37, 43};

int N, M, cnt;
ll sh[numP], th[numP], pw[numP][maxN];
char S[maxN], T[maxN];

bool hashes_equal(){
    for(int p = 0; p < numP; p++)
        if(sh[p] != th[p])
            return false;
    return true;
}

int main(){
    scanf("%s %s", S, T);
    N = (int) strlen(S); M = (int) strlen(T);

    if(M > N){
        printf("0\n");
        return 0;
    }

    for(int p = 0; p < numP; p++){
        pw[p][0] = 1;
        for(int i = 1; i < maxN; i++)
            pw[p][i] = (pw[p][i-1] * prime[p]) % MOD;
    }

    for(int i = 0; i < M; i++){
        for(int p = 0; p < numP; p++){
            sh[p] = (sh[p] + (S[i] - 'a' + 1) * pw[p][M-i-1]) % MOD;
            th[p] = (th[p] + (T[i] - 'a' + 1) * pw[p][M-i-1]) % MOD;
        }
    }

    if(hashes_equal())  cnt++;
    for(int i = M; i < N; i++){
        for(int p = 0; p < numP; p++){
            sh[p] = (sh[p] * prime[p] - (S[i-M] - 'a' + 1) * pw[p][M]) % MOD;
            sh[p] = (sh[p] + (S[i] - 'a' + 1) + MOD) % MOD;
        }
        if(hashes_equal())  cnt++;
    }
    printf("%d\n", cnt);
}
