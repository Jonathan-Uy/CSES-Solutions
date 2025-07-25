#include <bits/stdc++.h>

using namespace std;
const int maxN = 1002;

int N, M, best, h[maxN], l[maxN], r[maxN];
char S[maxN][maxN];

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf(" %s", S[i]);

    h[0] = h[M+1] = -1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++)
            h[j] = (S[i-1][j-1] == '*' ? 0 : h[j]+1);

        int smaller;
        for(int j = 1; j <= M; j++){
            smaller = j-1;
            while(h[smaller] >= h[j])
                smaller = l[smaller];
            l[j] = smaller;
        }
        for(int j = M; j >= 1; j--){
            smaller = j+1;
            while(h[smaller] >= h[j])
                smaller = r[smaller];
            r[j] = smaller;
        }

        for(int j = 1; j <= M; j++){
            int base = r[j]-l[j]-1;
            best = max(best, base * h[j]);
        }
    }

    printf("%d\n", best);
}