#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5+1;

int N, x[maxN], ds[maxN];

int main(){
    scanf("%d ", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &x[i]);
        int k = i-1;
        while(x[k] >= x[i])
            k = ds[k];
        ds[i] = k;
        printf("%d%c", ds[i], (" \n")[i==N]);
    }
}
