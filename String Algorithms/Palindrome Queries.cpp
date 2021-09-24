#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll p[2] = {31, 37};
const int maxN = 2e5+5;

char S[maxN];
int N, K;
ll pows[2][maxN], invs[2][maxN], F[2], B[2], ds[2][2][maxN];

ll inverse(ll x){
    ll res = 1;
    ll b = MOD-2;
    while(b){
        if(b&1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        b >>= 1;
    }
    return res;
}

void update(int pt, int t, int idx, ll val){
    val %= MOD; val += MOD; val %= MOD;
    for(int i = idx+1; i < maxN; i += -i&i)
        ds[pt][t][i] = (ds[pt][t][i] + val) % MOD;
}

ll query(int pt, int t, int idx){
    if(idx < 0) return 0;
    ll sum = 0;
    for(int i = idx+1; i > 0; i -= -i&i)
        sum = (sum + ds[pt][t][i]) % MOD;
    return sum;
}

void init(){
    for(int t = 0; t < 2; t++){
        pows[t][0] = invs[t][0] = 1;
        for(int i = 1; i < maxN; i++){
            pows[t][i] = (pows[t][i-1] * p[t]) % MOD;
            invs[t][i] = inverse(pows[t][i]);
        }
        update(t, 0, 0, (int) (S[0]-'a'+1) * pows[t][N-1]);
        update(t, 1, 0, (int) (S[0]-'a'+1));
        for(int i = 1; i < N; i++){
            int c = (int) (S[i]-'a'+1);
            update(t, 0, i, c * pows[t][N-i-1]);
            update(t, 1, i, c * pows[t][i]);
        }
    }
}

void modify(int a, char c){
    int newchar = (int) (c - 'a' + 1);
    int oldchar = (int) (S[a] - 'a' + 1);
    for(int t = 0; t < 2; t++){
        update(t, 0, a, -oldchar * pows[t][N-a-1]);
        update(t, 0, a, newchar * pows[t][N-a-1]);
        update(t, 1, a, -oldchar * pows[t][a]);
        update(t, 1, a, newchar * pows[t][a]);
    }
    S[a] = c;
}

bool palindrome(int a, int b){
    for(int t = 0; t < 2; t++){
        F[t] = (query(t, 0, b) - query(t, 0, a-1) + MOD) % MOD;
        F[t] = (F[t] * invs[t][N-b-1]) % MOD;
        B[t] = (query(t, 1, b) - query(t, 1, a-1) + MOD) % MOD;
        B[t] = (B[t] * invs[t][a]) % MOD;
    }
    return F[0] == B[0] && F[1] == B[1];
}

int main(){
    scanf("%d %d %s", &N, &K, S);

    init();
    for(int i = 0, t, a, b; i < K; i++){
        char c;
        scanf("%d", &t);
        if(t == 1){
            scanf("%d %c", &a, &c);
            modify(a-1, c);
        } else if(t == 2){
            scanf("%d %d", &a, &b);
            printf("%s\n", palindrome(a-1, b-1) ? "YES" : "NO");
        }
    }
}