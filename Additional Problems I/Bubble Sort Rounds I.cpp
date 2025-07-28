#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 2e5+1;

int N, x[maxN];
vector<pii> sorted;
map<int,int> inv;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &x[i]);
        sorted.push_back({x[i], i});
    }
    sort(sorted.begin(), sorted.end(), greater<pii>());

    int worst_dist = 0;
    for(int i = 0; i < N; i++){
        int targ = N-i-1;
        int start = sorted[i].second;
        worst_dist = max(worst_dist, start - targ);
    }
    printf("%d\n", worst_dist);
}