#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int sqrtN = 1e6+5;

bool prime[sqrtN];
vector<ll> p;

void init_primes(){
    for(int i = 2; i < sqrtN; i++)  prime[i] = true;

    for(int i = 2; i * i <= sqrtN; i++)
        if(prime[i])
            for(int j = 2*i; j < sqrtN; j += i)
                prime[j] = false;

    for(int i = 2; i < sqrtN; i++)
        if(prime[i])
            p.push_back(i);
}

bool is_prime(ll n){
    for(int i = 0; i < (int) p.size() && p[i] < n; i++)
        if(n % p[i] == 0)
            return false;
    return true;
}

int main(){
    init_primes();

    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        ll n;
        scanf("%lld", &n);

        n++;
        while(!is_prime(n))
            n++;

        printf("%lld\n", n);
    }
}