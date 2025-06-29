#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef array<int,4> solution;
const int maxN = 1e7+1;

set<int> squares;
map<int,solution> small_solutions;
bool prime[maxN];

void init_squares(){
    for(int i = 0; i * i <= maxN; i++)
        squares.insert(i * i);
}

void init_primes(){
    for(int i = 2; i < maxN; i++)   prime[i] = true;
    for(int i = 2; i * i < maxN; i++)
        if(prime[i])
            for(int j = 2*i; j < maxN; j += i)
                prime[j] = false;
}

void precompute_small(){
    for(int a = 0; a <= 100; a++)
        for(int b = 0; b <= 100; b++)
            for(int c = 0; c <= 20; c++)
                for(int d = 0; d <= 5; d++)
                    small_solutions[a*a + b*b + c*c + d*d] = {a, b, c, d};
}

// Returns a and b such that
// a and b have opposite parity
// and p := n - a^2 - b^2 is prime
pii find_ab(int n){
    int sqrtn = (int) sqrt(n);

    while(true){
        int a = (rand() % sqrtn) + 1;
        int b = (rand() % sqrtn) + 1;

        if((a+b) % 2 == 0)  a++;

        int p = n - a*a - b*b;
        if(p >= 2 && prime[p])
            return {a, b};
    }
}

// If prime p is congruent to 1 (mod 4),
// then there exists integers (c, d)
// such that c^2 + d^2 = p.
// Naively find such c and d.
pii find_cd(int p){
    for(int c = 0; c*c <= p; c++){
        int d_squared = p - c*c;
        if(squares.find(d_squared) != squares.end())
            return {c, (int) sqrt(d_squared)};
    }
    return {-1, -1};
}

solution solve(int n){
    if(small_solutions.find(n) != small_solutions.end()){
        return small_solutions[n];
    } else if(n == 0){
        return {0, 0, 0, 0};
    } else if(n % 4 == 0){
        solution sol = solve(n / 4);
        for(int i = 0; i < 4; i++)  sol[i] *= 2;
        return sol;
    } else if(n % 4 == 1 || n % 4 == 3){
        solution sol = solve(2 * n);
        sort(sol.begin(), sol.end(), [](int a, int b){
            return (a % 2 > b % 2);
        });
        return {
            (sol[0] + sol[1]) / 2,
            (sol[0] - sol[1]) / 2,
            (sol[2] + sol[3]) / 2,
            (sol[2] - sol[3]) / 2,
        };
    } else {
        pii ab = find_ab(n);
        int a = ab.first, b = ab.second;
        int p = n - a*a - b*b;
        pii cd = find_cd(p);
        int c = cd.first, d = cd.second;
        return {a, b, c, d};
    }
}

int main(){
    init_squares();
    init_primes();
    precompute_small();

    int T;
    scanf("%d", &T);
    for(int t = 0, n; t < T; t++){
        scanf("%d", &n);
        solution sol = solve(n);
        for(int i = 0; i < 4; i++)  sol[i] = abs(sol[i]);
        printf("%d %d %d %d\n", sol[0], sol[1], sol[2], sol[3]);
    }
}
