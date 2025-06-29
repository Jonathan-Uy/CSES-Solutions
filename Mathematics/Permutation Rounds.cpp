#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5+1;
const ll MOD = (ll) 1e9+7;

int N, perm[maxN];
bool vis[maxN], is_prime[maxN];
vector<int> primes;
map<int,int> ans;

void init_primes(){
    for(int i = 2; i < maxN; i++)   is_prime[i] = true;
    for(int i = 2; i < maxN; i++){
        if(is_prime[i]){
            primes.push_back(i);
            for(int j = 2 * i; j < maxN; j += i)
                is_prime[j] = false;
        }
    }
}

int dfs(int u){
    vis[u] = true;
    if(vis[perm[u]])    return 1;
    return dfs(perm[u]) + 1;
}

void prime_factor(int x){
    for(int i = 0; i < (int) primes.size() && primes[i] <= x; i++){
        int p = primes[i];
        int num_divisions = 0;
        while(x % p == 0){
            x /= p;
            num_divisions++;
        }

        if(num_divisions > 0)
            ans[p] = max(ans[p], num_divisions);
    }
}

int main(){
    init_primes();

    scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%d", &perm[i]);

    for(int u = 1; u <= N; u++){
        if(!vis[u]){
            int len = dfs(u);
            prime_factor(len);
        }
    }

    ll prod = 1;
    for(auto const& [prime, power] : ans)
        for(int i = 0; i < power; i++)
            prod = (prod * prime) % MOD;
    printf("%lld\n", prod);
}