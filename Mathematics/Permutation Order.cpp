#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 21;

ll fac[maxN];

void init(){
    fac[0] = 1;
    for(int i = 1; i < maxN; i++)
        fac[i] = fac[i-1] * i;
}

vector<int> query_one(const vector<int>& a, ll k){
    if(a.empty())   return {};

    int n = (int) a.size();
    int first_digit = (int) (k / fac[n-1]);

    ll new_k = k - (first_digit * fac[n-1]);
    vector<int> new_a;
    for(int i = 0; i < n; i++)
        if(i != first_digit)
            new_a.push_back(a[i]);

    vector<int> p = query_one(new_a, new_k);
    p.push_back(a[first_digit]);
    return p;
}

ll query_two(int n, const vector<int>& p){
    ll k = 1;
    for(int i = 0; i < n; i++){
        ll place_value = fac[n-i-1];

        int num_smaller = 0;
        for(int j = 0; j < i; j++)
            if(p[j] < p[i])
                num_smaller++;

        int digit_in_place = p[i] - num_smaller - 1;

        k += place_value * digit_in_place;
    }
    return k;
}

int main(){
    init();

    int T;
    scanf("%d", &T);
    for(int t = 0, type, n; t < T; t++){
        scanf("%d %d", &type, &n);
        if(type == 1){
            ll k;
            scanf("%lld", &k);

            vector<int> a;
            for(int i = 1; i <= n; i++)
                a.push_back(i);

            vector<int> p = query_one(a, k-1);
            reverse(p.begin(), p.end());

            for(int i = 0; i < n; i++)
                printf("%d%c", p[i], (" \n")[i==n-1]);
        } else {
            vector<int> p(n);
            for(int i = 0; i < n; i++)
                scanf("%d", &p[i]);

            printf("%lld\n", query_two(n, p));
        }
    }
}