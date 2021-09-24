#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll p1 = 31, p2 = 37;
const int maxN = 1e6+5;

int N;
char S[maxN];
ll pow1[maxN], pow2[maxN], h1[maxN], h2[maxN];

void init(){
    pow1[0] = pow2[0] = 1;
    h1[0] = h2[0] = (int) (S[0] - 'a' + 1);
    for(int i = 1; i < maxN; i++){
        int c = (int) (S[i] - 'a' + 1);
        pow1[i] = (pow1[i-1] * p1) % MOD;
        pow2[i] = (pow2[i-1] * p2) % MOD;
        h1[i] = (h1[i-1] * p1 + c) % MOD;
        h2[i] = (h2[i-1] * p2 + c) % MOD;
    }
}

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);
    init();

    for(int len = 1; len <= N; len++){
        ll hash1 = h1[len-1], hash2 = h2[len-1];
        for(int i = 0; i < (N/len)-1; i++){
            hash1 = (hash1 * pow1[len] + h1[len-1]) % MOD;
            hash2 = (hash2 * pow2[len] + h2[len-1]) % MOD;
        }
        hash1 = (hash1 * pow1[N%len] + h1[N%len-1]) % MOD;
        hash2 = (hash2 * pow2[N%len] + h2[N%len-1]) % MOD;
        if(hash1 == h1[N-1] && hash2 == h2[N-1])    printf("%d ", len);
    }
}