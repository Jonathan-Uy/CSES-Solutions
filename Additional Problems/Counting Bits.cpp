#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;
map<ll,ll> memo;

ll f(ll a){
	if(a == 0)	return 0;
	if(memo[a])	return memo[a];
	if(a&1)	memo[a] = 2*f(a/2)+(a/2)+1;
	else 	memo[a] = f(a/2)+f(a/2-1)+(a/2);
	return	memo[a];
}

int main(){
	scanf("%lld", &N);
	printf("%lld\n", f(N));
}
