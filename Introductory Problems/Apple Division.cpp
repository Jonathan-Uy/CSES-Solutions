#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int N, p[20];
ll a, b, best;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &p[i]);

    best = INF;
    for(int i = 0; i < (1<<N); i++){
        a = 0; b = 0;
        for(int j = 0; j < N; j++){
            if(i&(1<<j))    a += p[j];
            else            b += p[j];
        }
        best = min(best, abs(a-b));
    }
    printf("%lld\n", best);
}
