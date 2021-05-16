#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5;

int N, pre, a, freq[maxN];
ll cnt;

int mod(int x){
    return (x % N + N) % N;
}

int main(){
    scanf("%d", &N);
    freq[0] = 1;
    for(int i = 0; i < N; i++){
        scanf("%d", &a);
        pre = mod(pre+a);
        cnt += freq[pre];
        freq[pre]++;
    }
    printf("%lld\n", cnt);
}
