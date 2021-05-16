#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;
const int logK = 31;

int N, Q, x, k, p[maxN][logK];

int main(){
    scanf("%d %d", &N, &Q);
    for(int i = 1; i <= N; i++)
        scanf("%d", &p[i][0]);
    for(int j = 1; j < logK; j++)
        for(int i = 1; i <= N; i++)
            p[i][j] = p[p[i][j-1]][j-1];

    for(int q = 0; q < Q; q++){
        scanf("%d %d", &x, &k);
        for(int i = 0; i < logK; i++)
            if(k&(1<<i))
                x = p[x][i];
        printf("%d\n", x);
    }
}
