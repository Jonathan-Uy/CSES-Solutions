#include <bits/stdc++.h>

/* Fast Input and Output Template */
char _i[1<<24], _o[1<<10], __[20], _, _c; int _i0, _o0, _n;
#define readio()    { fread(_i, 1, 1<<24, stdin); }
#define writeio()   { fwrite(_o, 1, _o0, stdout); }
#define scanu(x)    { for (x = _i[_i0++] & 15; 47 < (_ = _i[_i0++]); x = x * 10 + (_ & 15)); }
#define putnumu(x)  { _ = 0; do __[_++] = x % 10 | '0'; while (x /= 10); while (_--) _o[_o0++] = __[_]; }
#define putnl()     { _o[_o0++] = '\n'; }
/* End of Template */

using namespace std;
typedef long long ll;
const int maxN = 2e5+2;
const int logC = 32, logN = 18;
const int INF = 0x3f3f3f3f;

int N, Q, mn[logC][logN][maxN];
ll pre[logC][maxN];

int layer(int x){
    return 31 - __builtin_clz(x);
}

ll sum(int l, int a, int b){
    return pre[l][b] - pre[l][a-1];
}

int minimum(int l, int a, int b){
    a--; b--;
    int len = b-a+1;
    int k = (int) floor(log2(len));
    return min(mn[l][k][a], mn[l][k][b-(1<<k)+1]);
}

void init(){
    scanu(N); scanu(Q);
    for(int i = 1, x; i <= N; i++){
        scanu(x);
        int l = layer(x);
        pre[l][i] = x;
        for(int j = 0; j < logC; j++)
            mn[j][0][i-1] = (j == l ? x : INF);
    }

    for(int l = 0; l < logC; l++){
        for(int j = 1; j <= N; j++)
            pre[l][j] += pre[l][j-1];

        for(int i = 1; i < logN; i++)
            for(int j = 0; j <= N-(1<<i); j++)
                mn[l][i][j] = min(mn[l][i-1][j], mn[l][i-1][j+(1<<(i-1))]);
    }
}

ll query(int a, int b){
    ll ans = 1;
    for(int l = 0; l < logC && ans >= (1<<l); l++)
        if(minimum(l, a, b) <= ans)
            ans += sum(l, a, b);
    return ans;
}

int main(){
    readio();
    init();
    for(int q = 0, a, b; q < Q; q++){
        scanu(a); scanu(b);
        ll ans = query(a, b);
        putnumu(ans);
        putnl();
    }
    writeio();
}