#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e6+5;
const ll MOD = 1e9+7;
const ll p1 = 31;
const ll p2 = 37;

int N, M, cnt;
ll sh1, sh2, th1, th2, pow1[maxN], pow2[maxN];
char S[maxN], T[maxN];

int main(){
    scanf("%s %s", S, T);
    N = (int) strlen(S); M = (int) strlen(T);

    if(M > N){
        printf("0\n");
        return 0;
    }

    pow1[0] = pow2[0] = 1;
    for(int i = 1; i < maxN; i++){
        pow1[i] = (pow1[i-1] * p1) % MOD;
        pow2[i] = (pow2[i-1] * p2) % MOD;
    }

    for(int i = 0; i < M; i++){
        sh1 = (sh1 + (S[i] - 'a' + 1) * pow1[M-i-1]) % MOD;
        sh2 = (sh2 + (S[i] - 'a' + 1) * pow2[M-i-1]) % MOD;
        th1 = (th1 + (T[i] - 'a' + 1) * pow1[M-i-1]) % MOD;
        th2 = (th2 + (T[i] - 'a' + 1) * pow2[M-i-1]) % MOD;
    }

    if(sh1 == th1 && sh2 == th2)    cnt++;
    for(int i = M; i < N; i++){
        sh1 = (sh1 * p1 - (S[i-M] - 'a' + 1) * pow1[M]) % MOD;
        sh1 = (sh1 + (S[i] - 'a' + 1) + MOD) % MOD;
        sh2 = (sh2 * p2 - (S[i-M] - 'a' + 1) * pow2[M]) % MOD;
        sh2 = (sh2 + (S[i] - 'a' + 1) + MOD) % MOD;
        if(sh1 == th1 && sh2 == th2)    cnt++;
    }
    printf("%d\n", cnt);
}
