#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
typedef complex<ld> cd;
const int maxN = 2e5+5;
const ld PI = acos(-1);

ll ans[maxN];
char S[maxN];

void fft(vector<cd> &a, bool inv){
    int N = (int) a.size();

    for(int i = 1, j = 0; i < N; i++){
        int bit = N>>1;
        for(; j&bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if(i < j)
            swap(a[i], a[j]);
    }

    for(int len = 2; len <= N; len <<= 1){
        ld theta = 2*PI / len * (inv ? -1 : 1);
        cd wlen(cos(theta), sin(theta));
        for(int i = 0; i < N; i += len){
            cd w(1);
            for(int j = 0; j < len / 2; j++){
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if(inv)
        for(cd &z : a)
            z /= N;
}

int next_two_pow(int x){
    return 1<<(32 - __builtin_clz(x));
}

void solve(int l, int r){
    if(l+1 == r){
        ans[(int) (S[l] - '0')]++;
        return;
    }

    int m = (l+r)/2;
    int sz = next_two_pow(r-l);
    vector<cd> A(sz), B(sz);
    for(int i = m-1, cnt = 0; i >= l; i--){
        if(S[i] == '1') cnt++;
        A[cnt] += 1;
    }
    for(int i = m, cnt = 0; i < r; i++){
        if(S[i] == '1') cnt++;
        B[cnt] += 1;
    }

    fft(A, false);
    fft(B, false);
    for(int i = 0; i < sz; i++)
        A[i] *= B[i];
    fft(A, true);

    for(int i = 0; i < sz && i < maxN; i++)
        ans[i] += llround(A[i].real());

    solve(l, m);
    solve(m, r);
}

int main(){
    scanf(" %s", S);
    int N = (int) strlen(S);
    solve(0, N);
    for(int i = 0; i <= N; i++)
        printf("%lld%c", ans[i], (" \n")[i==N]);
}