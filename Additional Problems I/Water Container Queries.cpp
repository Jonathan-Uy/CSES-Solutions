#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    return b == 0 ? a : gcd(b, a % b);
}

bool solve(ll a, ll b, ll x){
    return x % gcd(a, b) == 0 && x <= a;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 0, a, b, x; t < T; t++){
        scanf("%d %d %d", &a, &b, &x);
        printf("%s\n", solve(a, b, x) ? "YES" : "NO");
    }
}