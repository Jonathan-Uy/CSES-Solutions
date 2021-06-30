#include <bits/stdc++.h>

using namespace std;

int T, N, x;
bool even;

int main(){
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        scanf("%d", &N);
        even = true;
        for(int i = 0; i < N; i++){
            scanf("%d", &x);
            even &= !(x&1);
        }
        printf("%s\n", even ? "second" : "first");
    }
}