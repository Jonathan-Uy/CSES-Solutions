#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef array<ll,4> result;
const ll INF = 0x3f3f3f3f3f3f3f;
const int SIZE = 8e5;

int N, Q, lo[SIZE], hi[SIZE];
ll sum[SIZE], dp[SIZE], dpl[SIZE], dpr[SIZE];

result operator+(const result &a, const result &b){
    return {
        a[0] + b[0],
        max(a[1], a[0] + b[1]),
        max(b[2], b[0] + a[2]),
        max(max(a[3], b[3]), a[2] + b[1]),
    };
}

void pull(int i){
	dpl[i] = max(dpl[2*i], sum[2*i] + dpl[2*i+1]);
	dpr[i] = max(dpr[2*i+1], sum[2*i+1] + dpr[2*i]);
	dp[i] = max(dpr[2*i] + dpl[2*i+1], max(dp[2*i], dp[2*i+1]));
	sum[i] = sum[2*i] + sum[2*i+1];
}

void build(int i, int l, int r){
	lo[i] = l; hi[i] = r;
	if(l == r){
		scanf("%lld", &sum[i]);
		dpl[i] = dpr[i] = dp[i] = sum[i];
		return;
	}
	int m = l+(r-l)/2;
	build(2*i, l, m);
	build(2*i+1, m+1, r);
	pull(i);
}

result query(int i, int l, int r){
    if(lo[i] > r || hi[i] < l) return {-INF, -INF, -INF, -INF};
    if(lo[i] >= l && hi[i] <= r) return {sum[i], dpl[i], dpr[i], dp[i]};
    result left = query(2*i, l, r);
    result right = query(2*i+1, l, r);
    return left + right;
}

int main(){
	scanf("%d %d", &N, &Q);

	build(1, 1, N);
	for(int q = 0, l, r; q < Q; q++){
        scanf("%d %d", &l, &r);
        result res = query(1, l, r);
        printf("%lld\n", res[3] <= 0 ? 0 : res[3]);
	}
}