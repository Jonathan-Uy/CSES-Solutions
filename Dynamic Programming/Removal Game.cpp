#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 5000;

int N, x[maxN+1];
ll p[maxN+1], dp[maxN+1][maxN+1];
bool found[maxN+1][maxN+1];

ll sum(int l, int r){
	return p[r] - p[l-1];
}

ll solve(int l, int r){
	if(found[l][r])	return dp[l][r];
	if(l == r)		return x[l];
	found[l][r]=true;
	return dp[l][r] = max(x[l]+sum(l+1, r)-solve(l+1, r), x[r]+sum(l,r-1)-solve(l,r-1));
}

int main(){
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%d", &x[i]);
		p[i] = p[i-1] + x[i];
	}
	printf("%lld\n", solve(1, N));
}
