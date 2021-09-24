#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxN = 3005;

struct Line {
    ll m, b, c;
    ll operator()(ll x){
        return m * x + b;
    }
};

struct CHT {
    Line dq[2*maxN];
    int fptr, bptr;

    void clear(){
        dq[0] = {0, 0, 0};
        fptr = 0; bptr = 1;
    }

    bool pop_back(Line& L, Line& L1, Line& L2){
        ll v1 = (L.b - L2.b) * (L2.m - L1.m);
        ll v2 = (L2.m - L.m) * (L1.b - L2.b);
        return (v1 == v2 ? L.c > L1.c : v1 < v2);
    }

    bool pop_front(Line& L1, Line& L2, ll x){
        ll v1 = L1(x);
        ll v2 = L2(x);
        return (v1 == v2 ? L1.c < L2.c : v1 > v2);
    }

    void insert(Line L){
        while(bptr-fptr >= 2 && pop_back(L, dq[bptr-1], dq[bptr-2]))    bptr--;
        dq[bptr++] = L;
    }

    pll query(ll x){
        while(bptr-fptr >= 2 && pop_front(dq[fptr], dq[fptr+1], x))     fptr++;
        return {dq[fptr](x), dq[fptr].c};
    }
};

CHT cht;
int N, K, cnt[maxN];
ll pre[maxN], dp[maxN];

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 1; i <= N; i++){
        scanf("%lld", &pre[i]);
        pre[i] += pre[i-1];
        dp[i] = pre[i]*pre[i];
    }

    for(int k = 1; k <= K-1; k++){
        cht.clear();
        for(int i = 1; i <= k; i++)
            cht.insert({-2*pre[i], dp[i]+pre[i]*pre[i], cnt[i]});
        for(int i = k+1; i <= N; i++){
            pll P = cht.query(pre[i]);
            cht.insert({-2*pre[i], dp[i]+pre[i]*pre[i], cnt[i]});
            dp[i] = pre[i]*pre[i] + P.first;
            cnt[i] = P.second + 1;
        }
    }

    printf("%lld\n", dp[N]);
}