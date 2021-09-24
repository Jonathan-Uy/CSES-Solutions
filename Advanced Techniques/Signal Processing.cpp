#include <bits/stdc++.h>

using namespace std;
typedef double ld;
typedef complex<ld> cd;
const int maxN = 2e5+5;
const int SIZE = 1<<19;
const ld PI = acos(-1);

int N, M;
vector<cd> A(SIZE), B(SIZE);

void fft(vector<cd> &a, bool inv){
    int n = (int) a.size();

    for(int i = 1, j = 0; i < n; i++){
        int bit = n>>1;
        for(; j&bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if(i < j)
            swap(a[i], a[j]);
    }

    for(int len = 2; len <= n; len <<= 1){
        ld theta = 2*PI / len * (inv ? -1 : 1);
        cd wlen(cos(theta), sin(theta));
        for(int i = 0; i < n; i += len){
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
            z /= n;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0, a; i < N; i++){
        scanf("%d", &a);
        A[i] = a;
    }
    for(int i = 0, b; i < M; i++){
        scanf("%d", &b);
        B[M-i-1] = b;
    }

    fft(A, false);
    fft(B, false);
    for(int i = 0; i < SIZE; i++)
        A[i] *= B[i];
    fft(A, true);

    for(int i = 0; i < N+M-1; i++)
        printf("%lld%c", llround(A[i].real()), (" \n")[i==N+M-2]);
}