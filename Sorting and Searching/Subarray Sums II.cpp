#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll X, a, cnt, pre;
map<ll,int> freq;

int main(){
    scanf("%d %lld", &N, &X);
    freq[0] = 1;
    for(int i = 0; i < N; i++){
        scanf("%lld", &a);
        pre += a;
        cnt += freq[pre-X];
        freq[pre]++;
    }
    printf("%lld\n", cnt);
}
