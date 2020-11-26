#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e6;

int N, dp[maxN+1];

int main(){
	scanf("%d", &N);
	fill(dp+1, dp+N+1, INT_MAX);
	
	for(int i = 1; i <= N; i++){
		int d = i;
		while(d > 0){
			if(d%10 != 0)
				dp[i] = min(dp[i], dp[i-(d%10)]+1);
			d /= 10;
		}
	}
	
	printf("%d\n", dp[N]);
}
