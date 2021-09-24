#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 5005;
const ll p1 = 31, p2 = 37, MOD = 1e9+7;

int K;
ll pow1[maxN], pow2[maxN], sh1[maxN], sh2[maxN], dp[maxN];
char S[maxN], word[maxN];
unordered_set<int> hashes1, hashes2;

void init(){
    pow1[0] = pow2[0] = 1;
    for(int i = 1; i < maxN; i++){
        pow1[i] = (pow1[i-1] * p1) % MOD;
        pow2[i] = (pow2[i-1] * p2) % MOD;
    }
}

void hashWord(){
    scanf(" %s", word);
    int N = (int) strlen(word);
    if(N >= maxN)    return;

    ll h1 = 0, h2 = 0;
    for(int i = 0; i < N; i++){
        int c = (int) (word[i] - 'a' + 1);
        h1 = (h1 * p1 + c) % MOD;
        h2 = (h2 * p2 + c) % MOD;
    }
    hashes1.insert(h1);
    hashes2.insert(h2);
}

int main(){
    init();
    scanf(" %s %d", S, &K);
    for(int i = 0; i < K; i++)
        hashWord();

    dp[0] = 1;
    int N = (int) strlen(S);
    ll h1 = 0, h2 = 0;
    for(int r = 1; r <= N; r++){
        int c = (int) (S[r-1] - 'a' + 1);
        h1 = (h1 * p1 + c) % MOD;
        h2 = (h2 * p2 + c) % MOD;
        sh1[r] = h1;
        sh2[r] = h2;

        for(int l = 0; l < r; l++){
            int len = r-l;
            ll prehash1 = (sh1[l] * pow1[len]) % MOD;
            ll subhash1 = (sh1[r] - prehash1 + MOD) % MOD;
            ll prehash2 = (sh2[l] * pow2[len]) % MOD;
            ll subhash2 = (sh2[r] - prehash2 + MOD) % MOD;
            if(hashes1.count(subhash1) && hashes2.count(subhash2))
                dp[r] = (dp[r] + dp[l]) % MOD;
        }
    }
    printf("%lld\n", dp[N]);
}