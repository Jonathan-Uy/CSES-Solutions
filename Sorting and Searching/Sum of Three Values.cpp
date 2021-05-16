#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 5000;

int N, X, v, r;
pii a[maxN];

int main(){
    scanf("%d %d", &N, &X);
    for(int i = 0; i < N; i++){
        scanf("%d", &v);
        a[i] = {v, i+1};
    }

    sort(a, a+N);
    for(int i = 0; i < N; i++){
        v = X - a[i].first;
        r = N-1;
        for(int l = i+1; l < r; l++){
            while(l+1 < r && a[l].first + a[r].first > v)   r--;
            if(a[l].first + a[r].first == v){
                printf("%d %d %d\n", a[i].second, a[l].second, a[r].second);
                return 0;
            }
        }
    }
    printf("IMPOSSIBLE\n");
}
