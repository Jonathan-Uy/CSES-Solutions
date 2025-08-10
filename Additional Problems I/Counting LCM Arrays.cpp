#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll MOD = 1e9+7;

struct Matrix2x2 {
    ll a, b, c, d;
    Matrix2x2(ll a, ll b, ll c, ll d) : a(a), b(b), c(c), d(d) {}

    Matrix2x2 operator*(const Matrix2x2& other) const {
        return Matrix2x2(
            (a * other.a + b * other.c) % MOD,
            (a * other.b + b * other.d) % MOD,
            (c * other.a + d * other.c) % MOD,
            (c * other.b + d * other.d) % MOD
        );
    }
};

Matrix2x2 fast_pow(Matrix2x2 base, ll exp){
    Matrix2x2 result(1, 0, 0, 1);
    while(exp > 0){
        if(exp % 2 == 1)
            result = result * base;
        base = base * base;
        exp /= 2;
    }
    return result;
}

vector<pii> prime_factor(int k){
    vector<pii> factors;
    for(int i = 2; i * i <= k; i++){
        int count = 0;
        while(k % i == 0){
            k /= i;
            count++;
        }
        if(count > 0)
            factors.push_back({i, count});
    }
    if(k > 1)
        factors.push_back({k, 1});
    return factors;
}

ll solve(int n, int k){
    vector<pii> factors = prime_factor(k);

    ll ans = 1;
    for(const auto& [p, e] : factors){
        Matrix2x2 base(1, 1, e, 0);
        Matrix2x2 result = fast_pow(base, n+1);
        ans = (ans * result.a) % MOD;
    }
    return ans;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 0, n, k; t < T; t++){
        scanf("%d %d", &n, &k);
        printf("%lld\n", solve(n, k));
    }
}