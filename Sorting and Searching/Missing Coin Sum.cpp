#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5;

int N, x[maxN];
ll res;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &x[i]);
    sort(x, x+N);

    res = 1;
    for(int i = 0; i < N && x[i] <= res; i++)
        res += x[i];
    printf("%lld\n", res);
}
