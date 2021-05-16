#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxN = 2e5+1;

int N, a[maxN], b[maxN];
ll p[maxN], dp[2*maxN];
struct project {int time, id, type;} times[2*maxN];
map<int,int> mp;

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d %d %lld", &a[i], &b[i], &p[i]);
        times[2*i] = {a[i], i, 0};
        times[2*i+1] = {b[i], i, 1};
    }

    sort(times+2, times+2*N+2, [](project A, project B){
        return A.time == B.time ? A.id < B.id : A.time < B.time;
    });

    for(int i = 2; i <= 2*N+1; i++)
        if(!mp[times[i].time])
            mp[times[i].time] = i;

    for(int i = 2; i <= 2*N+1; i++){
        if(times[i].type == 0)  dp[i] = dp[i-1];
        else dp[i] = max(dp[i-1], dp[mp[a[times[i].id]]-1] + p[times[i].id]);
    }
    printf("%lld\n", dp[2*N+1]);
}
