#include <bits/stdc++.h>

using namespace std;

int N, ans;

int main(){
    scanf("%d", &N);
    while(N > 0){
        N /= 5;
        ans += N;
    }
    printf("%d\n", ans);
}
