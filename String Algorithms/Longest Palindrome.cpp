#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;

char S[maxN];
int N, bestl, bestr, d1[maxN], d2[maxN];

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);

    for(int i = 0, l = 0, r = -1; i < N; i++){
        int k = (i > r ? 1 : min(d1[l+r-i], r-i+1));
        while(0 <= i-k && i+k < N && S[i-k] == S[i+k])  k++;

        if(2*k-1 > bestr-bestl+1){
            bestl = i-k+1;
            bestr = i+k-1;
        }

        d1[i] = k--;
        if(i+k > r){
            l = i-k;
            r = i+k;
        }
    }

    for(int i = 0, l = 0, r = -1; i < N; i++){
        int k = (i > r ? 0 : min(d2[l+r-i+1], r-i+1));
        while(0 <= i-k-1 && i+k < N && S[i-k-1] == S[i+k])  k++;

        if(2*k > bestr-bestl+1){
            bestl = i-k;
            bestr = i+k-1;
        }

        d2[i] = k--;
        if(i+k > r){
            l = i-k-1;
            r = i+k;
        }
    }

    for(int i = bestl; i <= bestr; i++)
        printf("%c", S[i]);
}