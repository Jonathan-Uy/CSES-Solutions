#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
const int maxN = 2e5+1;

int N, a[maxN], b[maxN], dp[2*maxN];
struct movie {int time, id, type;} movies[2*maxN];
map<int,int> mp;

int main(){
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d %d", &a[i], &b[i]);
		movies[2*i] = {a[i], i, 0};
		movies[2*i+1] = {b[i], i, 1};
	}
	
	sort(movies+2, movies+2*N+2, [](movie A, movie B){
		return A.time == B.time ? A.id < B.id : A.time < B.time;
	});
	
	for(int i = 2; i <= 2*N+1; i++)
		mp[movies[i].time] = i;
	
	for(int i = 2; i <= 2*N+1; i++){
		if(movies[i].type == 0)	dp[i] = dp[i-1];
		else dp[i] = max(dp[i-1], dp[mp[a[movies[i].id]]]+1);
	}
	printf("%d\n", dp[2*N+1]);
}
