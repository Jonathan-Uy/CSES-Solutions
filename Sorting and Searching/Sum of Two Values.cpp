#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 2e5+1;

int N, x, a;
pii p[maxN];

int find(int val){
    int l = 1, r = N;
    while(l <= r){
        int m = l+(r-l)/2;
        if(p[m].first == val)       return p[m].second;
        else if(p[m].first < val)   l = m+1;
        else                        r = m-1;
    }
    return 0;
}

int main(){
    scanf("%d %d", &N, &x);
    for(int i = 1; i <= N; i++){
        scanf("%d", &a);
        p[i] = {a, i};
    }
    sort(p+1, p+N+1);

    for(int i = 1; i <= N; i++){
        int other = find(x-p[i].first);
        if(other != 0 && other != p[i].second){
            printf("%d %d\n", p[i].second, other);
            return 0;
        }
    }
    printf("IMPOSSIBLE\n");
}
