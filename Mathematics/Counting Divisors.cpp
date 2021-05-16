#include <bits/stdc++.h>

using namespace std;
const int maxX = 1e6;

int N, x, d[maxX+1];

void init(){
    for(int i = 1; i <= maxX; i++)
        for(int j = i; j <= maxX; j += i)
            d[j]++;
}

int main(){
    scanf("%d", &N);

    init();
    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        printf("%d\n", d[x]);
    }
}
