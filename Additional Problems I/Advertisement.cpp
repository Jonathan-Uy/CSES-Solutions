#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+5;

int N, l[maxN], r[maxN];
ll best, a[maxN];

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%lld", &a[i]);

    for(int i = 1; i <= N; i++){
        l[i] = i-1;
        while(a[l[i]] >= a[i])
            l[i] = l[l[i]];
    }
    for(int i = N; i >= 1; i--){
        r[i] = i+1;
        while(a[r[i]] >= a[i])
            r[i] = r[r[i]];
    }

    for(int i = 1; i <= N; i++)
        best = max(best, (r[i]-l[i]-1)*a[i]);
    printf("%lld\n", best);
}
