#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 2e5+1;

int N, a[maxN], b[maxN], dp[2*maxN];
struct Movie {int t, id, type;} movies[2*maxN];
map<int,int> mp;

int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &a[i], &b[i]);
        movies[2*i] = {a[i], i, 0};
        movies[2*i+1] = {b[i], i, 1};
    }

    sort(movies, movies+2*N, [](Movie A, Movie B){
        return A.t == B.t ? A.id < B.id : A.t < B.t;
    });

    for(int i = 0; i < 2*N; i++)
        mp[movies[i].t] = i;

    for(int i = 0; i < 2*N; i++){
        if(movies[i].type == 0) dp[i] = dp[i-1];
        else dp[i] = max(dp[i-1], dp[mp[a[movies[i].id]]]+1);
    }
    printf("%d\n", dp[2*N-1]);
}
