#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;

int main(){
    scanf("%d", &N);
    for(int k = 1; k <= N; k++){
        ll cnt = 1LL + (k-1)*(k-2)/2;
        cnt = cnt * (k-1) * (k+4);
        printf("%lld\n", cnt);
    }
}
