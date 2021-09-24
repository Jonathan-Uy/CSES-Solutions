#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6+5;

char S[maxN];
int N, cur, best;

int main(){
    scanf(" %s", S);
    N = (int) strlen(S);
    cur = best = 1;
    for(int i = 1; i < N; i++){
        if(S[i] == S[i-1])  cur++;
        else                cur = 1;
        best = max(best, cur);
    }
    printf("%d\n", best);
}
