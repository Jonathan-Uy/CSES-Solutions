#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5;

int N, a[maxN];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);

    for(int i = 0; i < N; i++){
        int ans = a[0];
        for(int subset = i; subset > 0; subset = (subset-1)&i)
            ans ^= a[subset];
        printf("%d%c", ans, (" \n")[i==N-1]);
    }
}