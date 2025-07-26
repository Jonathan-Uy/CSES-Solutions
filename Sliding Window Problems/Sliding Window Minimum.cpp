#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;

struct Window {
    deque<pii> dq;
    int l, r;

    Window(){
        l = r = 0;
    }

    void push_back(ll x){
        while(!dq.empty() && dq.back().first >= x)   dq.pop_back();
        dq.push_back({x, r});
        r++;
    }

    void pop_front(){
        if(dq.front().second == l)  dq.pop_front();
        l++;
    }

    ll get_min(){
        return dq.empty() ? -1 : dq.front().first;
    }
};

int N, K;
ll x, a, b, c;

int main(){
    scanf("%d %d", &N, &K);
    scanf("%lld %lld %lld %lld", &x, &a, &b, &c);

    Window window;
    for(int i = 0; i < K; i++){
        window.push_back(x);
        x = (a * x + b) % c;
    }

    ll xum = window.get_min();
    for(int i = K; i < N; i++){
        window.push_back(x);
        window.pop_front();
        xum ^= window.get_min();
        x = (a * x + b) % c;
    }

    printf("%lld\n", xum);
}