#include <bits/stdc++.h>

using namespace std;
const int maxX = 5005;
const int SIZE = 700;
const int MOD = 1e9+7;

int N, ans;
bool p[maxX];
vector<int> primes;
bitset<SIZE> basis[700];

void generate_primes(){
    for(int i = 2; i < maxX; i++)   p[i] = true;
    for(int i = 2; i < maxX; i++){
        if(p[i]){
            primes.push_back(i);
            for(int j = 2*i; j < maxX; j += i)
                p[j] = false;
        }
    }
}

bitset<SIZE> prime_factor(int x){
    bitset<SIZE> factors;
    for(int i = 0; i < (int) primes.size() && primes[i] <= x; i++){
        int power = 0;
        while(x % primes[i] == 0){
            x /= primes[i];
            power++;
        }
        factors[i] = (power % 2 == 1);
    }
    return factors;
}

bool insert_vector(bitset<SIZE> mask){
    for(int i = SIZE-1; i >= 0; i--){
        if(mask[i] == 0)  continue;
        if(!basis[i].any()){
            basis[i] = mask;
            return true;
        }
        mask ^= basis[i];
    }
    return false;
}

int main(){
    scanf("%d", &N);
    generate_primes();

    int ans = 1;
    for(int i = 0, x; i < N; i++){
        scanf("%d", &x);
        bitset<SIZE> factors = prime_factor(x);
        if(!insert_vector(factors))
            ans = (ans * 2) % MOD;
    }
    printf("%d\n", ans);
}