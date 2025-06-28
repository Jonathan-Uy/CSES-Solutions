#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll maxN = (ll) 1e12;

unordered_set<ll> S;
vector<ll> nums;

bool is_two_sum(ll n){
    int l = 0, r = (int) nums.size() - 1;
    while(l < (int) nums.size() && r >= 0){
        ll cur = nums[l] + nums[r];
        if(cur == n)        return true;
        else if(cur < n)    l++;
        else                r--;
    }
    return false;
}

int answer(ll n){
    if(S.find(n) != S.end())    return 1;
    else if(is_two_sum(n))      return 2;
    else                        return 3;
}

int main(){
    S.reserve((int) 1e6);
    for(ll i = 1, num = 1; num <= maxN; i++, num += i){
        nums.push_back(num);
        S.insert(num);
    }

    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; t++){
        ll n;
        scanf("%lld", &n);
        printf("%d\n", answer(n));
    }
}