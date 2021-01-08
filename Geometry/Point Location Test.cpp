#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int T;
ll x1, yy1, x2, y2, x3, y3;

int main(){
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		scanf("%lld %lld %lld %lld %lld %lld", &x1, &yy1, &x2, &y2, &x3, &y3);
		ll LHS = (y3-y2) * (x2-x1);
		ll RHS = (x3-x2) * (y2-yy1);
		if(LHS == RHS)		printf("TOUCH\n");
		else if(LHS < RHS)	printf("RIGHT\n");
		else if(LHS > RHS)	printf("LEFT\n");
	}
}
