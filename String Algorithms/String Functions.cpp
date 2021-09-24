#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;

char S[maxN];
int N, z[maxN], pi[maxN];

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);

    for(int i = 1, l = 0, r = 0; i < N; i++){
        if(i <= r)  z[i] = min(r-i+1, z[i-l]);
        while(i+z[i] < N && S[z[i]] == S[i+z[i]])   z[i]++;
        if(i+z[i]-1 > r)    l = i, r = i+z[i]-1;
    }
    for(int i = 0; i < N; i++)
        printf("%d%c", z[i], (" \n")[i==N-1]);

    for(int i = 1; i < N; i++){
        int j = pi[i-1];
        while(j > 0 && S[i] != S[j])    j = pi[j-1];
        if(S[i] == S[j])    j++;
        pi[i] = j;
    }
    for(int i = 0; i < N; i++)
        printf("%d%c", pi[i], (" \n")[i==N-1]);
}