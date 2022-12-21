#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;

int N, last[maxN];
ll K, x[2*maxN];

int main(){
    scanf("%d %lld", &N, &K);
    for(int i = 0; i < N; i++){
        scanf("%lld", &x[i]);
        x[i+N] = x[i];
    }

    int r = 0;
    ll sum = 0;
    for(int l = 0; l < N; l++){
        while(r < l+N && sum + x[r] <= K){
            sum += x[r];
            r++;
        }
        last[l] = r % N;
        sum -= x[l];
    }

    int opt = 0;
    for(int i = 0; i < N; i++)
        opt = last[opt];

    int cnt = 1;
    sum = x[opt];
    for(int i = opt+1; i < N+opt; i++){
        if(sum + x[i] <= K) sum += x[i];
        else {
            sum = x[i];
            cnt++;
        }
    }

    printf("%d\n", cnt);
}