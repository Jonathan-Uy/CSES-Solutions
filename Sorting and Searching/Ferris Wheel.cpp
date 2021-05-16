#include <bits/stdc++.h>

using namespace std;
const int maxN = 2e5;

int N, X, l, ans, p[maxN];

int main(){
    scanf("%d %d", &N, &X);
    for(int i = 0; i < N; i++)
        scanf("%d", &p[i]);
    sort(p, p+N);

    l = 0;
    for(int r = N-1; r >= l; r--){
        if(p[l] + p[r] <= X)
            l++;
        ans++;
    }
    printf("%d\n", ans);
}
