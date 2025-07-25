#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;

int N, nxt[maxN];
char S[maxN];

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);
    for(int i = 0; i < N; i++)  nxt[i] = i;
    stable_sort(nxt, nxt+N, [](int a, int b){
        return S[a] < S[b];
    });

    int ptr = nxt[0];
    while(ptr != 0){
        ptr = nxt[ptr];
        printf("%c", S[ptr]);
    }
}