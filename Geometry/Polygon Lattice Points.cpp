#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e5+5;

int N;
ll area, boundary, inside, x[maxN], y[maxN];

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%lld %lld", &x[i], &y[i]);
    x[N] = x[0]; y[N] = y[0];

    for(int i = 0; i < N; i++){
        area += x[i] * y[i+1];
        area -= y[i] * x[i+1];
    }
    area = abs(area);

    for(int i = 0; i < N; i++){
        if(x[i+1] == x[i])      boundary += abs(y[i+1]-y[i]);
        else if(y[i+1] == y[i]) boundary += abs(x[i+1]-x[i]);
        else boundary += __gcd(abs(x[i+1]-x[i]), abs(y[i+1]-y[i]));
    }

    printf("%lld %lld\n", (area+2-boundary)/2, boundary);
}
